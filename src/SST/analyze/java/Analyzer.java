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
		String out = this.ssrtCalc.treatLine(inlet.readLine());
		System.out.println(out);
		inlet.readLine();
		return out;
	}

	public void analyze()
	throws IOException
	{
		BufferedReader in= new BufferedReader(new FileReader(this.inputFile));
		String line;

		line = this.getLine(in); // file path
		line = this.getLine(in); // columns
		this.ssrtCalc.getColumns(line);

		for (int i = 0; i < 8; ++i)
		{
			line = this.getLine(in);
		}

		while (line != null)
		{
			this.ssrtCalc.extractData(line);
			line = this.getLine(in);
		}

		this.data = this.ssrtCalc.analyzeData();
		in.close();
	}

	public double[] getData()
	{
		return this.data;
	}
}