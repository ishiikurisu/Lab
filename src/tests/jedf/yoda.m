function [outlet] = yoda(inlet)
% Testing `br.unb.biologiaanimal.edf` package with MATLAB.
fprintf('---\n');
fprintf('Input file: %s\n', inlet);
fprintf('# Importing data\n');
javaaddpath(strcat(pwd, '/edf.jar'));
if exist(inlet, 'file') == 2
	fprintf('# Loading files\n');
	edf = br.unb.biologiaanimal.edf.EDF(inlet);
	outlet = edf;
	fprintf('# Displaying data\n');
	labels = edf.getLabels();
	fprintf('Labels:\n');
	for n = 1:length(labels)
		fprintf('- %s\n', labels(n)); % TODO Discover why this line doesn't work
	end
	fprintf('Convertion factors:\n')
	for n = 1:length(labels)
		fprintf('- %s: %s\n', labels(n), edf.getConvertionFactor(labels(n)));
	end
	plot(edf.getSignal(labels(1)));
else
	fprintf('/!\\ FILE DOES NOT EXIST!\n');
end