import java.io.IOException;
import java.io.FileWrite;
import java.io.BufferedWriter;

public class Single
{
	private String inputFile;

	public Single(String inputFile)
	{
		Analyzer analyzer = new Analyzer(inputFile);
		this.inputFile = inputFile;

		try {
			analyzer.analyze();
			this.write(analyzer.getData());
		}
		catch (Exception any) { 
			System.out.println(any);
		}
	}

	public void write(double[] data)
	throws IOException
	{
		BufferedWriter BW = new BufferedWriter(new FileWriter(inputFile + ".yml"));
		String toWrite;

		toWrite = "RT: " + data[0];
		BW.write(toWrite, 0, toWrite.length());
		BW.newLine();

		toWrite = "SSD: " + data[1];
		BW.write(toWrite, 0, toWrite.length());
		BW.newLine();

		toWrite = "SSRT: " + data[2];
		BW.write(toWrite, 0, toWrite.length());
		BW.newLine();

		toWrite = "%I: " + data[3];
		BW.write(toWrite, 0, toWrite.length());
		BW.newLine();

		toWrite = "%A: " + data[4];
		BW.write(toWrite, 0, toWrite.length());
		BW.newLine();

		BW.flush();
		BW.close();
	}
}