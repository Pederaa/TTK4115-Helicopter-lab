# TTK4115 - Helicopter Lab 3 (Part III) only

This delivery contains **only Lab 3** material for IMU characteristics, transformations, and the Luenberger observer.

## How to use

Open `Lab3_Plotting.ipynb` in VS Code or JupyterLab from this folder and run all cells. Required Python packages: `numpy`, `pandas`, `matplotlib`, `scipy`, `ipython`, `nbconvert`, plus a Jupyter kernel. Figures are written to `figures/` (PNG and SVG); plots are also embedded in the executed notebook.

## Included

- `data/Hovedopptak_Del3/`: 6 experimental MAT files from `Del 3(1).zip` (the Task 3 `task34_y`, `task34_xhat` and `task34_u` files are synchronized).
- `data/Tillegg_Lab3_fra_annet_arkiv/`: 4 additional distinct MAT recordings **with Lab 3 `task34_*` filenames** recovered from `Del 4(1).zip`. These recordings are **not** synchronized. Their association with particular observer configurations has not been established.
- `reference/`: selected Lab 3 initialization, helicopter, and IMU Simulink model files **exclusively from the original Del 3 archive**.
- `Lab3_filoversikt.csv`: a 10-record Lab 3-only manifest with original source paths and hashes.
- `figures/`: 23 Lab 3-focused figures, each exported in PNG and SVG; CSV summaries.
- `Lab3_Gjenstaende_Feilsjekk.pdf`: concise Lab 3-only overview of remaining gaps and implementation checks.

**Excluded:** All `task41_*`, `task42_*`, and `task43_*` recordings, Kalman-filter models/experiments, and their figures. The second archive was only used to recover potentially relevant `task34_*` files.

## Cautions

`y` consists of IMU-derived measurements; `y - xhat` is not the true estimation error. Tasks 1-2 lack a confirmed synchronized raw IMU and encoder run. Additional `task34_*` logs from the second archive cannot be combined sample-by-sample with the main recording.

## Utestående forhold

Se `Lab3_Gjenstaende_Feilsjekk.pdf` for bare gjenværende modellkontroller og datamangler. Del 4-måledata er ikke inkludert. De fire usynkroniserte `task34_*`-filene er kun tilleggsopptak med usikker forsøkskontekst.
