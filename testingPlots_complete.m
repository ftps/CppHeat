%git

clear all; close all; clc

set(groot,'defaultAxesTickLabelInterpreter','latex');  
set(groot,'defaultLegendInterpreter','latex');

fontsize = 18;
xticksize = 13;

%% 1D PROBLEM: TESTING

% Test #1:

mVec_1d      = 1:99;
errorVec1_1d = [57.3787 45.4411 40.2754 37.677 36.2063 35.2986 34.7009 34.2871 33.9892 33.7678 33.6018 33.5049 33.3868 33.3201 33.2302 33.184 33.1412 33.0703 33.0334 33.0456 32.9752 32.9675 32.9776 32.9132 32.9012 32.8834 32.8959 32.8781 32.9087 32.8543 32.845 32.8298 32.8772 32.8152 32.8158 32.8276 32.8099 32.7991 32.8043 32.7942 32.8017 32.7832 32.7741 32.774 32.769 32.7658 32.7614 32.7641 32.7574 32.7711 32.7792 32.7629 32.7664 32.7695 32.7988 32.7659 32.7549 32.7481 32.7466 32.7535 32.738 32.7558 32.7544 32.735 32.7337 32.7506 32.7344 32.7532 32.7335 32.7375 32.7277 32.7305 32.7586 32.7454 32.7282 32.7343 32.7352 32.7348 32.7276 32.7247 32.7458 32.7422 32.7221 32.7286 32.7233 32.7422 32.7254 32.7205 32.718 32.7317 32.7175 32.7322 32.7306 32.7277 32.7167 32.7163 32.7339 32.7275 32.7255];
errorVec2_1d = [45.9354 26.6975 17.9132 13.3939 10.8067 9.19937 8.13658 7.39887 6.8666 6.4703 6.16746 5.93092 5.96274 5.89199 5.68764 5.52148 5.47654 5.35733 5.4688 5.26869 5.27649 5.11871 5.44397 5.32431 5.26972 5.53754 5.58421 5.77579 4.90792 4.96462 4.88769 5.23426 5.17949 4.86127 5.36319 5.17023 4.9785 4.82631 5.01376 4.84151 5.30962 4.78481 4.73833 5.07627 5.31153 4.82733 4.97087 4.77286 5.33716 4.77908 4.74088 4.8555 4.80466 4.733 4.94503 4.74019 4.7714 4.75579 4.70157 5.04866 5.24739 4.79797 4.91178 4.72237 5.2149 4.93752 5.21977 4.93357 5.00166 4.91087 4.9136 4.67045 4.73988 4.7485 4.67242 4.88768 4.84675 4.84622 4.69408 4.94629 4.70635 4.90294 4.82702 4.76129 4.90281 4.7418 4.93389 4.98343 4.71974 4.81165 4.79981 4.64345 4.93604 4.88298 4.66986 5.00398 4.72087 4.88503 4.64045];
errorVec3_1d = [44.4214 24.0959 14.7515 9.93022 7.166 5.44729 4.31023 3.52067 2.95086 2.52653 2.20223 1.9489 1.74731 1.58429 1.45062 1.33966 1.24655 1.16767 1.10026 1.04221 0.991848 0.94789 0.90929 0.875213 0.84498 0.818034 0.793915 0.772241 0.752694 0.735003 0.718941 0.704315 0.690957 0.678726 0.667498 0.657167 0.64764 0.638835 0.630681 8.28211 12.7957 15.5537 17.2772 18.4284 19.1674 19.4269 19.5317 19.3751 18.9776 18.801 18.2538 17.6311 17.0837 16.2713 15.7212 14.8334 13.9966 12.9017 12.0973 11.2568 10.0727 8.94332 8.08656 7.78835 6.6462 6.98494 7.02679 7.33975 7.10166 6.52956 5.81411 5.26185 5.56686 5.28622 4.98788 4.87064 4.817 4.30661 4.29443 4.21352 5.77019 5.78449 8.31983 8.50218 8.34929 8.56117 8.20013 8.61136 7.50052 6.54928 6.24556 5.93632 4.12456 3.97158 3.87258 3.28238 3.83405 3.20012 3.79899];
errorVec4_1d = [44.2651 23.8258 14.4225 9.56936 6.78646 5.05598 3.91108 3.11605 2.54227 2.11498 1.7884 1.5333 1.33029 1.16613 1.03152 0.919778 0.826018 0.746582 0.678697 0.62023 0.569518 0.52525 0.486378 0.452061 0.421615 0.394478 0.370189 0.348363 0.328677 0.310862 0.294686 0.279957 0.266505 0.254187 0.24288 0.232476 0.222882 0.214015 0.205803 0.198185 0.191103 0.184509 0.178359 0.172614 0.167239 0.162204 0.157479 0.153041 0.148866 0.144933 0.141226 0.137726 0.134418 0.13129 0.128327 0.125519 0.122854 0.120324 0.117919 0.115632 0.113454 0.111379 0.1094 0.107512 0.105709 0.103987 0.102339 0.100763 0.0992538 0.0978079 0.0964217 0.0950921 0.093816 0.0925906 0.0914133 0.0902814 0.0891929 0.0881454 0.0871369 0.0861655 0.0852294 0.084327 0.0834565 0.0826167 0.0818059 0.0810229 0.0802664 0.0795353 0.0788285 0.0781448 0.0774832 0.0768429 0.0762229 0.0756224 0.0750405 0.0744766 0.0739298 0.0733995 0.072885];

