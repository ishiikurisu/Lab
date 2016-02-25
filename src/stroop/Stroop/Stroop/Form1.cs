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
    public partial class Form1 : Form
    {
        private string TestType = "random";

        public Form1()
        {
            InitializeComponent();
        }

        private void comboType_SelectedIndexChanged(object sender, EventArgs e)
        {
            var combo = sender as ComboBox;
            var type = combo.SelectedText.ToLower();
            var flag = textHowLong.Enabled;

            switch (type)
            {
                case "from file":
                    TestType = type;
                    flag = !flag;
                    break;

                case "random":
                    TestType = type;
                    break;

                default:
                    break;
            }

            textHowLong.Enabled = flag;
            textWhere.Enabled = !flag;
            buttonSelect.Enabled = !flag;
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            var form = new FormStroop();
            int howLong = -1;
            string source = "";

            if (TestType == "from file")
            {
                SetSource(out source);
            }
            else
            {
                source = TestType;
                // Converting text to miliseconds
                // howLong = 60000 * int.Parse(textHowLong.Text);
            }

            form.setTest(source, howLong);
            form.setMother(this);
            form.Show();
            Hide();
        }

        private void SetSource(out string source)
        {
            source = textWhere.Text;
        }

    }
}
