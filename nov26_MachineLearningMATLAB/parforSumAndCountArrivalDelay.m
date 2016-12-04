function [total, count] = parforSumAndCountArrivalDelay(ds)

N = numpartitions(ds,gcp);
total = 0;
count = 0;
parfor ii = 1:N
    % Get partition ii of the datastore.
    subds = partition(ds,N,ii);
    
    [localTotal,localCount] = sumAndCountArrivalDelay(subds);
    total = total + localTotal;
    count = count + localCount;
end
end