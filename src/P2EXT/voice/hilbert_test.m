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
% checking densities for curiosity
densities_file = 'fx.ascii';
figure;
densities = more_curiousity(densities_file);
plot(1:length(densities), densities);
delete(densities_file)

function [output] = more_curiousity(input_file)
output = [];
inlet = fopen(input_file);
data = fgetl(inlet);
while ischar(data)
	output(length(output)+1) = str2num(data);
	data = fgetl(inlet);
end
fclose(inlet);