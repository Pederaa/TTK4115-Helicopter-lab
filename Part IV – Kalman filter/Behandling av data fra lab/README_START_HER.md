# TTK4115 – Helicopter Lab Part IV (Kalman filter)

**Samlepakke, 7. november 2026**

Denne pakken samler materiale relatert til **Part IV / Lab 4**. Målefiler fra Part III er utelatt.

## Innhold

- `01_Oppgavetekster/`: helicopter lab assignment og lab preparation (2026).
- `02_Verifiserte_Data/`: siste verifiserte, rensede Part IV-arkiv, med **47 ulike opptak** (5 fra Task 4.1, 9 fra Task 4.2, 33 fra Task 4.3), siste MATLAB-/Simulink-modeller, tidligere modellversjoner, filmanifest og intern kontrollrapport.
- `03_Analyse/`: revidert notebook med renset arkiv som datakilde, samt eksisterende PNG-/PDF-figurer og CSV-beregninger fra tidligere fjerde kontrollrunde.
- `04_Kvalitetskontroll/`: **siste reviderte PDF**, datakontroll i Markdown og filklassifiseringen.
- `05_Historiske_Analysemerknader/`: logg fra tidligere analyse for sporbarhet.

## Slik bruker du notebooken

1. Pakk ut **hele samlepakken** med mappestrukturen intakt.
2. Åpne `03_Analyse/TTK4115_Lab4_Analyse_PartIV_Renset.ipynb` i Jupyter.
3. Installer ved behov `numpy`, `scipy`, `pandas`, `matplotlib` og `ipython`.
4. Kjør cellene fra toppen. Notebooken leser det verifiserte ZIP-arkivet direkte fra `../02_Verifiserte_Data/` og lagrer oppdaterte figurer i `03_Analyse/figures_lab4/`.

## Viktige forbehold

- Filintegritet og klassifisering er kontrollert, men enkelte kanalnavn fra Task 4.1 kan ikke dokumenteres ut fra MAT-filene alene.
- Tidligere genererte figurer og notebook-beregninger ble opprinnelig utviklet med et blandet originalarkiv. Ny notebook er tilpasset renset Part IV-arkiv; allerede eksporterte figurer er beholdt **for referanse**, ikke presentert som en ny samlet fullkjøring.
- Notebooken må ikke brukes som bevis for at de sist lagrede Simulink-innstillingene gjaldt for alle tidligere eksperimenter.
- Se `04_Kvalitetskontroll/TTK4115_Part4_Kvalitetskontroll_Revidert_2026-11-07.pdf` for dokumenterte feil, mangler og anbefalte tiltak.
- Denne pakken inneholder **ikke** det originale blandede `Del 4.zip` og har ingen Part III-målinger.
