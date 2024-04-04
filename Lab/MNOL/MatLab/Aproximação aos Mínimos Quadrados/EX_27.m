clear all
    t=[10 20 30]
    cm=[1003 1010 1015]
    % modelo linear nao polinomial
    [c,RESNORM] = lsqcurvefit(@exerc_43,[1,1],t,cm)
    RESNORM % dá a soma do quadrado do residuos - erro
    % c(t)= 0.6000*t + 997.3333
    exerc_43(c,18) %estima o comprimento da barra para t=18o
    %%representacao grafica m
    novo_x=10:0.05:30;
    novo_m=exerc_43(c,novo_x);
    plot(t,cm,’o’,novo_x,novo_m,’k’)
    %funcao
    function [ m ] = exerc_43( c,t )
        m=c(1).*t+c(2);
    end

