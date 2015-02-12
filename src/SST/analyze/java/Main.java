import java.util.List;
import java.util.ArrayList;
import java.io.IOException;
import java.io.File;

public class Main
{
	static private List<String> textFiles(String directory) {
		List<String> textFiles = new ArrayList<String>();
		File dir = new File(directory);

		for (File file : dir.listFiles()) {
			if (file.getName().toLowerCase().endsWith((".txt"))) {
				textFiles.add(file.getName());
			}
			else if (file.getName().toLowerCase().endsWith((".csv"))) {
				textFiles.add(file.getName());
			}
		}

		return textFiles;
	}

	public static void main(String[] args) 
	throws IOException
	{
		String separator = System.getProperty("file.separator");
		List<String> files = textFiles(".");
		Multiple multiple = new Multiple();
		Single single = new Single();

		for (String file: files)
		{
			file = System.getProperty("user.dir") + separator + file;
			multiple.update(single.update(file));
		}

		single.close();
		multiple.close();
	}
}