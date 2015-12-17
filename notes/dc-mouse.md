# DC Mouse

The problem is to make the Neuron-spectrum EEG receive a DC signal from a mouse click.

Initial idea
------------

![circuit](./dc-mouse/dc-mouse.1.png)
Figure 1

We thought that, by clicking the mouse button, we would be able to receive an direct answer from the connection

First analysis
--------------

Mice are weird and work in weird ways. Testing some PS/2 mice, we came to the conclusion the chip that controls the mouse understand a button click as the absence of voltage in a terminal. Therefore, to identify a mouse click, we will have to measure when the button's voltage decrease. Maybe adding a filter to the cables before channeling them to the EEG?

To circumvent this, we will try to add a PNP transistor to the mouse's circuit, so the button will only signal the EEG when it's pressed. In other words, we are 'reversing' its output voltage only for the . The circuit we will attempt is described in figure 2.

![circuit](./dc-mouse/dc-mouse.2.png)
Figure 2
