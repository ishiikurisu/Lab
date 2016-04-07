cls
REM build edf2csv
cd src
mingw32-make all
mingw32-make edfp2notes
move *.exe ..
cd..

REM translate data
rem edf2ascii data\joe-teste-17.02.16.13.56.33.edf > "C:\Documents and Settings\Laboratorio.LABORATO-6A7377\Meus documentos\software\eeglab\joe.ascii"
rem edf2ascii data\joe-teste-17.02.16.13.56.33.edf > data\joe.ascii
edf2ascii data\testelinhadebase.edf > data\tlb.ascii
edfp2notes data\testelinhadebase.edf
