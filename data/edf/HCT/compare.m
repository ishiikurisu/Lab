% Loading data
golang = load('HCT-4-23.ECG.ascii');
jvm = load('ECG.ascii');

% Drawing data
hold on;
plot(jvm, 'r');
plot(golang, 'b');
hold off;