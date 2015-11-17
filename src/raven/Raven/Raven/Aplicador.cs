using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Raven
{
    public class Aplicador
    {
        public string NomeTeste { get; private set; }
        public Preparador DAL { get; private set; }

        public Aplicador()
        {
            DAL = new Preparador();
        }

        public Aplicador(string nomeTeste) : this()
        {
            this.NomeTeste = nomeTeste;
        }
    }
}
