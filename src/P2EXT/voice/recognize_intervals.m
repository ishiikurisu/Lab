%% recognize_intervals: Recognize where the voice spots begin
function [output_file] = recognize_intervals(input_file)
% Recognize where the voice spots begin
output_file = 'intervals.yml';
room = recognize_room(input_file);
inlet = fopen(input_file);
outlet = fopen(output_file, 'wt');
queue = fill_queue(inlet, room);
data = fgetl(inlet);
linenumber = 1;
while ischar(data)
    n = str2num(data);
    if and(isequal(n, 1), empty_spot(queue));
        fprintf(outlet, '%f\n', linenumber);
    end
    queue = walk_queue(queue, n);
    data = fgetl(inlet);
    linenumber = linenumber + 1; % heheheh
end
fclose(inlet);
fclose(outlet);

%% recognize_room: check what is the best length of emptiness to be used
function [room] = recognize_room(input_file)
inlet = fopen(input_file);
diffs = [];
room = 0;
it = fgetl(inlet);
while ischar(it)
    if isequal(str2num(it), 0)
        room = room+1;
    elseif room > 50 % TODO: arbitrate this number in a better way
        diffs(length(diffs)+1) = room;
        room = 0;
    end
    it = fgetl(inlet);
end
fclose(inlet);
room = floor(mean(diffs));

%% fill_queue: allocate space for queue
function [queue] = fill_queue(inlet, room)
queue = [];
for n = 1:room
    queue(n) = str2num(fgetl(inlet));
end

%% empty_spot: check if this spot has nothing before it
function [result] = empty_spot(pre)
result = 1;
for it = pre
    if isequal(it, 1)
        result = 0;
    end
end

%% walk_queue: reallocate queue items
function [queue] = walk_queue(queue, item)
queue = queue(2:length(queue));
queue(length(queue)+1) = item;
