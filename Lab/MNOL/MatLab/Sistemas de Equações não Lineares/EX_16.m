[x,fval,exitflag,output]=fsolve(@exerc_16,[0.30 0.30]);

function [ F ] = exerc_16(x)
    F(1) = (x(1)^4+0.068*x(1))-(x(2)^4+0.058*x(2))-0.0159;
    F(2) = (x(1)^4+0.058*x(1))-(2*x(2)^4+0.117*x(2));
end