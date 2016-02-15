using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BeckInventory
{
    public partial class FormResult : Form
    {
        public Form Parent { get; private set; }
        private const string Recomendation = "A persistent score of 17 or above indicates that you may need medical treatment.";

        public FormResult()
        {
            InitializeComponent();
        }

        public void SetParent(Form parent)
        {
            Parent = parent;
        }

        public void SetScore(int score)
        {
            string result = "These ups and downs are considered normal.";

            labelScore.Text = string.Format("You scored {0} point(s).", score);

            if (score >= 11 && score < 17)
                result = "Mild mood disturbance.";
            else if (score >= 17 && score < 21)
                result = "Borderline clinical depression.";
            else if (score >= 21 && score < 31)
                result = "Moderate depression.";
            else if (score >= 31 && score <= 40)
                result = "Severe depression.";
            else if (score > 40)
                result = "Extreme depression.";

            if (score >= 17)
                result += "\n" + Recomendation;

            labelResult.Text = result;
        }

        private void buttonFinish_Click(object sender, EventArgs e)
        {
            Parent.Show();
            this.Close();
        }
    }
}