%cicle to get the powers of two only
i=1;    j=1;
while i<99
    mVec_1d_2(j)=j-1;
    errorVec1_1d_2(j)=errorVec1_1d(i);
    errorVec2_1d_2(j)=errorVec2_1d(i);
    errorVec3_1d_2(j)=errorVec3_1d(i);
    errorVec4_1d_2(j)=errorVec4_1d(i);
    i=i*2;
    j=j+1;
end

final_m=35;
mVec_1d_3=zeros(final_m);
errorVec1_1d_3 = zeros(final_m);
errorVec2_1d_3 = zeros(final_m);
errorVec3_1d_3 = zeros(final_m);
errorVec4_1d_3 = zeros(final_m);
for i = 1:final_m
    mVec_1d_3(i)=1./(mVec_1d(i)+1);
    errorVec1_1d_3(i)=errorVec1_1d(i);
    errorVec2_1d_3(i)=errorVec2_1d(i);
    errorVec3_1d_3(i)=errorVec3_1d(i);
    errorVec4_1d_3(i)=errorVec4_1d(i);
end


%This is the plot of error as function of m
figure(1)
plot(mVec_1d,errorVec1_1d,'LineWidth',2); grid on; hold on
plot(mVec_1d,errorVec2_1d,'LineWidth',2); hold on
plot(mVec_1d,errorVec3_1d,'LineWidth',2); hold on
plot(mVec_1d,errorVec4_1d,'LineWidth',2); hold on
a = get(gca,'XTickLabel'); set(gca,'fontsize',xticksize)
xlabel('No. Points per Dimension: m','Fontsize',fontsize,'Interpreter','latex'); 
ylabel('Relative Error (\%)','Fontsize',fontsize,'Interpreter','latex');
title('1D Case: Exact-Numerical Solution Error (t = 1 sec)','Fontsize',fontsize,'Interpreter','latex');
legend('dt = 0.1','dt = 0.01','dt = 0.001','dt = 0.0001','Location','NorthEast','Fontsize',fontsize)

%Error as a function of m as powers of 2
figure(2)
plot(mVec_1d_2,errorVec1_1d_2,'LineWidth',2); grid on; hold on
plot(mVec_1d_2,errorVec2_1d_2,'LineWidth',2); hold on
plot(mVec_1d_2,errorVec3_1d_2,'LineWidth',2); hold on
plot(mVec_1d_2,errorVec4_1d_2,'LineWidth',2); hold on
a = get(gca,'XTickLabel'); set(gca,'fontsize',xticksize)
xlabel('log_2 of the number of Points per Dimension: log_2(m)','Fontsize',fontsize,'Interpreter','latex'); 
ylabel('Relative Error (\%)','Fontsize',fontsize,'Interpreter','latex');
title('1D Case: Exact-Numerical Solution Error (t = 1 sec)','Fontsize',fontsize,'Interpreter','latex');
legend('dt = 0.1','dt = 0.01','dt = 0.001','dt = 0.0001','Location','NorthEast','Fontsize',fontsize)

