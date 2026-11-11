# TTK4115 — Part IV: independent audit of cleaned data
**Date:** 7 November 2026  
**Sources:** `Del 4.zip`, `TTK4115_Part4_Renset_Data.zip`, helicopter lab assignment and preparation (v5.7, 2026).

## Verified data integrity
- Original ZIP: 64 MAT entries; 54 distinct MAT contents. Ten extra entries are byte-identical duplicates.
- Distinct contents: 47 labelled Part IV (5 Task 4.1, 9 Task 4.2, 33 Task 4.3), seven prior-task files excluded. This grouping is **by filename** and task compatibility, not independently verified lab-session metadata.
- SHA256 and bytes checked: all 47 included MAT files are unchanged from original.
- The 33 Task 4.3 MAT files are **11 trials**, not 33 independent experiments. Each trial has xhat, measurement and encoder recordings, with matching 0.002 s sample timestamps. Task 4.2 additionally has one matching three-file set.
- Only one MAT file contains nonfinite values: `task43_newdata_qdinf_xhatvalues.mat`. All six estimates become nonfinite beginning at 0.360 s; the corresponding measurements and encoder values remain finite. There is no `nonewdata_qdinf` trial.

## Confirmed issues or limitations
**High — Task 4.1: measurement covariance.** The archived initialisation calculates `Rd = cov(X_meas')` over the entire `task41_xhat_noie_fligh.mat` recording. The signals vary with helicopter movement; the resulting covariance is not necessarily stationary IMU measurement noise. The grounded `task41_xhat_noie_grounded.mat` appears to contain six raw accelerometer/gyroscope channels, whereas the flight record is six transformed state-like signals. Their covariance entries cannot be compared like-for-like. The separate 10-channel `task41_noice_grounded.mat` has four identically-zero channels and many zeros in other channels, so its signal identities and useful time intervals need independent confirmation. Select defensible stationary windows if possible and disclose residual motion and sensor-coordinate differences.

**High — K2 discrepancy.** Latest `init_heli_3_10.m` computes `K2=Kf*l_h/(m_c*l_c^2+2*m_p*l_h)` instead of preparation-consistent `Kf*l_h/(m_c*l_c^2+2*m_p*l_h^2)` (the saved value is approximately 23.8% lower). This proves a discrepancy in the *saved file*, not necessarily the configuration of every recorded run. Do not silently change the historical data or attribute specific estimation errors to it without additional evidence.

**High for oral demonstration — stored model state.** The latest `heli_q8.slx` routes zero to the filter's `new_data` input through a switch whose two data/control constants are both zero. The latest init sets very large Qd (1e33 diagonal), a last-run test configuration. Restore and test a functioning measurement-update path and reasonable tuning before flying or demonstrating. Preserve the historical versions separately.

**Medium — missing logged variables.** No per-trial P[k], Kalman gains, new-data bit-stream or complete model/tuning snapshot is present in the MAT recordings. Therefore precise on/off events and empirical covariance development cannot be reconstructed uniquely. Separate `newdata` and `nonewdata` recordings do not prove an in-run disconnect-then-reconnect experiment.

**Medium — uncertain Qd labels.** `qdinf`, `qde34`, etc. are names rather than parameter metadata. The latest saved init has Qd=1e33 on its diagonal (1e34 multiplied by 0.1). Do not describe `qdinf` as literal floating-point infinity or assert numeric values for each trial without lab logs.

**Medium — channel independence.** In 12 matched trial sets, the fifth measurement channel (travel angle) equals the travel encoder exactly; it is passed through, not an independent IMU-based orientation estimate. Exclude it from measurement-to-encoder error improvement claims. Encoder readings are comparison references, not noiseless ground truth.

**Medium — reproducibility.** The earlier notebook searches only for `Del 4.zip`/`Lab4_data.zip`, not the cleaned ZIP. The latest init uses `load('task41_xhat_noie_fligh.mat')` without a path; this will fail if launched from the root of the cleaned archive. A new analysis notebook should resolve paths in `Data/Task_4_*` explicitly and distinguish older versions.

**Missing context in cleaned v1.** The cleaned ZIP originally included only the last saved model and init. The original also has an older, nonidentical `heli_q8.slx` with an output named `task42_qvtuningqv10emin6.mat` and older init scripts. The *verified* ZIP supplied alongside this report includes these as model history to aid traceability. Hardware caches and irrelevant backup artifacts were not copied. The original ZIP remains the ultimate source.

## Improvements without new lab data
1. Write the new notebook against the verified cleaned ZIP, with a manifest of which original MAT maps to which plot. Label uncertain channels generically, and keep old model versions as historical context.
2. For Task 4.1, show both raw ground and in-flight transformed time series, assess stationarity / repeated IMU samples, and report `Rd` as a *sample covariance including real motion* unless a validated stationary window and matched signal representation can be justified. Do not substitute grounded raw covariance into the state-measurement filter unmodified.
3. For Tasks 4.2–4.3, plot measurement, estimate and encoder in the same axes for each state. Report within-run RMSE for the five independent measurement channels (excluding travel-angle encoder passthrough), and show the fraction of valid samples. Compare separate runs qualitatively; different flight trajectories confound strict between-Qd ranking.
4. Distinguish theoretical filter covariance P[k] from empirical estimation error; do not label reconstructed curves as measured. Discuss P growth during missing measurement updates using the Riccati prediction equation.
5. Keep the Kalman-vs-Luenberger comparison theoretical or qualitative unless truly comparable Part III measurements are available and analysed consistently.

## Priority if lab access is possible
No full repeat appears necessary for basic reporting. Best extra experiment: in **one** run, log time, xhat, y, encoder, `new_data` and P (or diag(P)); disable then re-enable measurement updates and save the event times. A separate short stationary *matched-channel* ground-versus-flight recording would strengthen Task 4.1. Both are beneficial but their absence can be documented honestly. If no access is possible, prioritize sound analysis and explicit limits rather than claiming experiments not recorded.

## Notes on model files
`Model_reference/` retains the last archived model and init. `Model_history/Older_version/` in the verified ZIP holds the earlier nonidentical model and init; `Model_history/Latest_autosave/` contains the latest init `.asv` for provenance. Model versions are not guaranteed snapshots of the exact settings for all historical recordings.
