%% hilbert_transform: our implementation of the hilbert transform of an array
function [H] = hilbert_transform(u)
% H = imag(ifft(-j * fft(u)));
H = imag(hilbert(u));