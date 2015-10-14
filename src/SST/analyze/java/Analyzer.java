import java.io.IOException;
import java.io.InputStream;
import java.io.FileReader;
import java.io.BufferedReader;

public class Analyzer
{
	private inputFile;
	private SSRTCalculator ssrtCalc;
	private double[] data;

	public Analyzer(String inputFile)
	{
		ssrtCalc = new SSRTCalculator();
		this.inputFile = inputFile;
	}

	public void analyze()
	throws IOException
	{
		FileReader FR = new FileReader(this.inputFile);
		BufferedReader inlet = new BufferedReader(FR);
		String line;

		line = inlet.readLine(); // file path
		this.ssrtCalc.getColumns(inlet.readLine());

		line = inlet.readLine();
		while (line.length() > 0)
		{
			this.ssrtCalc.extractData(line);
			inlet.readLine();
		}

		this.data = ssrtCalc.analyzeData();
		inlet.close();
		FR.close();
	}

	public double[] getData()
	{
		return this.data;
	}
}