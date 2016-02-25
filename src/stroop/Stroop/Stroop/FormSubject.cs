using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Stroop
{
    public partial class FormSubject : Form
    {
        public FormSubject()
        {
            InitializeComponent();
        }

        private void labelText_Click(object sender, EventArgs e)
        {

        }

        public void setText(string text, string color)
        {
            labelText.Text = text.ToUpper();
        }
    }
}
