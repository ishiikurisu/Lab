package br.unb.biologiaanimal.edf;

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
        return reader.getData();
    }

    public static void main(String[] args)
    {
        System.out.println("Let's work this monster!");
    }
}
