import numpy
import spectro

if __name__ == '__main__':
    fs = 200
    time = numpy.arange(0, 10, 1.0/fs)
    waves = [
        numpy.sin(  2*numpy.pi*time),
        numpy.sin(40*2*numpy.pi*time),
        numpy.sin(30*2*numpy.pi*time),
        numpy.sin(2*2*numpy.pi*time)
    ]
    sinewave = numpy.concatenate(waves)
    signals = { 'sine': sinewave }
    spectro.generate_plots(signals)
