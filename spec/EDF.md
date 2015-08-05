# [The specification](http://www.edfplus.info/specs/edf.html)

One data file contains one uninterrupted digitized polygraphic recording. A data file consists of a header record followed by data records. The variable-length header record identifies the patient and specifies the technical characteristics of the recorded signals. The data records contain consecutive fixed-duration epochs of the polygraphic recording.

The first 256 bytes of the header record specify the version number of this format, local patient and recording identification, time information about the recording, the number of data records and finally the number of signals (ns) in each data record. Then for each signal another 256 bytes follow in the header record, each specifying the type of signal (e.g. EEG, body temperature, etc.), amplitude calibration and the number of samples in each data record (from which the sampling frequency can be derived since the duration of a data record is also known). In this way, the format allows for different gains and sampling frequencies for each signal. The header record contains 256 + (ns * 256) bytes. Figure 1 shows its detailed format.

The information in the ASCII strings must be left-justified and filled out with spaces. Midnight time is 00:00:00. The duration of each data record is recommended to be a whole number of seconds and its size (number of bytes) is recommended not to exceed 61440. Only if a 1s data record exceeds this size limit, the duration is recommended to be smaller than 1s (e.g. 0.01).

The digital minimum and maximum of each signal should specify the extreme values that can occur in the data records. These often are the extreme output values of the A/D converter. The physical (usually also physiological) minimum and maximum of this signal should correspond to these digital extremes and be expressed in the also specified physical dimension of the signal. These 4 extreme values specify offset and amplification of the signal.

Following the header record, each of the subsequent data records contains 'duration' seconds of 'ns' signals, with each signal being represented by the specified (in the header) number of samples. In order to reduce data size and adapt to commonly used software for acquisition, processing and graphical display of polygraphic signals, each sample value is represented as a 2-byte integer in 2's complement format. Figure 1 shows the detailed format of each data record.

