function dummy = csv2asciiV2(output, starttime, endtime)
	inputfile = strcat(output, '.csv');
	numbersamples = 128;
	beginning = starttime * numbersamples;
	ending = endtime * numbersamples;
	inlet = fopen(inputfile, 'r');

	% + analize header
	header = fgetl(inlet);
	labels = get_labels(header);
	[fc5, fc6, t7, t8] = analize_labels(labels);
	positions = [fc5, fc6, t7, t8];

	% + read and write data
	fc5 = fopen(strcat(output, '.fc5.ascii'), 'w');
	fc6 = fopen(strcat(output, '.fc6.ascii'), 'w');
	t7 = fopen(strcat(output, '.t7.ascii'), 'w');
	t8 = fopen(strcat(output, '.t8.ascii'), 'w');
	files = {fc5, fc6, t7, t8};

	%   + first iteration
	row = fgetl(inlet);
	for moment = 3:beginning
		row = fgetl(inlet);
	end

	columns = strread(row, '%s', 'delimiter', ',');
	for ii = (1:4)
		fp = files{ii};
		jj = positions(ii);
		data = columns{jj};
		fprintf(fp, '%f', data);
	end

	%   + other iterations
	for moment = beginning:ending
		row = fgetl(inlet);
		columns = strread(row, '%s', 'delimiter', ',');
		for ii = (1:4)
			fp = files{ii};
			jj = positions(ii);
			data = columns{jj};
			fprintf(fp, ', %f', data);
		end
	end

	% + cleaning the house
	for ii = (1:4)
		fclose(files{ii});
	end
	fclose(inlet);
end
