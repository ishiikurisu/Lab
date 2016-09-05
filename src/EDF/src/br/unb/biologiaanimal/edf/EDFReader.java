package br.unb.biologiaanimal.edf;

import java.io.FileInputStream;
import java.io.IOException;

class EDFReader
{
    private String path;
    private String data;
    private FileInputStream stream;

    public EDFReader(String input)
    {
        byte[] buffer = new byte[256];
        this.path = input;

        try {
            stream = new FileInputStream(path);
            // TODO Actually read and parse file
            stream.read(buffer);
            data = new String(buffer);
        }
        catch (Exception any) {
            System.out.println(any);
        }
    }

    public String getPath()
    {
        return this.path;
    }

    public String getData()
    {
        return this.data;
    }
}
