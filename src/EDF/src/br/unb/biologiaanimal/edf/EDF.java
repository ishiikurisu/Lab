package br.unb.biologiaanimal.edf;

public class EDF
{
    private String file;
    private EDFReader reader;

    public EDF(String filePath)
    {
        this.file = filePath;
        this.reader = new EDFReader(file);
    }

    public String getFile()
    {
        return reader.getPath();
    }

    public String getData()
    {
        return reader.getData();
    }

    public static void main(String[] args)
    {
        System.out.println("Let's work this monster!");
    }
}
