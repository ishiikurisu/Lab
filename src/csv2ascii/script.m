input_file = 'EEG.csv';
fp = fopen(input_file, 'r');
row = fgetl(fp); % reading header
row = fgetl(fp); % first row
while ischar(row)
	[fn, b, e] = parse_row(row);
	ff = strcat(fullfile(cd, fn), '.csv');
	if exist(ff, 'file') == 2
		% csv2ascii(fn, b, e);
		csv2ascii(fn, 0, 50);
	end
	row = fgetl(fp);
end
fclose(fp);
