x = [-2 1 2];
y = [-8 1 8];

s = spline(x, [12 y 20]);
disp(ppval(s, -1));