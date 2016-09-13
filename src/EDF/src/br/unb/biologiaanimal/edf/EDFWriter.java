package br.unb.biologiaanimal.edf;

import java.util.HashMap;
import java.nio.ByteBuffer;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * The class to write EDF information in an standard way
 */
class EDFWriter
{
    private File file;
    private String path;
    private BufferedWriter buffer;

    /**
     * Creates a new writer for this EDF file depiected in these variables
     * @param header the header of the EDF file
     * @param records the records in the file, tagged by their label
     */
    public EDFWriter(String filePath)
    {
        path = filePath;
        try {
            file = new File(path);

            if (!file.exists()) {
                file.createNewFile();
            }

            buffer = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
        }
        catch (IOException any) {
            any.printStackTrace();
        }
    }

    /**
     * Writes data to file in the ASCII format. Beware with side effects!
     * @param data what you want to write in this file
     */
    public void write(String data)
    throws IOException
    {
        buffer.write(data);
    }

    /**
     * Closes the file opened by this EDFWriter
     */
    public void close()
    throws IOException
    {
        buffer.close();
    }

    public static String sayHi()
    {
        return "Hello from EDF Writer!";
    }
}
