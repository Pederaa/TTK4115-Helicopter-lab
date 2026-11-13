# TTK4115 – Helicopter Lab 2 post-processing

## Folder structure

- `notebook/lab2_postprocessing.ipynb` — notebook for Lab 2 / Part II.
- `notebook/input/` — all 27 original `.mat` recordings (unchanged).
- `notebook/matlab_original/` — both supplied initialization scripts and the supplied IMU model.
- `plots/` — exported PNG figures, generated directly by the notebook.

Run the notebook with Python 3, `numpy`, `scipy`, `matplotlib`, and `jupyter` installed. Open the notebook and choose **Run All**. Figure files are saved into the existing `plots` directory.

## File audit

- The 27 MATLAB recordings form **9 complete triplets** (`encoder`, `reference`, `u`): six without integral action and three with integral action.
- All triplets contain matching timestamps and sample counts, at a 0.002 s sampling interval. Channel mappings were checked against the generated C code from the last compiled model.
- Main file `heli_q8lab2new.slx` is **missing** from the uploaded archive. The available `IMU_heli_3_10.slx` is a different model. `heli_q8lab2new.slxc` is a generated cache, and `heli_q8lab2new.rt-win64` is a compiled runtime artifact, neither is the editable main model.
- `slprj/` and `heli_q8lab2new_quarc_win64/` contain automatically generated Simulink/QUARC build and cache artifacts. They are not additional experimental recordings and are omitted from this clean plotting package.
- The generated C code confirms that Simulink opens the three `To File` outputs in **`wb` (overwrite)** mode. Repeating a run with the same file names overwrites its old data. This explains one plausible mechanism for disappearing recordings; which historical files were overwritten cannot be established.
- The latest generated C build (Nov 12, 17:02:57) corresponds to the `newintegralmaxF5050` recording and had `F = [5 0; 5 0]`. This does not establish the historical values of `F` in other runs.
- Your note was **`Task2intergralreferencebysonqdp5 = F=0`**. No file with this exact name is present, and there is no triplet `integral/qdp5` or `integral/qpd5`. The existing `integral/qp5` triplet has not been relabelled.
- The supplied non-integral MATLAB script has a likely index/copy mistake: `K(2,3)` is populated from `K(1,3)` rather than the second row's third entry of the LQR gain. This can introduce a spurious elevation-rate feedback into the pitch-control channel. The archived script timestamps are later than the data, so we cannot confirm the same script was used for every recorded experiment.
- Output voltages in `u` are **pre-saturation commands**. The last compiled model uses +/-5 V motor saturation, so extreme logged commands do not necessarily imply that those voltages were physically applied to the motors.

## Recorded channels

`encoder`: `[t, lambda, lambda_dot, pitch, pitch_dot, elevation, elevation_dot]`

`reference`: `[t, pitch_reference, elevation_rate_reference]`

`u`: `[t, Vs, Vd]`

## How to use the plots

Individual experiment figures contain two reference-vs-measured panels and one control-input panel. The two overview figures cover all nine runs. Joystick inputs differ between runs, so comparisons should account for the reference trajectory, not only the measured response.

The notebook does not modify or overwrite the original `.mat` files. It can be rerun to regenerate all plots.
