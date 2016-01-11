function [fc5, fc6, t7, t8] = analize_labels(raw_data)
	labels = strread(raw_data, '%s', 'delimiter', ' ');
	limit = length(labels) - 1;
	
	for ii = 1:limit
		label = labels{ii};

		if strcmp(label, 'FC5')
			fc5 = ii;
		elseif strcmp(label, 'FC6')
			fc6 = ii;
		elseif strcmp(label, 'T7')
			t7 = ii;
		elseif strcmp(label, 'T8')
			t8 = ii;
		end
	end
end

