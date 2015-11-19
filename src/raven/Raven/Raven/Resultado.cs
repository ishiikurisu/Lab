using System;
using System.Windows.Forms;

namespace Raven
{
    public partial class Resultado : Form
    {
        public Resultado()
        {
            InitializeComponent();
        }

        public Resultado(int noRespostas) : this()
        {
            lblResultado.Text = noRespostas.ToString();
        }

        private void Resultado_Load(object sender, EventArgs e)
        {

        }

        private void btnSair_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btnVoltar_Click(object sender, EventArgs e)
        {
            Form1 f1 = new Form1();
            f1.Show();
            Close();
        }
    }
}
