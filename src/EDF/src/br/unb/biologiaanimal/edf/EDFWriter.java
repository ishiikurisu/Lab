package br.unb.biologiaanimal.edf;

import java.util.HashMap;
import java.nio.ByteBuffer;
import java.io.BufferedWriter;


/**
 * The class to write EDF information in an standard way
 */
class EDFWriter
{
    private HashMap header;
    private HashMap records;

    /**
     * Creates a new writer for this EDF file depiected in these variables
     * @param header the header of the EDF file
     * @param records the records in the file, tagged by their label
     */
    public EDFWriter(HashMap head, HashMap shoulders)
    {
        header = head;
        records = shoulders;
    }

    /**
     * Writes data to file in the ASCII format. Beware with side effects!
     * @param filePath the path to the chosen file
     */
    public void toAscii(String filePath)
    {

    }

    public static String sayHi()
    {
        return "Hello from EDF Writer!";
    }
}
