import spectro

__ABOUT__ = """
This script is a line-filter for generating spectrograms from CSV files.
"""

def read_labels():
    line = input()
    fields = line.split(';')
    labels = ''
    chan = ''

    # Extracting labels field
    for field in fields:
        if field.startswith('labels'):
            labels = field
        if field.startswith('chan'):
            chan = field
        # TODO Get sampling rate


    # Extracting labels
    fields = labels.split(':')[1]
    chans = int(chan.split(':')[1])

    # Cutting fields in equal parts
    outlet = [ ]
    limit = int(len(fields) / chans)

    for i in range(chans-1):
        outlet.append(fields[i*limit:(i+1)*limit])

    return outlet


def build_struct(labels):
    outlet = { }

    for label in labels:
        outlet[label] = [ ]

    return outlet

def save_signals(labels, signals):
    line = input()

    try:
        while line:
            values = line.split(';')
            for i, label in enumerate(labels):
                value = float(values[i])
                signals[label].append(value)
            line = input()
    except EOFError:
        pass

    return signals

if __name__ == '__main__':
    labels = read_labels()
    signals = save_signals(labels, build_struct(labels))
    # print(signals)
    # TODO Generate spectrogram
    # TODO Save figure on memory
    spectro.generate_plots(signals)
