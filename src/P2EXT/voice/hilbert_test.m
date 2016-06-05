%% hilbert_test: testing our implementation of the hilbert transform
function hilbert_test(testcase)
[recording, samplerate, nbits] = wavread(testcase);
limit = length(recording);
idea_of_threshold = mean(recording) + std(recording);
tic;
voice_file = recognize_voice(recording, idea_of_threshold);
intervals_file = recognize_density(voice_file);
recognition = load_intervals(intervals_file, limit);
toc
steps = 1:limit;
delete(voice_file);
delete(intervals_file);
figure;
plot(steps, recording, 'b', ...
     steps, recognition, 'r');
