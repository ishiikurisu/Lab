using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BeckInventory
{
    class DataAcessLayer
    {
        public string Path { get; private set; }

        public DataAcessLayer()
        {

        }

        public DataAcessLayer(string path)
        {
            Path = path;
        }

        public string[] Load()
        {
            List<string> data = new List<string>();

            using (var serial = new StreamReader(Path))
            {
                for (var line = serial.ReadLine(); line != null; line = serial.ReadLine())
                {
                    data.Add(line);
                }
            }

            return data.ToArray<string>();
        }
    }
}
