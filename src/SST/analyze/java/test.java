import java.io.IOException;
import java.io.FileReader;
import java.io.BufferedReader;

public class test
{
	public static void main(String[] args)
	throws IOException
	{
		BufferedReader BR = new BufferedReader(new FileReader("Main.java"));
		String line = BR.readLine();

		while (line != null)
		{
			System.out.println(line);
			line = BR.readLine();
		}

		BR.close();
	}
}