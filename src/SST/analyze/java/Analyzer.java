import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Analyzer
{
	private inputFile;
	private SSRTCalculator ssrtCalc;

	public Analyzer(String inputFile)
	{
		ssrtCalc = new SSRTCalculator();
		this.inputFile = inputFile;
	}

	public void analyze()
	{
		
	}
}