%% delegate: Decides if it should use single or multiple translation
function [errorcode] = delegate(inputfile, is_multiple)
% inputfile    a string containing the input file
% is_multiple  how this file should be translated
convert_edfp2csv(inputfile);
errorcode = convert_csv2ascii(inputfile, is_multiple);
