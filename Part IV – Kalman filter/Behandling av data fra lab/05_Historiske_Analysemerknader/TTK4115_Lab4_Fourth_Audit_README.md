# TTK4115 helicopter lab – Fourth independent audit

**Date:** 6 November 2026  
**Source:** Original `Del 4.zip`, 2026 lab preparation/assignment, newest archived `heli_q8.slx` and `init_heli_3_10.m`.  
**Deliverables:** Reproducible Jupyter notebook (42 cells), 34 PNG figures, 24 selected PDF figures, 10 CSV tables, file-to-figure manifest and original source ZIP.

## What was checked

- 64 `.mat` archive entries; 52 entries from Lab 4, representing **47 unique Lab 4 recording contents**. The other 12 are from earlier tasks and are not complete matched Lab 4 trials.
- All 52 Lab 4 archive entries map to exported plots (including the two distinct older versions sharing basenames). Verification is in `figures_lab4/00_file_coverage.csv`.
- 11 matched Task 4.3 trial triplets (`xhatvalues`, `yvalues`, `encodervalues`) and one matched Task 4.2 baseline triplet use 0.002 s timestamps.
- Main 6-channel state order is `[p, p_dot, e, e_dot, lambda, lambda_dot]` with angle `[rad]` and rate `[rad/s]` labels, verified against the Simulink y-transformer and encoder signal wiring. The fifth channel in the measurement vector is a **passthrough from the travel encoder**, not an independent IMU orientation measurement.
- Multiple archived Task 4.1 / Task 4.2 recordings do not have securely identified channel metadata and retain generic or explicitly inferred labels.
- The `qdinf` estimate first becomes nonfinite at **0.360 s**; no valid post-2 s RMSE is reported for it. Other large but finite estimation errors are not clipped during calculations.
- Whole-record in-flight sample covariance includes real motion; grounded raw IMU and flight state-like measurements are *not* interchangeable channel-by-channel. The grounded IMU initial zero samples must be excluded.
- Recorded new-data signals, instantaneous error covariance `P`, and complete per-trial parameter snapshots were **not found** in the MAT data. The data do not establish a single within-run disconnected-then-reconnected experiment.

## Additional figures in this audit

1. `41_autocorrelation`: autocorrelation of selected grounded IMU channels and in-flight derived channels, with the important caveat that the flight segment was not proven stationary.
2. `42_same_trial_residuals`: compare IMU-derived measurement error and Kalman estimate error against the same encoder recording for pitch, elevation and travel rate.
3. `43_within_trial_error_ratio`: normalized RMSE ratio for five comparable states across every experiment; excludes the encoder travel passthrough; labels undefined values explicitly.
4. `43_update_dropout_log_error`: absolute estimate-to-encoder errors on a log scale for two separate qdemin6 runs (with versus without measurement updates).

### Additional numerical outputs

- `41_grounded_raw_covariance.csv`: grounded raw IMU sample covariance after 1 s startup exclusion; **not** a directly comparable substitute for a six-state `R_d`.
- `42_within_trial_errors.csv`: baseline measurement-vs-encoder and estimate-vs-encoder RMSE on identical samples.
- `43_within_trial_comparison.csv`: same comparison for all 11 Task 4.3 runs.
- `42_model_parameter_audit.csv`: discrepancy between coded elevation gain and preparation equation.
- `42_saved_newdata_switch_audit.csv`: inspection of final archived Simulink switch configuration.

## Important technical findings

### Elevation model constant K2

The final archived initialization script contains:

`K2 = Kf*l_h / (m_c*l_c^2 + 2*m_p*l_h)`

but the preparation model specifies `J_e = m_c*l_c^2 + 2*m_p*l_h^2`, hence `K2 = Kf*l_h/J_e`. With the saved parameters, the implemented value is **0.0647891** and the preparation-consistent value **0.0850455** (23.8% smaller in the implementation). This is a **model-check finding**: no historical data were altered, and effects on particular experiments cannot be quantified from the saved recordings alone.

### Stored final new-data switch

