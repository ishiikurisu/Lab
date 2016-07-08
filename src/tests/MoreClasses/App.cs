using System;
using System.Linq;
using System.Collections.Generic;

namespace MoreClasses
{
	public class App
	{
		public static void Main()
		{
			var Boxes = new List<Box>();
			var line = Console.ReadLine();

			while (line.Length > 1)
			{
				var stuff = new List<string>(line.Split(new Char[] {':'})
				                                 .Select((item) => Clean(item)));
				Console.WriteLine(string.Format("  {0}\n  {1}", 
					                            stuff.ElementAt(0),
					                            stuff.ElementAt(1)));
				Boxes.Add(new Box(stuff.ElementAt(0), stuff.ElementAt(1)));
				line = Console.ReadLine();
			}

			// TODO: Add class (name it Bird) to retrieve only tags from boxes
		}

		private static string Clean(string inlet)
		{
			int lowerLimit = 0;
			int upperLimit = inlet.Length - 1;

			while (inlet[lowerLimit] == ' ')
			{
				lowerLimit++;
			}

			while (inlet[lowerLimit] == ' ')
			{
				lowerLimit--;
			}

			return inlet.Substring(lowerLimit, upperLimit - lowerLimit + 1);
		}
	}
}