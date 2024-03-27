%resolver com opcao de tolx
op=optimset('TolX',1e-3);
[x,fval,exitflag,output] = fzero(@exerc_1, 10,op);
%funcao do exerc_1
function f = exerc_1(x)
    f=x^3-30*x^2+2552;
end