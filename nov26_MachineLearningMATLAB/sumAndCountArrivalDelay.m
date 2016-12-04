function [total,count] = sumAndCountArrivalDelay(ds)
total = 0;
count = 0;
while hasdata(ds)
    data = read(ds);
    total = total + sum(data.ArrDelay,1,'OmitNaN');
    count = count + sum(~isnan(data.ArrDelay));
end
end