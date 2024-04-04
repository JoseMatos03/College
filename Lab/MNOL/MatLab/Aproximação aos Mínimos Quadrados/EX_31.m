clear all
x=[1 3 6 10 12]
f=[122 188 270 160 120]
[c,RESNORM] = lsqcurvefit(@exerc_47,[1,1],x,f)
%c1 = 24.7203  c2 = 148.3147
%m = 24.7203*x + 148.3147*sen(x)
%RESNORM - soma do quadrado dos residuos (erro) =4.5461e+04
exerc_47(c,8)  %estima a radiacao no mes de agosto
%representacao grafica
novo_x=1:0.05:12;
novo_f=exerc_47(c,novo_x); %avalia os valores de novo_x no modelo
plot(x,f,'o',novo_x,novo_f,'r')  %faz o grafico dos pontos e do modelo
%funcao
function [ m ] = exerc_47( c,x )
m=c(1).*x+c(2).*sin(x);
end
