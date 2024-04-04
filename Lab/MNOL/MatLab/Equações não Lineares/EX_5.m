op=optimset('TolX', 0.5);
[x, fval, exitflag, output]=fzero(@exerc5, [0 2], op);
% função
function f = exerc5(x)
f = sqrt(0.5*0.088)*cosh(exp(0.5*x))-exp(-0.5*x);
end