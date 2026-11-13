# TTK4115 – Etterarbeid, lab 4 (Kalman-filter)

## Mapper

- **`Notebook_og_input/Lab4_Kalman_etterarbeid.ipynb`** – Jupyter-notebook organisert etter del IV i oppgavearket.
- **`Notebook_og_input/input/`** – samtlige 21 originale MAT-målefiler, uendret.
- **`Notebook_og_input/MATLAB/`** – original Simulink-modell, IMU-modell og initialiseringsfil til dokumentasjon og eventuell videre analyse. Genererte MATLAB/QuaRC-byggartefakter (`.slxc`, `.rt-win64`) er utelatt fordi de ikke trengs til plott.
- **`Plots/PNG/`** – ferdig eksporterte rasterplott for rask visning.
- **`Plots/PDF/`** – tilsvarende vektorplott for LaTeX-rapport.
- **`DATAKONTROLL.md`** – gjennomgang av datakvalitet, observerte avvik og manglende målinger.

## Kjøring

1. Pakk ut hele ZIP-filen uten å endre mappestrukturen.
2. Åpne `Notebook_og_input/Lab4_Kalman_etterarbeid.ipynb` i JupyterLab eller VS Code.
3. Installer ved behov `numpy`, `scipy` og `matplotlib` i Python-miljøet.
4. Kjør **Run All**. Notebooken bruker lokale MAT-filer og oppdaterer `Plots/PNG` og `Plots/PDF`.

Notebooken bruker ingen eksterne data og ingen nettverkskall.

## Viktige forbehold

- Kun **flight noise** er levert for Task 1; bakkenoise mangler.
- Ingen tidsserier for `P_hat` og `new_data` er levert.
- Elevation-encoder i lagringsfilene har fått en ekstra `−0,6 rad` offset. Denne kompenseres eksplisitt **i plottene**, ikke i rådataene.
- De fem parameterverdiene for `Qd` er utledet fra filnavn og ikke bekreftet av egne MATLAB-workspace snapshots.
- Enkelte rate-målinger har korte, store utslag. Disse er beholdt.

Se `DATAKONTROLL.md` for detaljer før figurene brukes i en rapport.
