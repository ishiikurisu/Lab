function coffee()
disp('Let''s call java from matlab');
disp('Adding path...');
addpath(pwd);
javaaddpath(pwd);
disp('Testing donut...');
salute = donuts.Donut.sayHi('Joe');
disp(salute);
disp('Testing cupcake...');
cake = cupcake.Cupcake('Frank');
disp(cake.sayHi());
disp('Ok!');
