package br.unb.biologiaanimal.edf;

class EDFReader
{
    private String path;

    public EDFReader(String input)
    {
        this.path = input;
    }

    public String getPath()
    {
        return this.path;
    }
}
