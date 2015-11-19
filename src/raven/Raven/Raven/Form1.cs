using System;
using System.Windows.Forms;

namespace Raven
{
    public partial class Form1 : Form
    {
        private Preparador DAL;

        public Form1()
        {
            DAL = new Preparador();
            InitializeComponent();
            PopulateItems();
        }

        private void PopulateItems()
        {
            DAL.CarregarTeste();
            foreach(string item in this.DAL.Testes)
                comboOps.Items.Add(item);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form6Ops f2 = new Form6Ops(DAL.Caminhos[comboOps.SelectedIndex]);
            f2.Show();
            f2.StartTest();
            this.Hide();
        }
    }
}
