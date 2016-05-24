function [outlet] = recognize_voice(data, threshold)
inlet = imag(hilbert(data));
outlet = [];

for n = 1:length(inlet)
    if abs(inlet(n)) > threshold
        outlet(n) = 1;
    else
        outlet(n) = 0;
    end
end
