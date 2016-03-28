%% convert_csv2ascii: converts an EDF+ file to ASCII files
function [status, cmdout] = convert_csv2ascii(inlet, how)
[status, cmdout] = system(sprintf('edfp2ascii\\%s %s', get_operation(how), generate_name(inlet)))

function [outlet] = get_operation(inlet)
if isequal(inlet, true)
	outlet = 'csv2multiple';
else
	outlet = 'csv2single';
end

function [outlet] = generate_name(inlet)
outlet = [inlet(1:get_offset(inlet)-1) '.csv']
function [offset] = get_offset(inlet)
offset = get_offset_loop(inlet, length(inlet));
function [offset] = get_offset_loop(inlet, where)
if isequal(inlet(where), '.')
	offset = where
else
	offset = get_offset_loop(inlet, where-1);
end