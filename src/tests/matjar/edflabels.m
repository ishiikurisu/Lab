function [labels] = edflabels(filename)
% Gets the labels in an EDF file

% Adding jar file with EDF class
javaaddpath(strcat(cd, '/bin/EDF.jar'));
javaclasspath

% Loading file
edf = br.unb.biologiaanimal.edf.EDF(filename);
labels = edf.getLabels();