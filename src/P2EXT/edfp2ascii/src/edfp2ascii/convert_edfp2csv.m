%% convert_edfp2csv: Converts an EDF+ file to a 
%% CSV channels file and a TXT annotations files
function [status, cmdout] = convert_edfp2csv(inputfile)
fprintf('edf+ to csv\n');
[status, cmdout] = system(sprintf('"%s\\edfp2ascii\\edfp2csv" "%s"', cd, inputfile));
% TODO separate the annotations from the csv file in the cmdout variable
%      and save them into two different files.
[csv notes] = separate_csv_from_notes(cmdout);
notes

function [chops] = split_string(inlet, separator)
limit = length(inlet);
chops = {};
chop = '';
index = 1;

while index <= limit
	it = inlet(index);
	if isequal(it, separator)
		chops{length(chops)+1} = chop;	
		chop = '';
	else
		chop = [chop it];
	end

	index = index+1;
end

if length(chop) > 0
	chops{length(chops+1)} = chop;
end

%% starts_with: checks if the first string begins with the other string
function [result] = starts_with(haystack, needle)
result = true;

for index = 1:length(needle)
	if ~isequal(haystack(index), needle(index))
		result = false;
		break;
	end
end

%% separate_csv_from_notes: it does what it promises.
function [csv, notes] = separate_csv_from_notes(inlet)
fprintf('separating stuff...\n');
lines = split_string(inlet, sprintf('\n'));
index = 1;

csv = '';
while and(~starts_with(lines{index}, '---'), index < length(lines))
	csv = [csv lines{index} '\n'];
	index = index+1;
end

notes = '';
while index < length(lines)
	notes = [notes lines{index} '\n'];
	index = index+1;
end
