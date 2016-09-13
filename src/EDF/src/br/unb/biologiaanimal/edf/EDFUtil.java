package br.unb.biologiaanimal.edf;

import java.nio.ByteBuffer;

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

	/**
	 * Inserts a byte in a byte array
	 * @param box  the array to contain the new byte
	 * @param it  the byte to be added
	 * @return the new array
	 */
	public static byte[] insert(byte[] box, byte it)
	{
		byte[] newBox;

		if (box == null) {
			newBox = new byte[1];
		}
		else {
			newBox = new byte[box.length + 1];
			for (int i = 0; i < box.length; ++i)
			{
				newBox[i] = box[i];
			}
		}

		newBox[newBox.length-1] = it;
		return newBox;
	}

	/**
	 * Appends a byte array in another byte array
	 * @param box  the array to contain the new byte
	 * @param it  the bytes to be added
	 * @return the concatenated array
	 */
	public static byte[] insert(byte[] inlet, byte[] toAdd)
	{
		byte[] outlet;

		if (inlet == null) {
			outlet = toAdd;
		}
		else {
			outlet = new byte[inlet.length + toAdd.length];
			int j = 0;
			for (int i = 0; i < inlet.length; i++, j++)
			{
				outlet[j] = inlet[i];
			}
			for (int i = 0; i < toAdd.length; i++, j++)
			{
				outlet[j] = toAdd[i];
			}
		}

		return outlet;
	}

    /**
     * Converts a byte array into a short array
     * @param inlet  the array to be converted
     * @return the converted array
     */
    public static short[] convert(byte[] inlet)
    {
        ByteBuffer buffer = ByteBuffer.wrap(inlet);
        int limit = buffer.remaining()/2;
        short[] outlet = new short[limit];

        for (int i = 0; i < limit; ++i)
        {
            outlet[i] = buffer.getShort();
        }

        return outlet;
    }
}
