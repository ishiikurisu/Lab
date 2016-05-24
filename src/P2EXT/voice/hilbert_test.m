%% hilbert_test: testing our implementation of the hilbert transform
function hilbert_test()
% This test consists of no steps by now

disp('Testing the Hilbert transform');
% defining domain
x = -2*pi:1/100:2*pi;
c = cos(x);
s = sin(x);
q = square(x);

% calculating Hilbert transforms
hc = hilbert_transform(c);
hs = hilbert_transform(s);
hq = hilbert_transform(q);

disp('Reading sound waves');
tic;
[recording, samplerate, nbits] = wavread('voicerecognition.wav');
steps = 1:length(recording);
disp('Calculating threshold')
idea_of_threshold = mean(recording) + std(recording);
disp('Applying algorithm');
recognition = recognize_voice(recording, idea_of_threshold);
toc

disp('Displaying results');
figure;
plot(steps, recording, 'b', ...
     steps, recognition, 'r');
