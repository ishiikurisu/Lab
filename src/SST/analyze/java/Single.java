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

		BW.write("RT: " + data[0]);
		BW.newLine().;

		BW.flush();
		BW.close();
	}
}