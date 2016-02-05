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

        public Resultado(int resultado) : this()
        {
            lblResultado.Text = resultado.ToString();
        }

        public Resultado(string resultado) : this()
        {
            lblResultado.Text = resultado;
        }

        public Resultado(string resultado, int noRespostasCorretas) : this(resultado)
        {
            lblNoRespostasCorretas.Text = noRespostasCorretas.ToString();
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

        private void Resultado_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
