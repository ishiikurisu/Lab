import numpy
import matplotlib.pyplot
from scipy import signal as sg
import pylab

def generate_plots(signals):
    for label in signals:
        # generate_plot(label, signals[label])
        calculate_stft(label, signals[label])

def generate_plot(label, signal):
    # TODO Get sampling rate
    fs = 200
    time = numpy.linspace(0, len(signal)/200, len(signal))
    matplotlib.pyplot.plot(time, signal, label = label)
    matplotlib.pyplot.savefig('{0}.png'.format(label))
    matplotlib.pyplot.clf()

# TODO Calculate STFT
def calculate_stft(label, signal):
    # Calculating STFT
    spectrum, time, Sxx = stft(signal, 200)

    # Plotting stuff
    matplotlib.pyplot.pcolormesh(time, spectrum, Sxx, label=label)
    matplotlib.pyplot.savefig('{0}.png'.format(label))
    matplotlib.pyplot.clf()

# From http://stackoverflow.com/questions/2459295/invertible-stft-and-istft-in-python
def stft(x, fs):
    return sg.spectrogram(x, fs=fs)

def istft(X, fs, T, hop):
    x = scipy.zeros(T*fs)
    framesamp = X.shape[1]
    hopsamp = int(hop*fs)
    for n,i in enumerate(range(0, len(x)-framesamp, hopsamp)):
        x[i:i+framesamp] += scipy.real(scipy.ifft(X[n]))
    return x
