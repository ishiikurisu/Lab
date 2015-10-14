import java.util.List;
import java.util.ArrayList;

public class Main
{
	List<String> textFiles(String directory) {
		List<String> textFiles = new ArrayList<String>();
		File dir = new File(directory);

		for (File file : dir.listFiles()) {
			if (file.getName().toLowerCase().endsWith((".txt"))) {
				textFiles.add(file.getName());
			}
		}

		return textFiles;
	}

	public static void main(String[] args) {
		List<String> files = textFiles(".");
		Single single;

		for (String file: files)
		{
			single = new Single(file);
			/* what the fuck do I do now? */
		}
	}
}