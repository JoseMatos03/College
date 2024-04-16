x = [0 1 1.5 2];
f = [0 0.3125 0.6328125 1];

p = polyfit(x,f,3);
x1 = 4;
f1 = polyval(p,x1);

disp(f1);