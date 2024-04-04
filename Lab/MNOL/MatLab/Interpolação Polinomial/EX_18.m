x = [1 3 4 6 7 10];
f = [2 3 4 5 6 10];

[p, S] = polyfit(x, f, 3);

y1 = polyval(p, 2);
y2 = polyval(p, 8);

disp(y1);
disp(y2);
disp(S.normr^2);