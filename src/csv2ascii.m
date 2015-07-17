% # Reading data
%
% assuming they are all the same place...
% every signal has 128 samples.
% FC5 is at 6th column (1-index),
% FC6 is at 13th,
% T7 is at 7th and
% T8 is at 12th.
%
% to read a *.csv file in matlab, use
%
% ``` matlab
% csvread(inlname, R1, C1, [R1 C1 R2 C2])
% ```
%
% matlab's csvread function is 0-indexed
%
% for FC5,read from 1, 5

function dummy = csv2ascii(out, starttime, endtime)
	inl = strcat(out, '.csv');
	ns = 128;
	samples = 13430;
	beginning = starttime * ns;
	ending = endtime * ns; % ending = 1 + samples;
	fc5_i = 5;
	fc6_i = 12; % these positions might depend on each file
	t7_i = 6;   % we might need to change them :/
	t8_i = 11;
	fc5 = csvread(inl, 1, fc5_i, [1, fc5_i, samples, fc5_i]);
	fc6 = csvread(inl, 1, fc6_i, [1, fc6_i, samples, fc6_i]);
	t7  = csvread(inl, 1, t7_i, [1, t7_i, samples, t7_i]);
	t8  = csvread(inl, 1, t8_i, [1, t8_i, samples, t8_i]);
	data = [fc5 fc6 t7 t8];

	fc5_o = strcat(out, '.fc5.ascii');
	fc6_o = strcat(out, '.fc6.ascii');
	t7_o = strcat(out, '.t7.ascii');
	t8_o = strcat(out, '.t8.ascii');
	files = {fc5_o fc6_o t7_o t8_o};
	for ii = (1:4)
		fp = fopen(files{ii}, 'w');
		for jj = (beginning:ending)
			fprintf(fp, '%f, ', data(jj, ii));
		end
		fprintf(fp, '%f', data(ending+1, ii));
		fclose(fp);
	end
end