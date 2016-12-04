function [Input, Target] = Prepare(Ferment, Temp)
len = round(length(Ferment)/12);
Index = 1:len;
Sweet = 1.044*ones(1,len);
Temp = median( reshape(Temp(1:12*len), 12, len) );
Alcohol = median( reshape(Ferment(1:12*len), 12, len) );
Input = [Index;Sweet;Temp;Alcohol];
Target= repmat(mean(Ferment(end-12:end)), 1, len);
end