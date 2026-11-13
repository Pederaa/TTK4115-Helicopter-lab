# TTK4115 — Lab 3 post-processing

## Contents

- `Notebook/Lab_3_Postprocessing.ipynb`: reproducible post-processing, figures and data checks.
- `Notebook/Input/`: original 24 `.mat` recordings, the supplied `.m` initialization file and `.slx` Simulink diagram, unchanged.
- `Plots/`: pre-generated PDF (vector) and PNG figures.
- `requirements.txt`: minimal Python dependencies.

## How to use

Open `Notebook/Lab_3_Postprocessing.ipynb` in VS Code or Jupyter and run **Run All**. Make sure the working directory is `Notebook` or the root `Lab_3_Postprocessing`. The plotting code uses local relative paths; no need to change filenames or add an absolute path. Run `pip install -r requirements.txt` from the root if required.

Use PNG figures for previews and PDF figures for LaTeX reports. Every figure has units, a time axis and explanatory legend.

## Data mapping

Time is the first row of each `ans` MATLAB array, followed by signal rows:

- Encoder (6): travel, travel rate, pitch, pitch rate, elevation, elevation rate.
- Task 2 transformed vector (5): pitch, pitch rate, elevation, elevation rate, travel rate.
- Observer `xhat` and `y` (5): pitch, pitch rate, elevation, elevation rate, travel rate.
- Gyroscope (3): pitch, elevation, travel body angular rates (after the model's axis reorder).
- Accelerometer (3): IMU x, y, z values [m/s^2], after the model's axis reorder.

Mapping was checked against the supplied `heli_q8lab3.slx` wiring, not guessed solely from filenames.

## File inspection and anomalies

**1. Task 3.4 measurement vector: critical.** All five channels of **all six** `task34_y*.mat` recordings are *exactly zero for every sample*. This is inconsistent with the recorded encoder motion and means these files do not provide a usable IMU measurement vector for verification of the Luenberger observer. No correction or fabricated data has been inserted. The observer comparison plots are marked accordingly.

**2. Task 3.4 observer estimates: critical.** Channels 1, 3 and 5 of every `task34_xhat*.mat` file (pitch, elevation, travel rate) are exactly zero. The estimated elevation rate does vary, but is in some cases far from the encoder, especially suffix `1` (maximum estimated elevation rate about 23.76 rad/s, while encoder elevation rate stays below 0.60 rad/s). This is consistent with a nonfunctional measurement signal and/or unreliable observer experiment, but the precise cause cannot be established from the saved data alone.

**3. Task 3.2 IMU angle discrepancies: relevant.** The transformed elevation angle has a substantial negative mean offset relative to the encoder (approximately -0.49 rad for t > 5 s); under low encoder rates it is also around -0.47 rad. The measured pitch angle is restricted to approximately ±1.57 rad by the angle extraction formula while the encoder spans a wider range. Interpret these discrepancies before using angles as direct feedback. Pitch-rate transformation tracks the encoder well (correlation about 0.992 for t > 5 s).

**4. Lab configuration versus `Newintegral=0.2`: verify.** The supplied initialization file includes `gamma_max = 0.2` and `zeta_max = 0.2`, but the assembled feedback matrix `K` has its last two columns set to zero. Thus in this file integral states are not fed back through the LQR gain. The free-text note `Newintegral=0.2` is retained without assigning it to any particular recording because the filenames cannot establish which settings were active during the logged runs. The supplied model also only identifies one observer pole vector in code, `[-25,-25,-25,-25,-25]`. Other suffixes are not guaranteed to represent complete pole vectors.

**5. Files and timing: OK.** All 24 MAT files can be read with SciPy. All time axes are strictly increasing with 0.002 s steps, and there are no NaN/Inf samples. Within each Task 3.4 group, `enkoder`, `xhat` and `y` have identical timestamps and lengths. Task 3.1 has about 87.7 s of data; Task 3.2 about 79.9 s; Task 3.4 runs vary from 8.66 to 45.07 s. Short initial all-zero segments occur in some logs, consistent with startup/no-signal periods but not proof of their origin.

## Plot inventory

- `3.1_gyro_vs_encoder`: raw IMU gyro versus encoder rates (3 axes)
- `3.1_accelerometer`: accelerometer components (3 axes)
- `3.2_acc_angles_vs_encoder`: accelerometer-derived pitch and elevation versus encoders
- `3.2_transformed_rates_vs_encoder`: raw/transformed gyroscope versus encoder rates
- `3.4_00_all_zero_imu_measurements`: example evidence that logged observer measurement vector is zero
- `3.4_01_...` through `3.4_06_...`: estimates versus encoders for six recording suffixes

Every plot is present as both `.png` and `.pdf`.

## Scope

This notebook plots the data as supplied. It does not reconstruct missing IMU measurements, estimate biases, re-run the observer or make assumptions about controller pole settings that are absent from the files. Lab assignment section 2.3 (Luenberger observer) determined the necessary comparisons.
