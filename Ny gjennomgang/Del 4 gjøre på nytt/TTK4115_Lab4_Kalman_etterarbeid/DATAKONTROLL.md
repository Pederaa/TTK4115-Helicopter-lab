# Datakontroll – TTK4115 helicopter lab, del IV

Kontrollert mot vedlagt *Helicopter lab assignment* (versjon 5.7, særlig del 2.4, side 18–19), *Helicopter lab preparation* (del 2.4, side 11–12), `heli_q8lab4.slx` og `init_heli_3_10.m`.

## 1. Hva som er tilgjengelig

Det foreligger fem komplette sett med fire MAT-filer per eksperiment (`feedback_xhat`, `feedback_yvalues`, `feedback_encodervalues`, `reference`), i tillegg til ett opptak for Task 1. Alle er lagret i MAT-format med variabelen `ans`. Første rad er tid. For Task 4.4 inneholder de tre feedback-filene seks signaler hver; referansen inneholder to. Alle fem forsøk har fullstendig tidsjustering mellom de fire filene, med konstant tidssteg på 0,002 s. Ingen NaN-/Inf-verdier ble funnet.

| Filparameter `qis…` | Tolkning av filnavn | Antall prøver | Varighet |
|---|---:|---:|---:|
| `p00001` | 0,00001 | 39 801 | 79,600 s |
| `p0001` | 0,0001 | 21 219 | 42,436 s |
| `p01` | 0,1 | 23 349 | 46,696 s |
| `1` | 1 | 22 820 | 45,638 s |
| `20` | 20 | 44 503 | 89,004 s |

**Forbehold:** Parameterverdiene er tolket fra filnavnene. De arkiverte MATLAB-filene dokumenterer ikke den faktiske verdien av `Qd` for hver enkelt kjøring. Siste versjon av `init_heli_3_10.m` har `Qd = 1e-5 * eye(6)`.

## 2. Signalrekkefølge er forskjellig

Lagringsblokkene og forbindelsene i `heli_q8lab4.slx` viser følgende rekkefølge *etter tidsraden*:

- `feedback_xhat` og `feedback_yvalues`: `[p, p_dot, e, e_dot, lambda, lambda_dot]`.
- `feedback_encodervalues`: `[lambda, lambda_dot, p, p_dot, e, e_dot]`.
- `reference`: `[p_c, e_dot_c]`.

Notebooken omorganiserer encoderkanalene før sammenligning. Uten dette ville plottene og RMS-målene vært feil.

## 3. Systematisk feil i lagret elevation fra encoder

I Simulink-modellen blir konstanten `0.60` **trukket fra i `Heli 3D`** på elevation-encoderens utgang, og konstanten `0.6` **trukket fra igjen i hovedmodellen** før signalet sendes til `feedback_encodervalues`. Dette gjør det lagrede encoder-elevation-signalet 0,6 rad lavere enn signalet som kommer fra `Heli 3D`.

- Før kompensasjon ligger gjennomsnittlig differanse `y_e - encoder_e` rundt **0,76–0,83 rad** for de fem forsøkene.
- Etter at loggingens ekstra `-0,6 rad` kompenseres, er gjennomsnittlig differanse fortsatt omtrent **0,16–0,23 rad**. Denne residualen kan blant annet være IMU-bias, kalibrering eller reelle måleavvik; den er **ikke** fjernet.
- Notebooken legger til `+0,60 rad` *kun* på den lagrede elevation-encoderen for sammenligningsplottene. De opprinnelige filene er urørt. Dette er en korreksjon av dokumentert ekstra logging-offset, ikke en generell IMU-kalibrering.

## 4. Travel-målingen i `y` er ikke uavhengig av encoder

I Simulink er reisevinkelen (`lambda`) koblet fra encoder-utgangen til `y-transformer`-systemet. I alle fem opptak er `y_lambda` og den lagrede encoder-travel-kanalen **identiske, prøve for prøve**. Det gir mening for signalrouting, men disse kurvene kan ikke brukes som uavhengig validering av IMU-estimert travel-vinkel. Notebooken viser alle tre signaler der det er relevant, men utelater `lambda` fra oppsummerende målesammenligninger.

## 5. Task 1 – støyestimat og kovarians

