%resolver com opcao de tolx
op=optimset('TolX',1e-2);
[x,fval,exitflag,output]=fzero(@exerc2,[0.8 1],op);
%funcao
function a = exerc2(x)
a = 10.1*x^4-5.12*x^3+9.18*x^2-5.84*x-5.66;
end