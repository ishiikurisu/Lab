import numpy
import matplotlib.pyplot

def generate_plot(label, signal):
    # TODO Get sampling rate
    fs = 200
    time = numpy.linspace(0, len(signal)/200, len(signal))
    matplotlib.pyplot.plot(time, signal, label = label)
    matplotlib.pyplot.savefig('{0}.png'.format(label))


def generate_plots(signals):
    for label in signals:
        generate_plot(label, signals[label])

# TODO Calculate STFT
