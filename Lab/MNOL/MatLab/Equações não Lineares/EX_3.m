fplot(@exerc3, [0,3]) % fazer o gráfico da função
% para obter a raiz da função
op=optimset('TolX', 1e-2);
[x, fval, exitflag, output]=fzero(@exerc3, [0.25 0.5], op);
%
function f = exerc3(x)
    f = ((pi*x^2*(3*1-x)/3))-0.5;
end