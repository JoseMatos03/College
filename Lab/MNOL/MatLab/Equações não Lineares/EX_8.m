% ver gráfico da função
fplot(@exerc8, [0,10])
grid

% resolver sem opções
[x, fval, exitflag, output]=fzero(@exerc8,6);

% resolver com opção de ver por iteração
op1=optimset('Display','iter');
[x1, fval1, exitflag1, output1]=fzero(@exerc8, 6, op1);

% resolver com opção de tolx
op2=optimset('tolx',1e-3);
[x2, fval2, exitflag2, output2]=fzero(@exerc8,6,op2);

% função
function f = exerc8(x)
    f = 7*(2-0.9^(x))-10;
end