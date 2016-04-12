# Description

This folder contains the code made by [me](https://github.com/ishiikurisu) while working as an intern for Neurosciences and behavior laboratory at UnB.

# Projects

My projects can be accessed in the [`src`](https://github.com/ishiikurisu/EEG/tree/master/src) folder. Every code here is intended to be run on Windows.

EDF
---

The objective of this project is to read files in EDF format so they can be treated by many different software. It's composed of the [`edf`](https://github.com/ishiikurisu/EEG/tree/master/src/EDF) folder. Currently, we can manage EDF+ files, and they are expected to be used as part of [PROTOLIZE!2](https://github.com/ishiikurisu/P2).

Stop Signal Test
----------------

The objective of this project is to implement a version of the Stop Signal test (SST). Initially implemented using the E-PRIME (c) software with art made using PROCESSING. It's composed of the [SST](https://github.com/ishiikurisu/EEG/tree/master/src/SST) folder.

Raven's Progressive Matrices
----------------------------

We want to implement a version of the Raven's Progressive Matrices (RPM) test to apply on children; and generate not only _g_-factors but also electroencephalographic data from them, so we can analyze how children take decisions during these tests. It's currently implemented on E-prime and (almost) on C#, but there is no application to analyze its generated data. It's located in the [Raven](https://github.com/ishiikurisu/EEG/tree/master/src/raven) folder.

Minor Projects
--------------
### Beck's Inventories ###

An implementation of the Beck's Depression and anxiety inventories in C#. It's located in the [beck](https://github.com/ishiikurisu/EEG/tree/master/src/beck) folder, and it is meant to be translatable to any language.

It is currently being worked on the [scalemate](https://github.com/ishiikurisu/Scalemate) repository, due to its success. It has been renamed and it is fully growing as its own unique project now.

### Edinburgh Handedness Inventory ###

An implementation of the Edinburgh Handedness Inventory in Go using [walk](https://github.com/lxn/walk) by @lxn. It is located in the [edinburgh](https://github.com/ishiikurisu/EEG/tree/master/src/edinburgh) folder.

### Benchmarking ###

A small application to clock another app's performance. Nothing fancy.