using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Raven
{
    public partial class Form6Ops : Form
    {
        private Aplicador App { get; set; }
        private PictureBox[] Pics { get; set; }

        public Form6Ops()
        {
            InitializeComponent();
            Pics = new PictureBox[6];

            Pics[0] = picOp1;
            Pics[1] = picOp2;
            Pics[2] = picOp3;
            Pics[3] = picOp4;
            Pics[4] = picOp5;
            Pics[5] = picOp6;
        }

        public Form6Ops(string nomeTeste) : this()
        {
            this.App = new Aplicador(nomeTeste);
        }

        public void StartTest()
        {
            for (int i = 0; i < this.App.Imagens.Length; i++)
            {
                /* Carregar tela */
                DefinirTela(this.App.CarregarImagens(i));

                /* Esperar resposta */
            }
        }

        private void DefinirTela(string[] imagens)
        {
            foreach (string img in imagens)
            {
                Console.WriteLine(img);
            }
        }

        private void picOp3_Click(object sender, EventArgs e)
        {
            
        }
    }
}
