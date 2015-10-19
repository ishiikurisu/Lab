import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;

public class Single
{
	private String inputFile;
	private BufferedWriter BW;

	public Single()
	throws IOException
	{
		BW = new BufferedWriter(new FileWriter("individual.yml"));
		this.println("---");
	}

	public void update(String inputFile)
	{
		Analyzer analyzer = new Analyzer(inputFile);
		this.inputFile = inputFile;

		try {
			analyzer.analyze();
			this.write(analyzer.getData());
		}
		catch (Exception any) { 
			any.printStackTrace();
		}

	}

	private void println(String s)
	throws IOException
	{
		BW.write(s, 0, s.length());
		BW.newLine();
	}

	public void write(double[] data)
	throws IOException
	{
		String toWrite;

		this.println(this.extractName(inputFile) + ":");
		this.println("  RT: " + data[0]);
		this.println("  SSD: " + data[1]);
		this.println("  SSRT: " + data[2]);
		this.println("  %I: " + data[3]);
		this.println("  %A: " + data[4]);
		BW.newLine();
	}

	private String extractName(String path)
	{
		String[] bits = path.split("\\\\");

		return bits[bits.length-1].split("\\.")[0];
		// bits = path.split("\\.");
		// path = bits[0];

		// return bits[0];
	}

	public void close()
	throws IOException
	{
		this.println("...");
		BW.flush();
		BW.close();
	}
}