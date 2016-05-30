function [outlet] = recognize_voice(data, threshold)
inlet = imag(hilbert(data));
limit = length(inlet);
outlet = zeros(limit);

for n = 1:limit
    if abs(inlet(n)) > threshold
        outlet(n) = 1;
    else
        outlet(n) = 0;
    end
end
