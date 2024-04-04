[x,fval,exitflag,output]=fsolve(@exerc_15,[0 0]);

function [ F ] = exerc_15(x)
    F(1) = (x(1)-10)^2+(x(2)-10)^2-14^2;
    F(2) = (x(1)-10)^2+(x(2)+10)^2-16^2;
end