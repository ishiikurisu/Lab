function [] = trab()
R = 83.14462; %mL*bar/K*mol
PropMatrix = [304.2 73.76 0.225; 452.2 38.00 0.193];
k = [0 0.130 ; 0.130 0];
y(1) = 0.82;
y(2) = 1-y(1);
T = 273+50;
x(1) = 0.3585;
x(2) = 1 - x(1);

% parametros puros
for q=1:2
    Tc(q) = PropMatrix(q,1);
    Pc(q) = PropMatrix(q,2); 
    omega(q) = PropMatrix(q,3);
    kappa = 0.37464 + 1.54226.*omega - 0.26692.*omega.^2;
    ac = 0.457235*R^2.*Tc.^2./Pc;
    b = 0.077796*R.*Tc./Pc;
    a = ac.*(1+kappa.*(1-sqrt(T./Tc))).^2;
end
     
%PRmixParamsL

for p = 1:40
    P = p

    % parametros liquidos
    aml = 0;
    bml = 0;
    for n = 1:2
        for m = 1:2
            aml = aml + sum(sum(x(n)*x(m)*sqrt(a(m)*a(n))*(1-k(m,n))));
            for i = 1:2
                bml = bml + sum(x(i)*b(i));
            end
        end
    end
    Al = aml.*P/(R^2.*T.^2);
    Bl = bml.*P./(R*T);
    coefl = [1, (Bl-1), (Al - 2.*Bl - 3.*Bl.^2), (Bl.^3 + Bl.^2 - Al.*Bl)];

    %PRmixParamsV
    amv = 0;
    bmv = 0;
    for n = 1:2
        for m = 1:2
            amv = amv + sum(sum(y(n)*y(m)*sqrt(a(m)*a(n))*(1-k(m,n))));
            for i = 1:2
                bmv = bmv + sum(y(i)*y(i));
            end
        end
    end

    Av = amv.*P/(R^2.*T.^2);
    Bv = bmv.*P./(R*T);
    coefv = [1, (Bv-1), (Av - 2.*Bv - 3.*Bv.^2), (Bv.^3 + Bv.^2 - Av.*Bv)];

    % resolver sistema de equações definido por coefv e coefl
    % TODO resolver este passo
    zzz = roots(coefl);
    rv = roots(coefv);
    for ii = 1:length(rv);
        zzz(length(zzz)+1) = rv(ii);
    end

    for ii = 1:length(zzz)
        if abs(imag(zzz(ii))) > 0
            zzz(ii) = 0;
        end
    end
    zzz

    ZL = min(zzz);
    ZV = max(zzz);

    %PRfugl

    for i=1:2
        for j=1:2
            fl(i) = (ZL -1)*b(i)/bml - log(ZL - Bl) - ((aml/(2*sqrt(2)*bml*R*T))*((2*sum(x(j)*sqrt(a(i)*a(j))*(1-k(i,j))))/aml - Bl/bml)*log((ZL + (1+sqrt(2))*Bl)/(ZL+(1-sqrt(2))*Bl)));
            phil(i) = exp(fl(i));
            fugl(i) = P*y(i)*phil(i);
        end
    end

    %PRfugl

    for i=1:2
        for j=1:2
            fv(i) = (ZV -1)*b(i)/bmv - log(ZV - Bv) - ((amv/(2*sqrt(2)*bmv*R*T))*((2*sum(y(j)*sqrt(a(i)*a(j))*(1-k(i,j))))/amv - Bv/bmv)*log((ZV + (1+sqrt(2))*Bv)/(ZV+(1-sqrt(2))*Bv)));
            phiv(i) = exp(fv(i));
            fugv(i) = P*y(i)*phiv(i);
        end
    end

    test1 = 0;
    test2 = 0;
    if abs(1-fugl(1)/fugv(1)) > 0.00001
        y(1) = y(1) * fugl(1)/fugv(1);
    else
        test1 = 1;
    end

    if  abs(1-fugl(2)/fugv(2)) > 0.00001
        y(2) = y(2) * fugl(2)/fugv(2);
    %elseif condition
    % body
    else
        test2 = 1;
    end
    if and(test1, test2)
        break
    end
end

fprintf('P = %f\n', P);
disp(y);

function [ZL, ZV] = PRsolvEOS(coef)
ZZ = roots(coef);
Z1 = ZZ(1);
Z2 = ZZ(2);
Z3 = ZZ(3);
if abs(imag(Z2))> 0 
    Z1 = 0;
end
if abs(imag(Z2))> 0 
    Z2 = 0;
end
if abs(imag(Z3))> 0
    Z3 = 0;
end

% zzz = [Z1 Z2 Z3];
% zz = sort(zzz);

% %if zz(1) = 0
%  %   zz(1) = zz(3)
% %end

% %if zz(3)= 0
%  %   zz(3) = zz(1)
% %end

ZL = min(zzz);
ZV = max(zzz);