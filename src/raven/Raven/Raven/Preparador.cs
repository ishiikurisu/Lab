using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Raven
{
    public class Preparador
    {
        public string[] Caminhos { get; private set; }
        public string[] Testes { get; private set; }
        private string CaminhoAtual { get; set; }

        public Preparador()
        {
            CaminhoAtual = @"C:\Users\cris\Documents\work\EEG\src\raven\Raven\Raven\";
        }

        public void CarregarTeste()
        {
            StreamReader file = new StreamReader(this.CaminhoAtual + "versions.txt");
            List<string> paths = new List<string>();
            List<string> tests = new List<string>();

            for (string line = file.ReadLine(); line != null; line = file.ReadLine())
            {
                string[] data = line.Split(' ');
                paths.Add(data[0]);
                tests.Add(data[1]);
            }

            this.Caminhos = paths.ToArray();
            this.Testes = tests.ToArray();
        }

        public void CarregarOpcoes()
        {

        }
    }
}
