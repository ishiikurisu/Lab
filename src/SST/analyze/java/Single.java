public class Single
{
	private String inputFile;

	public Single(String inputFile)
	{
		Analyzer analyzer = new Analyzer(inputFile);
		this.inputFile = inputFile;
		analyzer.analyze();
	}


}