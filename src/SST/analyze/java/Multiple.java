import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.util.List;
import java.util.ArrayList;

public class Multiple
{
	private BufferedWriter BW;
	private List<Double> ssrt;
	private List<Double> rt;
	private List<Double> ssd;
	private List<Double> inhib;
	private List<Double> aus;

	private void println(String s)
	throws IOException
	{
		BW.write(s, 0, s.length());
		BW.newLine();
	}

	public Multiple()
	throws IOException
	{
		BW = new BufferedWriter(new FileWriter("multiple.yml"));
		this.println("--- # Multiple");
		this.println("Notes: >");
		this.println("  Esses resultados foram obtidos usando");
		this.println("  a equação `SSRT = <RT> - <SSD>` onde");
		this.println("  `<RT>` é a média de todos os Go RT; e");
		this.println("  `<SSD>` é a média dos SSDs corretos.");

		ssrt = new ArrayList<Double>();
		rt = new ArrayList<Double>();
		ssd = new ArrayList<Double>();
		inhib = new ArrayList<Double>();
		aus = new ArrayList<Double>();
	}

	public void update(double[] data)
	{
		rt.add(data[0]);
		ssd.add(data[1]);
		ssrt.add(data[2]);
		inhib.add(data[3]);
		aus.add(data[4]);
	}

	public void close()
	throws IOException
	{
		this.flush();
		this.println("...");
		BW.flush();
		BW.close();
	}

	private void flush()
	throws IOException
	{
		this.println("<RT>: " + this.mean(this.rt) + 
		              "+-" + stdDeviation(this.rt));
		this.println("<SSD>: " + this.mean(this.ssd) + 
			          "+-" + stdDeviation(this.ssd));
		this.println("<SSRT>: " + this.mean(this.ssrt) + 
			          "+-" + stdDeviation(this.ssrt));
		this.println("<%I>: " + this.mean(this.inhib) + 
			          "+-" + stdDeviation(this.inhib));
		this.println("<%AUS>: " + this.mean(this.aus) + 
			          "+-" + stdDeviation(this.aus));
	}

	private double mean(List<Double> list)
	{
		double result = 0;

		for (Double item: list)
			result += item;

		return result / list.size();
	}

	private double stdDeviation(List<Double> list)
	{
		double mean = this.mean(list);
		double variance = 0;

		for (Double item: list)
			variance += Math.pow(mean - item, 2);

		variance /= list.size();
		return Math.sqrt(variance);
	}
}