% # About
% 
% This script translates every file in a database
% 'EEG.csv' using the 'csv2ascii' function
%
% ## Algorithm
% 
% for each file
%   GET FILE NAME {fn}
%   GET INTERVALS {b, e}
%   csv2ascii(fn, b, e)
% end
%
% # Side notes
%
% + The original *.xls file has 289 lines, and 
%   the first one is a header. 
%

inlet = 'EEG.csv'
csv2ascii('..\data\1.01.1.1.1', 60, 100);