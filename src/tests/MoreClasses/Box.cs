using System;

namespace MoreClasses
{
	class Box
	{
		public string Tag { get; private set; }
		public string Content { get; private set; }

		public Box()
		{

		}		

		public Box(string tag, string content)
		{
			this.Tag = tag;
			this.Content = content;
		}
	}
}