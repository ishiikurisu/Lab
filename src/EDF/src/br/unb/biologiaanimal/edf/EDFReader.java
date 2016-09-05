package br.unb.biologiaanimal.edf;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;

class EDFReader
{
    private String path;
    private String data;
    private HashMap header; // <String, String>
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

    /* LOAD METHODS */
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
        String ns = (String) header.get("numbersignals");
        int numberSignals = Integer.parseInt(ns.trim());
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
    private void readRecords(FileInputStream stream)
    throws IOException
    {

    }

    /* INTERFACE METHODS  */
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
