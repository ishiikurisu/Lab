# Description

This folder contains the code made by [me](https://github.com/ishiikurisu) while working as an intern for Neurosciences and behavior laboratory at UnB.

# Projects

My projects can be accessed in the [`src`](https://github.com/ishiikurisu/EEG/tree/master/src) folder.

EDF
---

The objective of this project is to read files in EDF format, specially from EMOTIV devices so they can be treated using the EEGLAB software. It's composed of the [`edf`](https://github.com/ishiikurisu/EEG/tree/master/src/EDF) folder.

Currently, my executables can read `*.edf` and translate them into YAML, CSV and ASCII formats; but not in a way EEGLAB can understand, given EMOTIV's TESTBENCH (c) and EEGLAB don't yield the same data on screen. Therefore, my current challenge is to make EEGLAB read these EDF files the same way TESTBENCH (c) does. In the future, I want to add support for EDF+, so we might process every possible kind of EDF files by ourselves.

Stop Signal Test
----------------

The objective of this project is to implement a version of the Stop Signal test (SST). Initially implemented using the E-PRIME (c) software with art made using PROCESSING, I'm now working on a PROCESSING implemented version just for fun. It's composed of the [SST](https://github.com/ishiikurisu/EEG/tree/master/src/SST) folder.

Raven's Progressive Matrices
----------------------------

We want to implement a version of the Raven's Progressive Matrices (RPM) test to apply on children; and generate not only _g_-factors but also electroencephalographic data from them, so we can analyze how children take decisions during these tests. It's currently implemented on E-prime and (almost) on C#, but there is no application to analyze its generated data. It's located in the [Raven](https://github.com/ishiikurisu/EEG/tree/master/src/raven) folder.

Minor Projects
--------------

### Edinburgh Handedness Inventory ###

An implementation of the Edinburgh Handedness Inventory in Go using [walk](https://github.com/lxn/walk) by @lxn. It is located in the [edinburgh](https://github.com/ishiikurisu/EEG/tree/master/src/edinburgh) folder.

### OA folder ###

This is the code I made during the "Organização de Arquivos" course here at University of Brasília. I use it in the EDF project.

### Benchmarking ###

A small application to clock another app's performance. Nothing fancy.

### Buffering ###

A buffering header to make access to large files faster. Works well now but needs a whole lot more improvements, specially writing data types that aren't `char*`.
