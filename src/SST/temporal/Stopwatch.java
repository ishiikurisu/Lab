import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;

public class Stopwatch
{
	private String filePath;
	private int[] time;
	private boolean[] answer;
	private String[] procedure;
	private HashSet<String> neededFields;

	public Stopwatch(String filePath)
	{
		this.filePath = filePath;
		this.neededFields = this.getNeededFields();
		this.time = new int[128];
		this.procedure = new String[128];
		this.answer = new boolean[128];

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
	public boolean[] getAnswers()
	{ return this.answer; }
	private HashSet<String> getNeededFields()
	{
		HashSet<String> fields;

		fields.add("PressStimulus.RT");
		fields.add("PressStimulus.ACC");
		fields.add("SoundStimulus.RT");
		fields.add("SoundStimulus.ACC");
		fields.add("VisualStimulus.Duration");
		fields.add("Procedure[Trial]");

		return fields;
	}

	private HashMap<String, Integer> getIndex(String line)
	{
		HashMap<String, Integer> index = new HashMap<String, Integer>();
		String[] bits = line.split("\t");
		String bit;

		for (int i = 0; i < bits.length(); ++i)
		{
			if (this.neededFields.contains(bits[i])) {
				index.add(bits[i], i);
			}
		}

		return index;
	}

	public void readData()
	throws IOException
	{
		HashMap<String, Integer> index = new HashMap<String, Integer>();
		InputStream iss = new InputStream(this.filePath);
		InputStreamReader isr = new InputStreamReader(iss);
		BufferedReader br = new BufferedReader(isr);
		int i = 0;

		br.readLine(); // read file path
		index = this.getIndex(br.readLine()); // get index
		for (i = 0; i < 8; ++i)
			br.readLine();

		for (i = 0; i < 128; ++i)
			this.processLine(br.readLine(), i);

		br.close();
		isr.close();
		iss.close();
	}

	private void processLine(String rawData, int numberLine)
	{
		String[] data = rawData.split("\t");
		String procedure = data[this.index.get("Procedure[Trial]")];
		boolean answer = true;
		int time = 0;

		if (procedure.compareTo("PressProc") == 0) {
			time = Integer.parseInt(data[this.index.get("PressStimulus.RT")]););
			answer = (data[this.index.get("PressStimulus.ACC")].compareTo("0") == 0)? false : true;
		}
		else if (procedure.compareTo("NotPressProc") == 0) {
			time = Integer.parseInt(data[this.index.get("SoundStimulus.RT")]););
			answer = (data[this.index.get("SoundStimulus.ACC")].compareTo("0") == 0)? false : true;
		}
		
		this.procedure[numberLine] = procedure;
		this.answer[numberLine] = answer;
		this.time[numberLine] = time;
	}
}