Bare filen `task41_xhat_noie_fligh.mat` følger med. Den inneholder 9 921 prøver / 19,840 s med seks kanaler. Det finnes ikke noe tilsvarende opptak av helikopteret **i ro på bakken**. Derfor kan ikke sammenligningen `R_d,ground` mot `R_d,flight` i oppgavearket gjennomføres.

Init-filen beregner `Rd = cov(X_meas')` fra **hele** det tilgjengelige flyopptaket. Den resulterende diagonalen er omtrent:

`[0.001745, 0.000682, 0.018749, 0.004092, 0.010143, 0.001816]`

Dette er variansene til de registrerte kanalene, ikke nødvendigvis et rent anslag på instrumentstøy. Betydelige endringer i flyopptaket gjør den totale kovariansen følsom for hvilket intervall som velges. For eksempel varierer travel-variansen mellom omtrent **0,01135** i første halvdel og **0,000060** i siste halvdel (en faktor rundt 190). Også travel-rate-variansen faller kraftig. Opptaket kan dermed ikke uten videre regnes som stasjonær måling ved et fast arbeidspunkt.

Filnavnet inneholder `xhat`, mens init-koden kaller de innleste kanalene `X_meas`. Det kan ikke sikkert avgjøres fra selve MAT-filen om det lagrede signalet var et råmålesignal eller et estimat. Dette bør avklares mot eventuell original Simulink-konfigurasjon for selve Task 1-opptaket.

## 6. Korte, store utslag i rate-målingene

Disse er reelle verdier i de leverte dataene, ikke feil ved import/plotting:

- For `qis20`, omkring **46,150–46,152 s**, har sensorutgangen `y` blant annet ca. **−29,75 rad/s** i pitch rate og **−29,49 rad/s** i travel rate. Andre utslag forekommer rundt **46,300 s**.
- For `qisp0001`, ved **16,308 s**, finnes utslag på omtrent **−18,50 rad/s** i pitch rate og **−18,61 rad/s** i travel rate.

Mulige årsaker kan være IMU-/transformasjonsartefakter, tidsmessig signalforstyrrelse eller reelle kortvarige bevegelser. Rådata alene er ikke tilstrekkelig til å fastslå årsaken. Disse punktene er **ikke fjernet**, og et eget detaljplott viser et av tilfellene.

## 7. Manglende opptak av viktig informasjon

Laboppgaven ber om å undersøke effekten av å koble `new_data` av og på og observere estimatet `x_hat` samt kovariansen `P_hat`. De leverte MAT-filene har `xhat`, `y`, encoders og referanser, men **ingen eksport av `new_data` eller `P_hat`**. Simulink-modellen har disse signalene internt, men man kan ikke rekonstruere en faktisk tidsserie for `P_hat` eller et logget tidspunkt for kobling fra/til.

Det foreligger heller ingen separate rapportfiler som dokumenterer en kontrollert sammenligning av identisk referanseforløp for de fem parameterverdiene. Varighetene og referanseforløpene varierer. Eventuelle RMS-forskjeller må tolkes forsiktig, ikke som en isolert effekt av `Qd`.

## 8. MATLAB-initialisering: integrator-leddene i regulatoren

Etter `lqr(A,B,Q,R,0)` blir tilbakekoblingsmatrisen manuelt overskrevet med **nuller i kolonne 4 og 5**:

```matlab
K = [K(1, 1) K(1, 2) K(1, 3) 0 0;
     K(2, 1) K(2, 2) K(2, 3) 0 0];
```

Dermed benyttes ikke de to integrator-tilstandene i tilbakemeldingen med den aktuelle init-filen. Dette kan være et bevisst valg, men bør ikke beskrives i rapporten som aktiv integrator-tilbakekobling uten kontroll.

## 9. Resultat og anbefalt bruk i rapporten

Dataene er teknisk komplette og tidsmessig konsistente for de fem kjøringene. De kan brukes til å beskrive hvordan Kalman-estimatene følger målesignalene, og til å diskutere kompromisset mellom støyfiltrering og respons for ulike navngitte tuningforsøk. Plottene skal ikke brukes til å hevde at ground-versus-flight-støy er kartlagt eller at `P_hat`-utviklingen ved utkoblet IMU ble observert. Ved tolkning av elevation må en være tydelig på hvilken logging-offset som er korrigert, og at en residual sensorbias fremdeles er til stede.
