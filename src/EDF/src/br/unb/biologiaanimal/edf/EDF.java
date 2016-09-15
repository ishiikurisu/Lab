package br.unb.biologiaanimal.edf;

import java.util.HashMap;
import java.util.Set;

/**
 * The class to hold the EDF file information.
 */
public class EDF
{
    private String file;
    private EDFReader reader;

    /**
     * Generates new EDF object based on the filepath.
     * @param filePath the path to the file. Can be relative or absolute.
     */
    public EDF(String filePath)
    {
        this.file = filePath;
        this.reader = new EDFReader(file);
    }

    /* ###############
       # GETS & SETS #
       ############### */
    /**
     * Gets the file path.
     */
    public String getFile()
    {
        return reader.getPath();
    }

    /**
     * Generic method to get some data. For testing purposes only.
     */
    public String getData()
    {
        String outlet = "";
        String channel = "EEG Cz-A1";
        byte[] record = reader.getRecord(channel);
        short[] data = EDFUtil.convert(record);
        double convertionFactor = getConvertionFactor(channel);

        for (int i = 0; i < data.length; ++i)
        {
            double value = data[i] * convertionFactor;
            outlet += value + "\n";
        }

        return outlet;
    }

    /**
     * Gets raw EDF header
     */
    public HashMap getHeader()
    {
        return reader.getHeader();
    }

    /**
     * Gets raw EDF records
     */
    public HashMap getRecords()
    {
        return reader.getRecords();
    }

    /**
     * Get the labels contained in this EDF file
     */
    public String[] getLabels()
    {
        return reader.getLabels();
    }

    /* ###################
       # WRITING METHODS #
       ################### */
    public String write()
    {
        return EDFWriter.sayHi();
    }

    /**
     * Formats the read records into the ASCII format and saves it into memory.
     * @param filePath the path to the file to be written.
     */
    public void toAscii(String filePath)
    {
        try {
            EDFWriter writer = new EDFWriter(filePath);
            // TODO Write records in the ASCII format
            writer.write(this.getData());
            writer.close();
        }
        catch (Exception any) {
            System.out.println(any);
        }
    }

    // TODO Enable EDF file to be written in the standard output formats
    // the standard output formats are:
    // - Single ASCII matrix
    // - Multiple ASCII arrays
    // - CSV table

    /* ##########################
       # LABEL SPECIFIC METHODS #
       ########################## */

    /**
     * Gets the index related to a label
     */
    private int getLabelIndex(String label)
    {
        String[] labels = reader.getLabels();
        int limit = reader.getNumberSignals();
        int result = -1;

        for (int i = 0; (i < limit) && (result < 0); ++i)
        {
            if (label.equals(labels[i])) {
                result = i;
            }
        }

        return result;
    }

    /**
     * Gets the convertion factor related to the given label
     * @param label  the channel's label whose convertion factor we want
     * @return the convertion factor
     */
    public double getConvertionFactor(String label)
    {
        return reader.getConvertionFactors()[getLabelIndex(label)];
    }

    public static void main(String[] args)
    {
        System.out.println("Let's work this monster!");
    }
}
