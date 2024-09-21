fun = @(x)max((x(1)-1)^2 , x(1)^2+4*(x(2)-1)^2);
[x, fval, exitflag, output] = fminsearch(fun, [1;1]);