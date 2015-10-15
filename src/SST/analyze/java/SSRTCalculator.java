import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.TreeSet;

public class SSRTCalculator
{
	private HashMap<String, Integer> columns;
	private TreeSet<String> neededColumns;
	private ArrayList<Integer> times;
	private ArrayList<Boolean> answers;
	private ArrayList<String> procedures;
	private int totalRT = 0;
	private int sucessfulReactions = 0;
	private int totalReactions = 0;
	private int totalSSD = 0;
	private int sucessfulStops = 0;
	private int totalStops = 0;
	private double ssrt = 0;
	private double rt = 0;
	private double ssd = 0;
	private double inhib = 0;
	private double aus = 0;

	public SSRTCalculator()
	{
		this.neededColumns = new TreeSet<String>();

		neededColumns.add("PressStimulus.RT");
		neededColumns.add("PressStimulus.ACC");
		neededColumns.add("SoundStimulus.RT");
		neededColumns.add("SoundStimulus.ACC");
		neededColumns.add("VisualStimulus.Duration");
		neededColumns.add("Procedure[Trial]");
	}

	public void getColumns(String line)
	{
		String[] bits = line.split("\\t");

		this.columns = new HashMap<String, Integer>();
		for (int i = 0; i < bits.length; ++i)
			if (this.neededColumns.contains(bits[i]))
				columns.put(bits[i], i);
	}

	public String treatLine(String line)
	{
		String out = new String();

		for (int c = 0; c < line.length(); c++)
			if (line.charAt(c) != 0)
				out += line.charAt(c);

		return out;
	}

	public void extractData(String line)
	{
		String[] bits = line.split("\\t");
		int time = 0;
		int acc = 0;
		String bit;
		String procedure = bits[this.columns.get("Procedure[Trial]")];

		if (procedure.equals("PressProc")) {
			bit = bits[this.columns.get("PressStimulus.RT")];
			time = Integer.parseInt(bit);
			bit = bits[this.columns.get("PressStimulus.ACC")];
			acc = Integer.parseInt(bit);

			++this.totalReactions;
			this.sucessfulReactions += acc;
			this.totalRT += time;

			this.procedures.add(procedure);
			this.times.add(time);
			this.answers.add((acc != 0)? true : false);
		}
		else if (procedure.equals("NotPressProc")) {
			bit = bits[this.columns.get("VisualStimulus.Duration")];
			time = Integer.parseInt(bit);
			bit = bits[this.columns.get("SoundStimulus.ACC")];
			acc = Integer.parseInt(bit);

			++this.totalStops;
			this.sucessfulStops += acc;
			this.totalSSD += (acc != 0)? time : 0;

			bit = bits[this.columns.get("SoundStimulus.RT")];
			time = Integer.parseInt(bit);
			this.procedures.add(procedure);
			this.times.add(time);
			this.answers.add((acc != 0)? true : false);
		}
	}

	public double[] analyzeData()
	{
		double[] data = new double[4];

		this.rt = ((double) totalRT) / this.totalReactions;
		this.ssd = ((double) totalSSD) / sucessfulStops;
		this.ssrt = this.rt - this.ssd;
		this.inhib = ((double) sucessfulStops) / totalStops;

		data[0] = this.rt;
		data[1] = this.ssd;
		data[2] = this.ssrt;
		data[3] = this.inhib;
		data[4] = this.getAusences();

		return data;
	}

	public double getRT()
	{
		return this.rt;
	}

	public double getSSD()
	{
		return this.ssd;
	}

	public double getSSRT()
	{
		return this.ssrt;
	}

	public double getInhibition()
	{
		return this.inhib;
	}

	public double getAusences()
	{
		return ((double) this.totalReactions - this.sucessfulReactions) / this.totalReactions;
	}

	public ArrayList<Integer> getTimes()
	{
		return this.times;
	}

	public ArrayList<Boolean> getAnswers()
	{
		return this.answers;
	}

	public ArrayList<String> getProcedures()
	{
		return this.procedures;
	}
}