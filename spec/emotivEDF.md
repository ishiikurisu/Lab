[Data File Format](http://wiki.emotiv.com/tiki-index.php?page=Data+File+Format)
===============================================================================

Data File Format Introduction
-----------------------------

Data is stored by TestBench in a standard binary format, EDF, which is compatible with various EEG analysis programs, including EEGLab. Following the initial information line, each successive row in the data file corresponds to one data sample, or a 1/128 second slice of data. Each successive row corresponds to each successive time slice. So, for example, one second of data is contained in 128 rows. Each column of the data file corresponds to either an individual sensor location or another information tag.

Descriptive Tags
----------------

The first line, a single information line, contains reference information for the remainder of the file, arranged as information tags. Each tag consists of a tag name, a colon (:), and information separated by one whitespace character.

1. title:Demonstration - This is the title of the file entered in the recording window
2. recorded:16.09.11 10.40.19 - Data and time (local format) of when the recording was started
3. sampling:128 - Sampling rate in samples per second
2; subject:Geoff - Subject ID as entered in the recording window
4. labels:COUNTER  INTERPOLATED AF3 F7 F3 FC5 T7 P7 O1 O2 P8 T8 FC6 F4 F8 AF4 RAW_CQ CQ_AF3 CQ_F7 CQ_F3 CQ_FC5 CQ_T7 CQ_P7 CQ_01 CQ_02 CQ_P8 CQ_T8 CQ_FC6 CQ_F4 CQ_F8 CQ_AF4 CQ_CMS CQ_DRL GYROX GYROY MARKER - These are the headings for each data column (described in more detail below)
5. chan:36 - Count of the total number of information columns in the remainder of the file. (Note: this includes all columns, and is not just limited to EEG data)
6. units:emotiv - Measurement units. One emotiv unit is almost exactly equivalent to one microvolt

Column Headings
---------------

+ Counter: Use this packet counter as a timebase. The counter runs from 0 to 128. (Note that there are a total of 129 counter values. It takes one sample longer than a second to cycle around the full count).

+ Interpolated: This is a flag which shows if a packet was dropped. The value FLAG = 0 means the sample was good.
Raw_CQ: This is a multiplexed conductivity measurement used to derive the contact quality indicator lights. It is possible to demultiplex this channel if more accurate conductivity measurements are required. The multiplexer cycles twice through the electrode in each 128 sample cycle.  

+ CQ_A F3..CQ_A F4: These numbers show the color of the CQ Map indicators, where 0=BLACK, 1 =RED, 2=ORANGE, 4=GREEN.

+ CQ_CMS, CQ_DRL: The colors for the reference locations: RED (1) or GREEN (4).

+ GYROX, GYROY: Horizontal and vertical difference readings since the previous sample.

+ MARKER: Timing markers are manually or automatically entered into the file. If no marker was detected at a particular time, a value of zero is added into the file. Otherwise, the number associated with the specific marker, or the byte transmitted to the COM port, is entered in the MARKER column for that sample

Notes on the Data
-----------------

### DC Offset

EEG data is stored as floating point values directly converted from the unsigned 14-bit ADC output from the headset. This means that the (floating) DC level of the signal occurs at approximately 4200 uV, negative voltages are transmitted as positive values less the average level, and positive voltages are transmitted as positive values greater than the average. In order to remove the DC offset, especially before performing any kind of analysis, such as the Fast Fourier Transform (FFT), it is necessary to apply some kind of DC offset removal.

The simplest method is to subtract the average from the entire data channel, although this method is also the least accurate. Ideally, the user should apply a high-pass filter which matches the characteristics of the electronics.  The user should use a 0.16 Hz first order high-pass filter to remove background signal (this method also removes any longer term drift, which is not achieved by the use of the average subtraction method). Another method is to use an IIR filter to track the background level and subtract that value.  For example, see the MatLab pseudocode below, which assumes the first row has been removed from the array input_data():

``` matlab
IIR_TC = 256;
```

2 second time constant- adjust as required

    EEG_data = input_data( : ,3:16 );

select out only the EEG data

    [rows columns]= size(EEG_data);

rows= number of data samples, columns= 14

    AC_EEG_data = zeros(rows, columns);

reserve space for the output data file

    back= EEG_data( 1, : );

copy the first row of data into the background file

    for r = 2 : rows
        back= (back* ( IIR_TC- 1 ) + EEG_data( r,:)) I IIR_TC;
        AC_EEG_data = EEG_data( r,:)- back;
    end

This demonstration code is not efficient in memory usage and assumes that the entire file is available. The code can be modified to replace the data in the source array rather than making a separate AC-coupled array, and also to run the IIR filter in open-ended form for processing in real time.

Note the vectorized form of the background recalculation at each iteration. Each individual channel background average is retained in the relevant column of "back". At each step, the running average is re-estimated using the new input value. Also note that the first IIR_TC samples are biased towards the initial value, but this settles down after approximately 2 * IIR_TC samples.

It is important to remove the background signal before performing an FFT. The user should also apply a tapered window function such as a HANNING transform before executing the FFT to ensure that there are no wrapping artefacts where the FFT treats the data as an infinitely repeating sequence. Any mismatch between the first and last samples appear as a STEP FUNCTION in the analysis, injecting noise across the spectrum.
