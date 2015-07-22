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
+ ns * 16 ascii : ns * label (e.g. EEG Fpz-Cz or Body temp) (mind item 9 of the additional EDF+ specs)
+ 4 ascii : number of signals (ns) in data record
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
