% para obter a raiz da função
op=optimset('TolX', 0.05);
[x, fval, exitflag, output]=fzero(@exerc4, 5, op);
% função
function f = exerc4(x)
    f = 70*exp(-1.5*x)+25*exp(-0.075*x)-9;
end