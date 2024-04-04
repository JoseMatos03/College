% alinea (a)
x=[0   0.5    1   1.5];
y=[0  0.35  0.55  0.9];
t = trapz(x,y);
disp(t);

% alinea (b)
Q = integral(@(x)0.5*x.^2-0.15*x,1.5,7.5,'AbsTol',0.3);
disp(Q);