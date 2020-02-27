
clear all; close all; clc

set(groot,'defaultAxesTickLabelInterpreter','latex');  
set(groot,'defaultLegendInterpreter','latex');

fontsize = 18;
xticksize = 13;

%% 1D PROBLEM: TESTING

% Test #1: dt = 0.001, alpha = 0.3125

mVec1     = 1:99;
errorVec1 = [44.4214 24.0959 14.7515 9.93022 7.166 5.44729 4.31023 3.52067 2.95086 2.52653 2.20223 1.9489 1.74731 1.58429 1.45062 1.33966 1.24655 1.16767 1.10026 1.04221 0.991848 0.94789 0.90929 0.875213 0.84498 0.818034 0.793915 0.772241 0.752694 0.735003 0.718941 0.704315 0.690957 0.678726 0.667498 0.657167 0.64764 0.638835 0.630681 8.28211 12.7957 15.5537 17.2772 18.4284 19.1674 19.4269 19.5317 19.3751 18.9776 18.801 18.2538 17.6311 17.0837 16.2713 15.7212 14.8334 13.9966 12.9017 12.0973 11.2568 10.0727 8.94332 8.08656 7.78835 6.6462 6.98494 7.02679 7.33975 7.10166 6.52956 5.81411 5.26185 5.56686 5.28622 4.98788 4.87064 4.817 4.30661 4.29443 4.21352 5.77019 5.78449 8.31983 8.50218 8.34929 8.56117 8.20013 8.61136 7.50052 6.54928 6.24556 5.93632 4.12456 3.97158 3.87258 3.28238 3.83405 3.20012 3.79899];
plot(mVec1,errorVec1,'b','LineWidth',2); grid on; hold on
a = get(gca,'XTickLabel'); set(gca,'fontsize',xticksize)
xlabel('No. points per dimension: m','Fontsize',fontsize,'Interpreter','latex'); 
ylabel('Relative Error (\%)','Fontsize',fontsize,'Interpreter','latex');
legend('dt = 0.001','Location','NorthEast','Fontsize',fontsize)
%title('Pitch rate','Fontsize',fontsize,'Interpreter','latex');