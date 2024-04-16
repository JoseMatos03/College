x=-1:0.5:1;
y=exp(-(x.^2)./2);
I=trapz(x,y);
F=(1+1/sqrt(2*pi)*I)/2;