Gains, electrode montages and filters should remain fixed during the recording. Of course, these may all be digitally modified during replay of the digitized recording.
Below is the detailed digital format of the header record (upper block, ascii's only) and of each subsequent data record (lower block, integers only). Note that each one of the ns signals is characterized separately in the header.

## HEADER RECORD (we suggest to also adopt the 12 simple additional EDF+ specs)

+ 8 ascii : version of this data format (0)
+ 80 ascii : local patient identification (mind item 3 of the additional EDF+ specs)
+ 80 ascii : local recording identification (mind item 4 of the additional EDF+ specs)
+ 8 ascii : startdate of recording (dd.mm.yy) (mind item 2 of the additional EDF+ specs)
+ 8 ascii : starttime of recording (hh.mm.ss)
+ 8 ascii : number of bytes in header record
+ 44 ascii : reserved
+ 8 ascii : number of data records (-1 if unknown, obey item 10 of the additional EDF+ specs)
+ 8 ascii : duration of a data record, in seconds
+ 4 ascii : number of signals (ns) in data record
+ ns * 16 ascii : ns * label (e.g. EEG Fpz-Cz or Body temp) (mind item 9 of the additional EDF+ specs)
+ ns * 8 ascii : ns * physical dimension (e.g. uV or degreeC)
+ ns * 80 ascii : ns * transducer type (e.g. AgAgCl electrode)
+ ns * 8 ascii : ns * physical minimum (e.g. -500 or 34)
+ ns * 8 ascii : ns * physical maximum (e.g. 500 or 40)
+ ns * 8 ascii : ns * digital minimum (e.g. -2048)
+ ns * 8 ascii : ns * digital maximum (e.g. 2047)
+ ns * 80 ascii : ns * prefiltering (e.g. HP:0.1Hz LP:75Hz)
+ ns * 8 ascii : ns * nr of samples in each data record
+ ns * 32 ascii : ns * reserved

## DATA RECORD

+ nr of samples[1] * integer : first signal in the data record
+ nr of samples[2] * integer : second signal
+ ..
+ ..
+ nr of samples[ns] * integer : last signal

# [Additional specifications in EDF+](http://www.edfplus.info/specs/edfplus.html)

1. In the header, use only printable US-ASCII characters with byte values 32..126.
2. The 'startdate' and 'starttime' fields in the header should contain only characters 0-9, and the period (.) as a separator, for example "02.08.51". In the 'startdate', use 1985 as a clipping date in order to avoid the Y2K problem. So, the years 1985-1999 must be represented by yy=85-99 and the years 2000-2084 by yy=00-84. After 2084, yy must be 'yy' and only item 4 of this paragraph defines the date.
3. The 'local patient identification' field must start with the subfields (subfields do not contain, but are separated by, spaces):
  - the code by which the patient is known in the hospital administration.
  - sex (English, so F or M).
  - birthdate in dd-MMM-yyyy format using the English 3-character abbreviations of the month in capitals. 02-AUG-1951 is OK, while 2-AUG-1951 is not.
  - the patients name.
Any space inside the hospital code or the name of the patient must be replaced by a different character, for instance an underscore. For instance, the 'local patient identification' field could start with: MCH-0234567 F 02-MAY-1951 Haagse_Harry. Subfields whose contents are unknown, not applicable or must be made anonymous are replaced by a single character 'X'. Additional subfields may follow the ones described here.
4. The 'local recording identification' field must start with the subfields (subfields do not contain, but are separated by, spaces):
  - The text 'Startdate'.
  - The startdate itself in dd-MMM-yyyy format using the English 3-character abbreviations of the month in capitals.
  - The hospital administration code of the investigation, i.e. EEG number or PSG number.
  - A code specifying the responsible investigator or technician.
  - A code specifying the used equipment.
Any space inside any of these codes must be replaced by a different character, for instance an underscore. The 'local recording identification' field could contain: Startdate 02-MAR-2002 PSG-1234/2002 NN Telemetry03. Subfields whose contents are unknown, not applicable or must be made anonymous are replaced by a single character 'X'. So, if everything is unknown then the 'local recording identification' field would start with: Startdate X X X X. Additional subfields may follow the ones described here.
5. 'Digital maximum' must be larger than 'Digital minimum'. In case of a negative amplifier gain the corresponding 'Physical maximum' is smaller than the 'Physical minimum'. Check item 9 on how to apply the 'negativity upward' rule in Clinical Neurophysiology to the physical ordinary signal. 'Physical maximum' must differ from 'Physical minimum'. In case of uncalibrated signals, physical dimension is left empty (that is 8 spaces), while 'Physical maximum' and 'Physical minimum' must still contain different values (this is to avoid 'division by 0' errors by some viewers).
6.  Never use any digit grouping symbol in numbers. Never use a comma "," for a for a decimal separator. When a decimal separator is required, use a dot (".").
7. The ordinary signal samples (2-byte two's complement integers) must be stored in 'little-endian' format, that is the least significant byte first. This is the default format in PC applications.
8. The 'starttime' should be local time at the patients location when the recording was started.
9. Use the standard texts and polarity rules at http://www.edfplus.info/specs/edftexts.html. These standard texts may in the future be extended with further texts, a.o. for Sleep scorings, ENG and various evoked potentials.
10. The 'number of data records' can only be -1 during recording. As soon as the file is closed, the correct number is known and must be entered.
11. If filters (such as HighPass, LowPass or Notch) were applied to the ordinary signals then, preferably automatically, specify them like "HP:0.1Hz LP:75Hz N:50Hz" in the "prefiltering" field of the header. If the file contains an analysis result, the prefiltering field should mention the relevant analysis parameters.
12. The "transducertype" field should specify the applied sensor, such as "AgAgCl electrode" or "thermistor".

## Annotations for text, time-keeping, events and stimuli

This section describes how one of the EDF+ signals can be specially coded to store text annotations, time, events and stimuli. In this way, annotations and events are kept in the same file as the signals that they refer to. The coding is EDF compatible in the sense that old EDF software would simply treat this 'EDF Annotations' signal as if it were a (strange-looking) ordinary signal.

### The 'EDF Annotations' signal

EDF+ data records can (and often do) contain ordinary signals. EDF+ introduces one other kind of signal, in which the values are annotations that can occur at any arbitrary point of time. This signal is identified by giving it (in the EDF+ header) the label 'EDF Annotations'. As in EDF, the 'nr of samples in each data record' field in the header specifies how many 2-byte integers this 'EDF Annotations' signal occupies in each datarecord. But instead of storing 'ordinary signal' samples, those 2-byte integers are filled with characters. The character-bytes are stored byte-by-byte without changing their order. For instance, the text 'abc' is represented by successive byte values 97, 98 and 99 in the 'EDF Annotations' signal. Even if no annotations are to be kept, an EDF+ file must contain at least one 'EDF Annotations' signal in order to specify the starttime of each datarecord (see section 2.2.4). Of course, the label 'EDF Annotations' is not allowed for ordinary signals.

The 'EDF Annotations' signal only has meaningful header fields 'label' and 'nr of samples in each data record'. For the sake of EDF compatibility, the fields 'digital minimum' and 'digital maximum' must be filled with -32768 and 32767, respectively. The 'Physical maximum' and 'Physical minimum' fields must contain values that differ from each other. The other fields of this signal are filled with spaces.

### Time-stamped Annotations Lists (TALs) in an 'EDF Annotations' signal

Text, time-keeping, events and stimuli are coded as text annotations in this 'EDF Annotations' signal.  The annotations are listed in Time-stamped Annotations Lists (TALs) as follows.

Each TAL starts with a time stamp Onset21Duration20 in which 21 and 20 are single bytes with value 21 and 20, respectively (unprintable ASCII characters) and Onset as well as Duration are coded using US-ASCII characters with byte values 43, 45, 46 and 48-57 (the '+', '-',  '.' and '0'-'9' characters, respectively). Onset must start with a '+' or a '-' character and specifies the amount of seconds by which the onset of the annotated event follows ('+') or precedes ('-') the startdate/time of the file, that is specified in the header. Duration must not contain any '+' or '-' and specifies the duration of the annotated event in seconds. If such a specification is not relevant, Duration can be skipped in which case its preceding 21 must also be skipped. Both Onset and Duration can contain a dot ('.') but only if the fraction of a second is specified (up to arbitrary accuracy).

After the time stamp, a list of annotations all sharing the same Onset and Duration may follow. Each annotation is followed by a single 20 and may not contain any 20. A 0-byte (the unprintable ASCII character with byte value 0) follows after the last 20 of this TAL. So the TAL ends with a 20 followed by a 0.

In each data record, the first TAL must start at the first byte of the 'EDF Annotations signal'. Subsequent TALs in the same data record must follow immediately after the trailing 0 of the preceding TAL. A TAL, including its trailing 0, may not overflow into another data record. Each event is annotated only once, even if its duration makes it extend into the time period of other data records. Unused bytes of the 'EDF Annotations' signal in the remainder of the data record are also filled with 0-bytes. Additional 'EDF Annotations' signals may be defined according to the same specification.

For example, if the technician switches off the lights and closes the door 3 minutes after startdate/time, this can be stored as the 28-bytes TAL '+18020Lights off20Close door200' without the quotes. Alternatively, the two events can be stored as two separate shorter TALs '+18020Lights off200+18020Close door200', also without the quotes. The TAL '+1800.22125.520Apnea200' codes a 25.5s apnea that begins 30 minutes and 0.2s after starttime.

### Annotations in a TAL

The part between 20 and the next20 is called one annotation. These annotations may only contain UCS characters (ISO 10646, the 'Universal Character Set', which is identical to the Unicode version 3+ character set) encoded by UTF-8. This encoding is supported by the major operating systems, compilers and applications. The first 127 UCS characters are identical to those in US-ASCII and are encoded in the corresponding single byte values. US-ASCII characters that are represented by byte values 0-31 are allowed in the annotations only if explicitly prescribed by this EDF+ protocol. In order to enable multi-line texts and tables, US-ASCII characters that are represented by byte values 9 (TAB), 10 (LF) and 13 (CR) are allowed in the annotations. The first 65534 characters (the Basic Multilingual Plane: BMP) of the UCS contain virtually all characters used in any language in the world including Asian languages and UTF-8 encodes these in up to three byte-values. Remember that this encoding applies to the 'EDF Annotations' signal only: in the EDF+ header, only US-ASCII characters with byte values 32..126 are allowed.

In order to support automatic averaging and superimposition, identical events or stimuli that occur several times in one file must be coded each time by the same, unique annotation. Annotations (the part between 20 and the next 20) of different events/stimuli (or the same stimulus at a different location) must differ from this unique annotation.

Annotations, for instance stimuli, that are related to information in only one particular data record, must be in that same data record. Even annotations describing events preceding the start of that data record, for instance a pre-interval stimulus must follow the time-keeping annotation.

### Time keeping of data records

Because data records need not be contiguous, the starttime of each data record must be specified in another way. So, the first annotation of the first 'EDF Annotations' signal in each data record is empty, but its timestamp specifies how many seconds after the filestartdate/time that data record starts. So, if the first TAL in a data record reads '+5672020', then that data record starts 567s after the startdate/time of the file. If the data records contain 'ordinary signals', then the starttime of each data record must be the starttime of its signals. If there are no 'ordinary signals', then a non-empty annotation immediately following the time-keeping annotation (in the same TAL) must specify what event defines the starttime of this data record. For example, '+3456.7892020R-wave20 indicates that this data record starts at the occurrence of an R-wave, which is 3456.789s after file start.

The startdate/time of a file is specified in the EDF+ header fields 'startdate of recording' and 'starttime of recording'. These fields must indicate the absolute second in which the start of the first data record falls. So, the first TAL in the first data record always starts with +0.X2020, indicating that the first data record starts a fraction, X, of a second after the startdate/time that is specified in the EDF+ header. If X=0, then the .X may be omitted.

## Analysis results in EDF+

Ideally, all data (signals, annotations, events) recorded in one session using one recording system are in one EDF+ file. Data from the same patient but from other sessions or equipment will usually be kept in separate files. Ideally, all these files have an identical 'Patient identification' field. In this way, accurate synchronicity between signals and events is kept within the files and it is exactly known to what period in which patients life the data apply.

In practice, this will not always be possible. However, it ís easy to maintain synchronicity and patient identification between a recording and data that are derived from that recording. Such derived data can be analysis results such as averages, QRS parameters, peak latencies or sleep stages or simply a subset of the recording. If such analysis results are stored in  EDF+ then this must be done as follows.

If the original recording is in file R.edf (R can be any string), then the derived-file name must be RA.edf in which A can be any string. For instance a PSG would be recorded in file PSG0123_2002.edf and its sleep stage analysis in PSG0123_2002_hyp.edf. Copy the patient-id line (80 characters) from the recorded file into the analysis file.

Make sure that startdate, starttime, and number and duration of datarecords, are correct. So, if the analysis contains a period from 01:05:00 till 01:25:00 of a 24-hour recording that was started on August 2, 1999, 23:00:00hr, then the analysis file should have startdate 03.08.99 and starttime 01.05.00. In this way it is clear that both files refer to one and the same time period in the patient's life. Some viewers (like PolyMan) are then capable of showing the two (or more) files time-synchronized on one screen. Because the analysis may reduce or increase the amount of data, the durations of analysis-file data records and recording-file data records may differ.

Apply suitable scaling factors in such a way that a large part of the available range of -32768 till 32767 for the values of the analysis results is used. If necessary, the scaling factor can be adapted to the dynamic range of the analysis result even after the analysis was done. Put these scaling factors in the header (digital and physical minimum and maximum) of the analysis file. If such scaling is really impossible because the useful dynamic range of the analysis result is too large, but only then, apply the standardized logarithmic transformation to store floating point values. Be aware that old EDF software is not aware of this transformation, and will show the analysis results on a logarithmic scale. So really try scaling first!

If a hypnogram is stored as an ordinary signal, sleep stages W,1,2,3,4,R,M should be coded in the data records as the integer numbers 0,1,2,3,4,5,6 respectively. Unscored epochs should be coded as the integer number 9. If a hypnogram is stored as annotations, use the standard texts.

Automatically document the analysis principle and parameters in the Recording-id and, in case of ordinary signals, also in Label, Transducer type, Physical dimension and Prefiltering fields in the header of the analysis file. 