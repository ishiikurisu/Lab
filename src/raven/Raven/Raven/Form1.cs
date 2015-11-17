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
            this.Hide();
        }
    }
}
