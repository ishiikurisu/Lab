%% convert_edfp2csv: Converts an EDF+ file to a 
%% CSV channels file and a TXT annotations files
function [status, cmdout] = convert_edfp2csv(inputfile)
fprintf('edf+ to csv\n');
[status, cmdout] = system(sprintf('"%s\\edfp2ascii\\edfp2csv" "%s"', cd, inputfile))
