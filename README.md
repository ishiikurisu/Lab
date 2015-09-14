# Description

Code made while working for Neurosciences
and behaviour laboratory at UnB.

# Projects

My projects can be accessed in the `src` folder.

EDF
---

The objective of this project is to read files in EDF format, specially from EMOTIV devices so they can be treated using the EEGLAB software. Right now, my executables can read `*.edf` and translate them into YAML, CSV and ASCII formats; but not in a way EEGLAB can understand, given EMOTIV's TESTBENCH (c) and EEGLAB don't yield the same data on screen. Therefore, my current challenge is to make EEGLAB read these EDF files the same way TESTBENCH (c) does. It's composed of the `EDF`, `csv2ascii` and `edf2ascii` folders. In the future, I want to add support for EDF+.

Stop Signal Test
----------------

The objective of this project is to implement a version of the Stop Signal test (SST). Initially implemented using the E-PRIME (c) software with art made using PROCESSING, I'm now working on a PROCESSING implemented version just for fun. 

Minor Projects
--------------

### OA folder ###

This is the code I made during the "Organização de Arquivos" discipline here at University of Brasília. I use it in the EDF project.

### Benchmarking ###

A small application to clock another app's performance. Nothing fancy.

### Buffering ###

A buffering header to make access to large files faster. Works well now but needs a whole lot more improvements, specially writing data types that aren't `char*`.

### Software adaptations ###

We adapted the PROTOLIZE! software to automatically save files with an specific extension with one button click.