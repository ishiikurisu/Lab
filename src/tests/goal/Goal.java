import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Goal
{
	static String data;

	public static void main(String[] args) 
	throws IOException
	{
		System.setProperty("file.encoding", "Cp1252");
		setup();
		draw();
	}

	static void setup()
	throws IOException
	{
		BufferedReader inlet = new BufferedReader(
			new InputStreamReader(System.in)
		);
		
		for (String line = inlet.readLine(); 
			 line != null; 
			 data += line + " ", line = inlet.readLine());

		inlet.close();
	}

	static void draw()
	throws IOException
	{
		for (String part: data.split(";"))
			System.out.println("- [ ] " + part);
	}
}