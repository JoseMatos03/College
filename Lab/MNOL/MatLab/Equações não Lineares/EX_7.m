% ver gráfico da função
fplot(@exerc7, [100,150])
grid
% calcular a função
op=optimset('TolX', 1e-4);
[x, fval, exitflag, output]=fzero(@exerc7, 140, op);
% função
function f = exerc7(x)
    f = x*(x-40)^2-918.35*1700/1.025;
end