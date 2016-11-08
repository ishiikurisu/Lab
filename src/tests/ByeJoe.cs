using System;
using System.Linq;

namespace ByeJoe
{
	public class ByeJoe
	{	
		public static void Main()
		{
			string[] letters = new string[] { "J", "o", "e" };
			string word = letters.Aggregate("", (acc, x) => string.Format("{0}{1}", acc, x));
			Console.WriteLine(word);
		}
	}
}
