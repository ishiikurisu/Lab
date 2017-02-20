import numpy
import matplotlib.pyplot
import scipy
import pylab

def generate_plot(label, signal):
    # TODO Get sampling rate
    fs = 200
    time = numpy.linspace(0, len(signal)/200, len(signal))
    matplotlib.pyplot.plot(time, signal, label = label)
    matplotlib.pyplot.savefig('{0}.png'.format(label))
    matplotlib.pyplot.clf()


def generate_plots(signals):
    for label in signals:
        # generate_plot(label, signals[label])
        calculate_stft(label, signals[label])

# TODO Calculate STFT
def calculate_stft(label, signal):
    fs = 200.0
    framesize = 0.05
    hop = framesize/2
    X = stft(signal, fs, framesize, hop)
    pylab.imshow(scipy.absolute(X.T), origin='lower', aspect='auto', interpolation='nearest')
    pylab.savefig('{0}.png'.format(label))
    pylab.clf()

# From http://stackoverflow.com/questions/2459295/invertible-stft-and-istft-in-python
def stft(x, fs, framesz, hop):
    framesamp = int(framesz*fs)
    hopsamp = int(hop*fs)
    w = scipy.hanning(framesamp)
    X = scipy.array([scipy.fft(w*x[i:i+framesamp])
                     for i in range(0, len(x)-framesamp, hopsamp)])
    return X

def istft(X, fs, T, hop):
    x = scipy.zeros(T*fs)
    framesamp = X.shape[1]
    hopsamp = int(hop*fs)
    for n,i in enumerate(range(0, len(x)-framesamp, hopsamp)):
        x[i:i+framesamp] += scipy.real(scipy.ifft(X[n]))
    return x
