%% curiosity: Just to see how the Hilbert transform looks and sounds like
function curiosity(testcase)
[recording, samplerate, nbits] = wavread(testcase);
hilberted = imag(hilbert(recording));
steps = 1:length(recording);
figure;
plot(steps, recording, 'b', ...
     steps, hilberted, 'r');
