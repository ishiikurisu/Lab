# Stop Signal Test #

It's a paradigm to study inhibition in mind.

# How to analyze SST data #

We are going to use the mean method (Verbruggen, 2008) to calculate the mean stop-signal response time `<SSRT>`:

    SSRT := <RT> - <SSD>

in which `<RT>` is the mean reaction time; and `<SSD>` is the mean stop-signal delay.

> Therefore, ANALYZE-IT calculates the mean raw RT first (i.e., the mean RT for all no signal trials) and then the mean SSD is subtracted from this value

We are going to use only the `RT`s from the procedures in which the subject must have pressed the button.

> Mean signal-respond RT and mean no-ignal RT are calculated after the removal of incorrect responses (i.e., when the wrong key is pressed).

We need to analyze only the correct answers. In paper, Verbruggen writes he also calculates the percentage of successful stops on stop trials.

## in our case... ##

We are going to extract the following variables from our tables:

+ `PressStimulus.RT` for RT
+ `VisualStimulus.Duration` for SSD
+ `PressStimulus.ACC` for correct answer indicator
+ `SoundStimulus.ACC` for successful stop indicator

For `<RT>`, if `PressStimulus.ACC` is 1, then update a counter for correct answers and the total RT. Divide this total RT by the number of correct answers. For `<SSD>`, if `SoundStimulus.ACC` is true, then update a counter for successful stops, another for the total number of stop trials, and the total SSD; else update just the number of stop trials. Divide the total SSD by the number of successful stop trials and calculate the percentage of inhibition. Subtract `<SSD>` from `<SD>` to get `<SSRT>`.

### File format ###

By exporting the `*.edat2` to what it calls `EXCEL` format, we can open a table with the following format:

+ The first line contains the path of the original `*.edat2` file
+ The second line contains the name of each column divided by `\t` separators.
