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
        private string InstructionSource { get; set; }
        private FormText Instructions { get; set; }

        public Form1()
        {
            InitializeComponent();
            this.InstructionSource = "Instructions.txt";
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            Instructions = new FormText();
            Instructions.Text = DataAccessLayer.LoadText(DataAccessLayer.AssetsPath + 
                                                         InstructionSource);
            Instructions.HowToProceed(this.StartTest);
            Instructions.Show();
            this.Hide();
        }

        private void StartTest(object sender, EventArgs e)
        {
            FormArea form = new FormArea();
            Instructions.Close();
            form.Parent = this;
            form.Show();
        }
    }
}
