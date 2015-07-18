% # About
% 
% This script translates every file in a database
% 'EEG.csv' using the 'csv2ascii' function
%
% ## Algorithm
% 
%     for each file
%       GET FILE NAME fn
%       GET INTERVALS b, e
%       csv to ascii(fn, b, e)
%     end
%
% # Side notes
%
% + The original *.xls file has 289 lines, and 
%   the first one is a header. 
%

input_file = 'EEG.csv';
inlet = fopen(input_file, 'r');
row =  fgetl(inlet); %reading header
row = fgetl(inlet); %first row
while ischar(row)
	[fn, b, e] = parse_row(row);
	csv2ascii(fn, b, e);
	row = fgetl(inlet);
end

% csv2ascii('..\data\1.01.1.1.1', 60, 100);