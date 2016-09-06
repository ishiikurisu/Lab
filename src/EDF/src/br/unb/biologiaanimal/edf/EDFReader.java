package br.unb.biologiaanimal.edf;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;

class EDFReader
{
    private String path;
    private String data;
    private HashMap header;  // <String, String>
    private HashMap records; // <String, Double[]>

    public EDFReader(String input)
    {
        this.path = input;

        try {
            byte[] buffer = new byte[256];
            FileInputStream stream = new FileInputStream(path);
            this.readHeader(stream);
            this.readRecords(stream);
        }
        catch (Exception any) {
            System.out.println(any);
        }
    }

    /* ################
       # LOAD METHODS # 
       ################ */
    /**
     * Reads the header of an EDF file
     * @param stream the file input
     */
    private void readHeader(FileInputStream stream)
    throws IOException
    {
        int limit = EDFConstants.specs.length;
        byte[] buffer;
        String data;
        int i = 0;
        header = new HashMap();

        /* Reading header's header */
        for (i = 0; i < limit; ++i)
        {
            buffer = new byte[EDFConstants.lenghts[i]];
            data = (String) EDFConstants.specs[i];
            if (data != "label") {
                stream.read(buffer);
                header.put(EDFConstants.specs[i], new String(buffer));
            }
            else {
                break;
            }
        }

        /* Reading header's records */
        int numberSignals = getNumberSignals();
        for (i = i; i < limit; ++i)
        {
            buffer = new byte[EDFConstants.lenghts[i]];
            data = "";
            for (int n = 0; n < numberSignals; ++n)
            {
                stream.read(buffer);
                data += new String(buffer);
            }
            header.put(EDFConstants.specs[i], data);
        }
    }

    // TODO Read records
    /**
     * Reads the records of an EDF file
     * @param stream the file input
     */
    private void readRecords(FileInputStream stream)
    throws IOException
    {

    }

    /* AUXILIAR LOAD FUNCTIONS */
    private int getNumberSignals()
    {
        String ns = (String) header.get("numbersignals");
        return Integer.parseInt(ns.trim());
    }

    private int[] getNumberSamples()
    {
        int numberSignals = getNumberSignals();
        int[] numberSamples = new int[numberSignals];
        String rawSamples = (String) header.get("samplesrecord");
        String[] samples = EDFUtil.separateString(rawSamples, numberSignals);

        for (int i = 0; i < numberSignals; ++i)
        {
            numberSamples[i] = Integer.parseInt(samples[i]);
        }

        return numberSamples;
    }

    /* #####################
       # INTERFACE METHODS # 
       ##################### */
    public String getPath()
    {
        return this.path;
    }

    public String getData()
    {
        return header.toString();
    }

    public HashMap getHeader()
    {
        return this.header;
    }

    public HashMap getRecords()
    {
        return this.records;
    }
}
