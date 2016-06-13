function RecognizeVoice(testcase, density)
[recording, samplerate, nbits] = wavread(testcase);
limit = length(recording);
idea_of_threshold = mean(recording) + std(recording);
voice_file = recognize_voice(recording, idea_of_threshold);
intervals_file = recognize_density(voice_file, density);
recognition = load_intervals(intervals_file, limit);
steps = 1:limit;
delete(voice_file);
movefile(intervals_file, strcat(testcase, '.ascii'));
figure;
plot(steps, recording, 'b', ...
     steps, recognition, 'r');