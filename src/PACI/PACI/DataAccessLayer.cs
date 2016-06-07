using System;
using System.Linq;
using System.Text;
using System.IO;

namespace PACI
{
    class DataAccessLayer
    {
        static private string Path = @".\Assets\";

        static public string LoadText(string source)
        {
            return File.ReadAllText(Path + source);
        }

        static public string[] LoadLines(string source)
        {
            return File.ReadAllLines(Path + source);
        }
    }
}
