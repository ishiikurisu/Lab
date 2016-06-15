using System;
using System.Linq;
using System.Text;
using System.IO;

namespace PACI
{
    class DataAccessLayer
    {
        static public string AssetsPath = @".\Assets\";
        static public string ResultsPath = @".\Results\";

        static public string LoadText(string source)
        {
            return File.ReadAllText(source);
        }

        static public string[] LoadLines(string source)
        {
            return File.ReadAllLines(source);
        }

        static public void SaveLines(string output, string[] lines)
        {
            File.WriteAllLines(output, lines);
        }

        static public void DeleteFile(string fileName)
        {
            File.Delete(fileName);
        }
    }
}
