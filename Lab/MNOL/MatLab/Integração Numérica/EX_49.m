h=(1-0)/4 %5 pontos <=> 4 subintervalos
x=0:h:1
y=sqrt(1+(-exp(-x)).^2)
sol_5_pontos=trapz(x,y)
