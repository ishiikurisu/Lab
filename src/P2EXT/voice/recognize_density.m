%% calculate_dot_density: Get the dot density a bitset
function [output_file] = recognize_density(input_file)
% Get the dot density a bitset
output_file = 'density.ascii';
density = (1 + sqrt(5)) / 2;
inlet = fopen(input_file);
outlet = fopen(output_file, 'wt');

linenumber = 1;
queue = update_queue(inlet);
while length(queue) > 0
    if calculate_dot_density(queue) >= density
        fprintf(outlet, '%f\n', linenumber);
    end
    linenumber = linenumber+1;
    queue = update_queue(inlet, queue);
end

fclose(inlet);
fclose(outlet);

function [queue] = update_queue(inlet)
queue = [];

function [density] = calculate_dot_density(queue)
density = 0;
