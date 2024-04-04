%%b)
       clear all
       d=[0.239212 0.239215  0.239221];
       p=[0.00015 0.00020   0.00030];
       [c,RESNORM] = lsqcurvefit(@exerc_50,[1,1],d,p)
       % P(d)=10.9843*d^2 + 0.4393*ln(d);
       %%representacao grafica
       novo_d=0.239212:0.001:0.239221;
       novo_p=exerc_50(c,novo_d); %avalia os valores de novo_x no modelo
       plot(d,p,’o’,novo_d,novo_p,’r’)  %faz o grafico dos pontos e do modelo
       %funcao
       function P=exerc_50(c,d)
P=c(1).*d.^2 + c(2).*log(d);
         end

