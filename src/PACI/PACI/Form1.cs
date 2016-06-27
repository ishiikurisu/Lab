using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PACI
{
    public partial class Form1 : Form
    {
        private FormText Instructions1 { get; set; }
        private FormText Instructions2 { get; set; }
        public string Subject { get; private set; }

        public Form1()
        {
            InitializeComponent();
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            Subject = textName.Text;
            Instructions1 = new FormText();
            Instructions1.Text = DataAccessLayer.LoadText(DataAccessLayer.AssetsPath +
                                                         "Instructions1.txt");
            Instructions1.HowToProceed(this.GiveMoreInstructions);
            Instructions1.Show();
            this.Hide();
        }

        private void GiveMoreInstructions(object sender, EventArgs e)
        {
            Instructions2 = new FormText();
            Instructions2.Text = DataAccessLayer.LoadText(DataAccessLayer.AssetsPath +
                                                          "Instructions2.txt");
            Instructions2.HowToProceed(this.StartTest);
            Instructions2.Show();
            Instructions1.Close();
        }

        private void StartTest(object sender, EventArgs e)
        {
            FormArea form = new FormArea();
            Instructions2.Close();
            form.Mother = this;
            form.Show();
        }
    }
}
