clear all
    t=[2 4 8 10];
    H=[1.6 1.4 0.2 0.8];
    % modelo linear nao polinomial
    [c,RESNORM] = lsqcurvefit(@exerc_45,[1,1,1],t,H)
    RESNORM % dá a soma do quadrado do residuos - erro
    %%representacao grafica m
    novo_t=2:0.05:10;
    novo_m=exerc_45(c,novo_t);
    plot(t,H,’o’,novo_t,novo_m,’k’)
    %funcao
    function [m] = exerc_45(c,t)
        m=c(1)+c(2)*sin((2*pi.*t)/12)+c(3)*cos((2*pi.*t)/12);
    end
