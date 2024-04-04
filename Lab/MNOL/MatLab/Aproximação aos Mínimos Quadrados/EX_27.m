% Dados
t=[10 20 30]
cm=[1003 1010 1015]

% modelo linear nao polinomial c(t)= 0.6000*t + 997.3333
[c,RESNORM] = lsqcurvefit(@exerc_43,[1,1],t,cm)
RESNORM % dá a soma do quadrado do residuos - erro

cm1 = exerc_43(c,18) %estima o comprimento da barra para t=18o
disp(cm1);

%funcao
function [ m ] = exerc_43( c,t )
m=c(1).*t+c(2);
end

