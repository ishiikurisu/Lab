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
        private FormText Instructions { get; set; }
        public string Subject { get; private set; }

        public Form1()
        {
            InitializeComponent();
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            Subject = textName.Text;
            Instructions = new FormText();
            Instructions.Text = DataAccessLayer.LoadText(DataAccessLayer.AssetsPath +
                                                         "Instructions.txt");
            Instructions.HowToProceed(this.StartTest);
            Instructions.Show();
            this.Hide();
        }

        private void StartTest(object sender, EventArgs e)
        {
            FormArea form = new FormArea();
            Instructions.Close();
            form.Mother = this;
            form.Show();
        }
    }
}
