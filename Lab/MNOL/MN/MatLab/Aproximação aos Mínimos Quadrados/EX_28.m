clear all
x=[0 1.25 2.5 3.75 5 6.25]
f=[0.260 0.208 0.172 0.145 0.126 0.113]
[P2,S2] = polyfit(x,f,2)%P2-coeficientes do polinomio
%P2 = 0.0030*x^2 -0.0418*x + 0.2583
S2.normr^2 %calula a soma do quadrado dos residuos (erro)-1.6693e-05
%calcular P2(3) - consumo para distancia=3?
polyval(P2,3)
%%representacao do polinomio
novo_x=0:0.01:6.25;
novo_f=polyval(P2,novo_x); %avalia o novo_x em p2
plot(x,f,'o',novo_x,novo_f,'r')

