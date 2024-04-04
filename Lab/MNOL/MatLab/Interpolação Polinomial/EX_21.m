x = [-1 0 1 2];
f = [2 1 0 4];

p = polyfit(x, f, 3);
f1 = polyval(p, -2);
disp(f1);