%% calculate_dot_density: Get the dot density of a bitset
function [output_file] = recognize_density(input_file)
% Get the dot density of a bitset
global windowsize
windowsize = 256;
hole = floor(sqrt(windowsize));
output_file = 'density.ascii';
sideeffect_file = 'fx.ascii';
density = 0.35;
inlet = fopen(input_file);
fxlet = fopen(sideeffect_file, 'wt');
outlet = fopen(output_file, 'wt');
last = 0;
linenumber = 1;
queue = make_queue(inlet);
while length(queue) > 0
    dot_density = calculate_dot_density(queue);
    fprintf(fxlet, '%f\n', dot_density);
    current = dot_density >= density;
    if current > last % is rising?
        fprintf(outlet, '%f\n', linenumber);
    end
    last = current;
    linenumber = linenumber + hole;
    queue = update_queue(inlet, queue);
end
fclose(inlet);
fclose(fxlet);
fclose(outlet);

function [queue] = make_queue(inlet)
global windowsize
queue = [];
for n = 1:windowsize
    queue(length(queue)+1) = str2num(fgetl(inlet));
end

function [density] = calculate_dot_density(queue)
density = 0;
for item = queue
    density = density + item;
end
density = density / length(queue);

function [queue] = update_queue(inlet, queue)
global windowsize
limit = floor(sqrt(windowsize));
data = fgetl(inlet);
n = 1;
if ischar(data)
    queue = queue(limit:length(queue));
    while and(n <= limit, ischar(data))
        queue(length(queue)+1) = str2num(data);
        data = fgetl(inlet);
        n = n+1;
    end
else
    queue = [];
end
