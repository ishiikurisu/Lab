%% convert_edfp2csv: Converts an EDF+ file to a 
%% CSV channels file and a TXT annotations files
function [status, cmdout] = convert_edfp2csv(inputfile)
[status, cmdout] = system(sprintf('edfp2ascii\\edfp2csv "%s"', inputfile))

