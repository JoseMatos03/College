clear all
t=[0.11 0.52 0.79];
s=[-3.1127 0.0625 3.0351];
[c,RESNORM] = lsqcurvefit(@exerc_46,[1,1],t,s)
%%representacao grafica
novo_t=0.11:0.01:0.79;
novo_s=exerc_46(c,novo_t); %avalia os valores de novo_x no modelo
plot(t,s,'o',novo_t,novo_s,'r')  %faz o grafico dos pontos e do modelo
%funcao
function [ m ] = exerc_46( c,t )
m=0.2*c(1)*sin(20*pi*t)+0.2*c(2)*sin(22*pi*t);
end

