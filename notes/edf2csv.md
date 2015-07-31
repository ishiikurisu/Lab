# CSV format

The CSV format converted from [EDF](http://www.edfplus.info/specs/edf.html)
will consist of 2 parts: a header's block and a record's.
The header is one line containing the information
about the data, and the records will

# Header

The header will contain the following columns:

1. title
2. recorded
3. sampling
4. subject
5. labels
6. chan
7. units

Which are the translations of the following:

+ The `title` will correspond to the local recording identification;
+ `recorded`, to `'%d %d' % (startdate, starttime)`;
+ `sampling`, to the number of samples;
+ `subject`, to the local patient identification;
+ `labels`, to a list of labels separated by spaces;
+ `chan`, to the number of signals; and
+ `units`, to the unit used in this experiment. Since we are using only Emotiv
   gear, we shall use `emotiv` as the unit.

# Records

Each line will contain `chan` fields, each one for its respective
channel, as described in the `labels` section. Therefore, one column
will correspond to one data record of one channel.

```
WE ARE WORKING ON HOW TO CONVERT THE VALUES ON THE EDF FILE
TO THE CSV FILE.
```
