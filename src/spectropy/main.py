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


    # Extracting labels
    fields = labels.split(':')[1]
    chans = int(chan.split(':')[1])

    # Cutting fields in equal parts
    outlet = [ ]
    limit = int(len(fields) / chans)

    for i in range(chans-1):
        outlet.append(fields[i*limit:(i+1)*limit])

    return outlet

if __name__ == '__main__':
    # TODO Get labels
    labels = read_labels()
    print(labels)
    # TODO Save signals
    # TODO Generate spectrogram
    # TODO Save figure on memory