The final archived `heli_q8.slx` shows root-level Switch SID 479, `Criteria = u2 > Threshold`. Its control input (SID 481) and fallback input (SID 480) are both Constant 0. With the standard zero threshold, the correction input to the Kalman filter is always zero. This is consistent with a final `nonewdata` setup, **not** evidence that earlier `newdata` recordings were generated with that configuration. Verify the switch and parameters on the physical lab machine before presenting or flying.

### Qd = 0, P0 = 0

The stored initialization has `P_hat0 = zeros(6)`. In ideal arithmetic, with `Qd = 0` as well, the prediction covariance remains zero, the Kalman gain is zero, and no measurement correction takes place. This explains qualitatively why an extreme zero-covariance configuration can produce very poor estimates.

### Kalman performance not always improved

The main `task42_newdata` baseline has smaller estimator-to-encoder RMSE than raw IMU-derived measurement-to-encoder RMSE for all five independent channels, but this does **not** hold for every `Qd` trial. In `task43_newdata_qdemin6`, for example, pitch rate, elevation rate and travel rate estimates are farther from encoders by RMSE. These are comparisons *within* each trial and do not establish causal ranking across different helicopter trajectories.

## Remaining experimental limitations (do not invent results)

1. A credible noise-only flight `R_d` requires stationary trial segmentation with movement/noise separation. The full-record covariance replicates the archived `cov` approach but includes physical motion; the 10–15 s comparison is **illustrative**, not a validated stationary interval. Grounded raw and flight transformed variables are different sensor representations.
2. No logged `P[k]` or `new_data[k]` means covariance trends and exact correction times cannot be reconstructed uniquely. For the oral evaluation, show a **separately labelled theory/simulation illustration** of `P` behavior if no real recording exists, rather than falsely presenting it as measured.
3. The saved experiments compare separate `newdata` and `nonewdata` flights. A **single continuous run** turning corrections off and on would strengthen the Task 3 discussion, if there is an opportunity to repeat it.
4. Saved Lab 3 Luenberger data are not a matched joint experiment, so a quantitative Kalman-vs-Luenberger accuracy claim would be misleading. A theoretical and qualitative comparison is appropriate.
5. `Qd` labels are inferred from filenames, not measured metadata. The newest script contains `Qd = diag(1E34,...)` subsequently scaled by `1E-1`, yielding a saved final value of `1E33` on its diagonal. Do not equate the filename `qde34` with an independently verified parameter snapshot.
6. Angular encoder readings are comparison references, not noiseless truth. The fifth state, travel angle, is specifically excluded from the new normalized ratio analysis since the measurement value is copied from the encoder.

## Recommended figures for the report

- Task 4.1: `41_grounded_raw`, `41_flight_recording`, `41_stationarity_sensitivity` and `41_autocorrelation` (select, do not overload the report).
- Task 4.2: `42_baseline_threeway`, `42_same_trial_residuals`.
- Task 4.3: `43_within_trial_error_ratio`, `43_update_dropout_log_error`, `43_rmse_overview`, `43_qdinf_first_nonfinite`, plus one or two appropriate six-state trial figures.
- Evaluation: `45_presentation_summary` plus the actual Simulink scopes and configurations.

## Reproduction

1. Extract the complete package, preserving `Del 4.zip` alongside `TTK4115_Lab4_Results_Fourth_Audit.ipynb`.
2. Install `numpy`, `scipy`, `pandas`, `matplotlib`, `jupyter`, `ipykernel`.
3. Launch Jupyter, select Python 3 and **Restart & Run All**; outputs are written to `figures_lab4/`. Configure time range and all-plot export at the beginning.
4. The notebook's calculation/plotting code was validated against the original archive in **segmented execution**, and every expected plot plus the file-to-figure audit completed successfully. A single full Jupyter-kernel run with all inline graphical outputs was **not** successfully completed in this constrained environment. Therefore a pre-executed notebook is not presented as newly validated. The source notebook and pre-generated results are provided.

**Original experimental data and files are unchanged.**
