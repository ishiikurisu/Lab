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
    public partial class FormArea : Form
    {
        public Form Parent { get; set; }

        public FormArea()
        {
            InitializeComponent();

        }

        private void buttonContinue_Click(object sender, EventArgs e)
        {
            Parent.Show();
            Close();
        }
    }
}
