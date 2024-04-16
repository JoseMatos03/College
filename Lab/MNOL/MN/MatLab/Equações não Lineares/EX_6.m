% para obter a raiz da função
op=optimset('TolX', 1e-2);
[x, fval, exitflag, output]=fzero(@exerc6, [20 30], op);
% função
function f = exerc6(x)
f = 2200*log(1.6e+5/(1.6e+5-2680*x))-9.8*x-1000;
end