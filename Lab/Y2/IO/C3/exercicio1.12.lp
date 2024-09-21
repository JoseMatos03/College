/* Objective function */
min: tF;

/* Constraints */
tA >= 0;
tB >= 0;
tC >= tA + 3;
tD >= tA + 3;
tD >= tC + 6;
tD >= tB + 5;
tF >= tD + 4;
tF >= tC + 6;
