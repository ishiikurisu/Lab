import java.io.*;
import java.util.*;

public class test
{
	static void cat(String bacon)
	{
		System.out.println(bacon);
	}

	static List<String> textFiles(String directory) {
		List<String> textFiles = new ArrayList<String>();
		File dir = new File(directory);

		for (File file : dir.listFiles()) {
			if (file.getName().toLowerCase().endsWith((".java"))) {
				textFiles.add(file.getName());
			}
		}

		return textFiles;
	}

	public static void main(String[] args)
	throws IOException
	{
		BufferedReader BR = new BufferedReader(new FileReader("Main.java"));
		List<String> files = textFiles(System.getProperty("user.dir"));
		String line = BR.readLine();

		System.out.println("---");
		while (line != null)
		{
			System.out.println(line);
			line = BR.readLine();
		}

		cat("---");
		for (int i = 0; i < files.size(); ++i)
		{
			cat(files.get(i));
		}

		cat("...");
		BR.close();
	}
}