clear;clc;
dir='D:\FIEC\F_BLOG\DSD\DATABASE\PID_ServoMotor\2020GarzonSoledispa\2020data\';
Fs=600;%Hz frecuencia de muestreo
Datos=importdata(strcat(dir,'data.txt'));
%%
plot(Datos(:,1:3));
hold on;
plot(Datos(:,4)*100);
legend('Potenciometro','LDR1','LDR2','Dirección_t_=_0');
xlabel('Muestras');
ylabel('Valores');
title('Datos adquiridos');
%% Datos para la red neuronal
inNN=Datos(1:length(Datos)-10,:);%'Potenciometro','LDR1','LDR2','Dirección_t_=_0'
outNN=Datos(11:length(Datos),4);%'Dirección_t_+_1'

plot(inNN(:,4));
hold on;
plot(outNN(:,1));
legend('Dirección_t_=_0','Dirección_t_+_1');
xlabel('Muestras');
ylabel('Valores');
title('Datos de entrenamiento');
%%
nnstart
%%
pred=[];
pred=myNeuralNetworkFunction(inNN());
err = immse(outNN,pred)/max(pred)
acc=1-err

plot(outNN(:,:));
hold on;
plot(pred(:,:));
plot(round(pred(:,:)+0.30));
legend('Dirección_t_+_1','Real_Prediction','Prediction_t_+_1');
xlabel('Muestras');
ylabel('Valores');
title('Datos de Predicción');