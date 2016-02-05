function labels = get_labels(header)
	while header
		[column, header] = strtok(header, ',');
		[key, value] = strtok(column, ':');
		if strfind(key, 'label')
			labels = value;
		end
	end
end