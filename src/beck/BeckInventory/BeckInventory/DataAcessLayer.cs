using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace BeckInventory
{
    class DataAcessLayer
    {
        public DataAcessLayer()
        {

        }

        public string[] Load(string path)
        {
            List<string> data = new List<string>();

            using (var serial = new StreamReader(path))
            {
                for (var line = serial.ReadLine(); line != null; line = serial.ReadLine())
                {
                    data.Add(line);
                }
            }

            return data.ToArray<string>();
        }

        public void Save(string where, string what)
        {
            File.WriteAllText(where, what);
        }

        public string GetInventoryPath(string test)
        {
            return string.Format("assets\\{0}\\inventory.txt", test);
        }

        public string GetResultsPath(string test)
        {
            return string.Format("assets\\{0}\\results.txt", test);
        }

        public string GenerateResultsPath(string patient, string test)
        {
            return string.Format("results\\{0}_{1}.txt", patient.Split(' ')
                                                                .Aggregate((acc, x) => acc + x),
                                                         test);
        }
    }
}
