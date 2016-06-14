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
    public partial class FormRank : Form
    {
        public Form Mother { get; set; }
        public List<string> Goals { get; set; }

        public FormRank()
        {
            InitializeComponent();
            WindowState = FormWindowState.Maximized;
        }

        public void SetGoals(string[] goals)
        {
            Goals = new List<string>(goals);
            UpdateGoals();
        }

        private string[] CollectGoals()
        {
            int limit = Lines.Length;
            string[] goals = new string[limit];

            for (int i = 0; i < limit; ++i)
            {
                goals[i] = Lines[i].GetGoal();
            }

            return goals;
        }

        private void buttonContinue_Click(object sender, EventArgs e)
        {
            FormGoal form = new FormGoal();
            form.Mother = Mother;
            form.Goals = CollectGoals();
            form.Instruct();
            Close();
        }
    }
}
