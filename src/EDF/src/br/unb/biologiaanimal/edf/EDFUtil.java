package br.unb.biologiaanimal.edf;

public class EDFUtil
{
	/**
	 * Separates a String in an equal number of parts
	 * @param inlet the String to be divided
	 * @param numChops the number of chops to be done
	 * @return the chopped string
	 */
	public static String[] separateString(String inlet, int numChops)
	{
		String[] outlet = new String[numChops];
		int step = inlet.length() / numChops;

		for (int i = 0; i < numChops; ++i)
		{
			outlet[i] = inlet.substring(i*step, (i+1)*step);
		}

		return outlet;
	}
}