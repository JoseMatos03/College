x = [0 1 4 7 8 10 14];
f = [2.1 2.0 1.8 1.5 1.4 1.1 0];

p = polyfit(x, f, 3);
f1 = polyval(p, 5);
disp(f1);

[c,resnorm] = lsqcurvefit(@fun,[1,1],x,f);
f2 = fun(c,5);
disp(f2);

function [ m ] = fun( c,x )
m = c(1) - c(2)*x;
end