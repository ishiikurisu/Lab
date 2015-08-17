Foundations of neural networks
==============================

by Patrick K. Simpson

What are neural networks
------------------------

NNs are information processing systems and can be thought of as "black box" devices that accepts inputs and produce outputs. Some of its operations include:

* Classification
* Pattern matching
* Pattern completion
* Nose removal
* Optimization
* Control

NNs consists of processing elements (PEs) and weighted connections (Ws). Each PE:

* collects values from of its input connections
* performs a predefined opration;
* produces a single output value. 

Each NN has many layers, each layer with many PEs. Each W:

* acts both as a label and a value
* stores some information

Its value is often determined by a learning procedure. Every NN has the following features:

* each PE acts independently of each other
* each PE relies only on local information
* the large number of connections provides a large amount of redundancy and facilitates aa distributed representation.

There are three primary situations where NNs are advantageous;

* few decisions from a massive amount of data
* automatic acquisition of nonlinear mappings
* very quick solutions from optimization problems

NNs consist of 3 main elements:

* topology: how a NN is orgaized into layers and how those layers are connected
* learning: how information is stored in the network
* recall: how the information is retrieved from the network

Dissecting Neural Networks
--------------------------

NNs are represented as digraphs, with edges as connections and nodes as PEs. 

### Terminology

According to Eberhart (1990), we have 

* input and output patterns, which are represented as vectors
* layers, which are composed of processing elements
* connection weights, which are represented as matrices, in which each dimension usually indicates a layer.

### Input and output patterns

NNs cannot operate unless they have data. How to design the input and the output is a big problem.

### Connections

> Within the digraph representation, connections serve a single purpose: they determine the direction of information flow.

The connection weights 

* are adjused during a learning process that captures information. 
* that are positive-valued are called excitatory
* that are negative-valued are called inhibitory
* that are zero-valued are equivalent to nto having a connection present

It is often desirable for a PE to have an internal bias value, called threshold. 

### Processing elements

...are the portion of the NN where all the computing is performed. PEs can have only one input connection (as in the input layer) or several weighted connections. There are 2 important qualities a PE must possess:

* PEs require only local information
* PEs produce only one input value

These 2 qualities allow NNs to operate in parallel. To compute the output of a PE, we define a function `F(X,W)` where `X` is the vector of outputs from the preceding layer; and `W`, the weights from the previous layer to the PE. 

### PE functions

...map a PE's (possibly) infinite domain to a prespecified range. 

Examples:

* linear PE function: `f(x)=a*x` 
* step PE function:
  ```
  f(x) = if (x >= t) then (b) else (-d)
  ```
  usually `t=0`; `b=1`; and `d=0` or `d=-1`
* ramp PE function
* sigmod PE function
* gaussian PE function

Neural network topologies
-------------------------

Terminology:

* layers
* intralayers X interlayer connections
* feedfoward X feedback connections

### Instars, Outstars and the ADALINE

...

### Single-layer networks

...