import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;

public class Stopwatch
{
	private String filePath;
	private int[] time;
	private String[] procedure;

	public Stopwatch(String filePath)
	{
		this.filePath = filePath;
		try {
			this.readData();
		}
		catch (IOException any) {

		}
	}

	public int[] getTimes()
	{ return this.time; }
	public String[] getProcedures()
	{ return this.procedure; }

	public void readData()
	throws IOException
	{
		HashMap<String, Integer> index = new HashMap<String, Integer>();
		InputStream iss = new InputStream(this.filePath);
		InputStreamReader isr = new InputStreamReader(iss);
		BufferedReader br = new BufferedReader(isr);
		String rawData = null;
		int i = 0;

		this.times = new int[128];
		this.procedures = new String[128];

		br.readLine(); // read file path
		rawData = br.readLine(); // get index
		index = this.getIndex(rawData);
		for (i = 0; i < 8; ++i)
			br.readLine();

		for (i = 0; i < 128; ++i)
		{
			/* get information from line */
		}

		br.close();
		isr.close();
		iss.close();
	}

	private HashMap<String, Integer> getIndexes(String line)
	{
		HashMap<String, Integer> index = new HashMap<String, Integer>();
		String[] bits = line.split("\t");

		for (int i = 0; i < bits.length(); ++i)
		{
			if (bits[i].compareTo("bullshit") == 0) {
				index.add();
			}
		}

		return index;
	}
}
