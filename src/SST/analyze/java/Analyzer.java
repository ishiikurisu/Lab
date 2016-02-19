import java.io.IOException;
import java.io.InputStream;
import java.io.FileReader;
import java.io.BufferedReader;

public class Analyzer
{
	private String inputFile;
	private SSRTCalculator ssrtCalc;
	private double[] data;

	public Analyzer(String inputFile)
	{
		ssrtCalc = new SSRTCalculator();
		this.inputFile = inputFile;
	}

	private String getLine(BufferedReader inlet)
	throws IOException
	{
		String out = inlet.readLine();

		while (out.length() < 10)
		{
			out = inlet.readLine();
		}

		// System.out.println(out);
		return this.ssrtCalc.treatLine(out);
	}

	public void analyze()
	throws IOException
	{
		FileReader fr = new FileReader(this.inputFile);
		BufferedReader in = new BufferedReader(fr);
		String line;

		line = this.getLine(in); // file path
		line = this.getLine(in); // columns
		this.ssrtCalc.getColumns(line);

		while (line.length() > 1)
		{
			this.ssrtCalc.extractData(line);
			line = this.getLine(in);
		}

		this.data = this.ssrtCalc.analyzeData();
		in.close();
		fr.close();
	}

	public double[] getData()
	{
		return this.data;
	}
}