%Error as a function of spacing between nodes (dx)
figure(3)
plot(mVec_1d_3,errorVec1_1d_3,'LineWidth',2); grid on; hold on
plot(mVec_1d_3,errorVec2_1d_3,'LineWidth',2); hold on
plot(mVec_1d_3,errorVec3_1d_3,'LineWidth',2); hold on
plot(mVec_1d_3,errorVec4_1d_3,'LineWidth',2); hold on
a = get(gca,'XTickLabel'); set(gca,'fontsize',xticksize)
xlabel('Distance between nodes dx','Fontsize',fontsize,'Interpreter','latex'); 
ylabel('Relative Error (\%)','Fontsize',fontsize,'Interpreter','latex');
title('1D Case: Exact-Numerical Solution Error (t = 1 sec)','Fontsize',fontsize,'Interpreter','latex');
legend('dt = 0.1','dt = 0.01','dt = 0.001','dt = 0.0001','Location','NorthEast','Fontsize',fontsize)

%% 2D PROBLEM: TESTING

mVec_2d      = 3:3:99;
errorVec1_2d = [54.1066 51.02 50.2178 49.8988 49.7408 49.6512 49.5957 49.559 49.5337 49.5147 49.5014 49.4905 49.4829 49.4754 49.4703 49.4658 49.4626 49.4587 49.4563 49.4545 49.4521 49.4501 49.4491 49.4486 49.4462 49.4451 49.4444 49.4434 49.4425 49.4419 49.4412 49.4408 49.4402];
errorVec2_2d = [21.1715 13.0507 10.8818 10.0271 9.7186 9.82569 9.31048 9.43827 9.39442 9.02665 9.40334 9.14093 8.94577 9.44282 9.06766 9.17412 8.88987 9.11308 8.99196 9.52601 8.87222 9.62914 8.86393 8.83171 8.84402 8.82295 8.82385 9.64856 8.8073 8.88064 8.84829 9.03626 8.94056];
errorVec3_2d = [15.1143 5.87853 3.40111 2.40685 1.91241 1.63166 1.45719 1.34146 1.26079 1.5513 1.34544 1.23533 1.17564 1.21527 2.11803 2.31536 1.72137 2.33655 1.23448 2.30449 2.13692 2.27461 2.59763 2.17319 4.76766 1.8608 1.71549 2.0011 1.36322 1.55946 2.71161 3.60486 1.71317];

figure(4)
plot(mVec_2d,errorVec1_2d,'LineWidth',2); grid on; hold on
plot(mVec_2d,errorVec2_2d,'LineWidth',2); hold on
plot(mVec_2d,errorVec3_2d,'LineWidth',2); hold on
a = get(gca,'XTickLabel'); set(gca,'fontsize',xticksize)
xlabel('No. Points per Dimension: m','Fontsize',fontsize,'Interpreter','latex'); 
ylabel('Relative Error (\%)','Fontsize',fontsize,'Interpreter','latex');
title('2D Case: Exact-Numerical Solution Error (t = 0.5 sec)','Fontsize',fontsize,'Interpreter','latex');
legend('dt = 0.1','dt = 0.01','dt = 0.001','Location','Best','Fontsize',fontsize)

final_m=15;
mVec_2d_3=zeros(final_m);
errorVec1_2d_3 = zeros(final_m);
errorVec2_2d_3 = zeros(final_m);
errorVec3_2d_3 = zeros(final_m);
for i = 1:final_m
    mVec_2d_3(i)=1./(mVec_2d(i)+1);
    errorVec1_2d_3(i)=errorVec1_2d(i);
    errorVec2_2d_3(i)=errorVec2_2d(i);
    errorVec3_2d_3(i)=errorVec3_2d(i);
end
figure(5)
plot(mVec_2d_3,errorVec1_2d_3,'LineWidth',2); grid on; hold on
plot(mVec_2d_3,errorVec2_2d_3,'LineWidth',2); hold on
plot(mVec_2d_3,errorVec3_2d_3,'LineWidth',2); hold on
a = get(gca,'XTickLabel'); set(gca,'fontsize',xticksize)
xlabel('Distance between nodes dx','Fontsize',fontsize,'Interpreter','latex'); 
ylabel('Relative Error (\%)','Fontsize',fontsize,'Interpreter','latex');
title('2D Case: Exact-Numerical Solution Error (t = 0.5 sec)','Fontsize',fontsize,'Interpreter','latex');
legend('dt = 0.1','dt = 0.01','dt = 0.001','Location','Best','Fontsize',fontsize)



