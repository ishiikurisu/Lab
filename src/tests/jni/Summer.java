public class Summer
{
	static {
		System.loadLibrary("Summer");
	}

	public Summer()
	{
	}
	
	public native int sum(int x, int y);
}