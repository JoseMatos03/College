% Dados do problema
x = [1.5 2.0 3.0 4.0];
f = [4.9 3.3 2.0 1.5];

%a) reta p1(x) =  -1.2915*x + 6.3153
[P1,S1] = polyfit(x,f,1);
disp(P1);
disp(S1.normr^2); % dá a soma do quadrado do residuos - erro

%b) parabola p2(x) = 0.6482*x^2 -4.8678*x + 10.6387
[P2,S2] = polyfit(x,f,2);
S2.normr^2; % dá a soma do quadrado do residuos - erro

%c) modelo nao polinomial m(x)= 7.4054/x -0.1175*x
[c,RESNORM] = lsqcurvefit(@exerc_42,[1,1],x,f);
RESNORM; % dá a soma do quadrado do residuos - erro

%funcao
function [ m ] = exerc_42( c,x )
m=c(1)./x+c(2).*x;
end
