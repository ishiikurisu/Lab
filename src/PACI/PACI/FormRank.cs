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
        public Form1 Mother { get; set; }
        private bool Ended { get; set; }
        public List<string> Goals { get; set; }

        public FormRank()
        {
            InitializeComponent();
            WindowState = FormWindowState.Maximized;
            Ended = false;
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

        private string[] CollectGoalsInOrder()
        {
            int limit = Lines.Length;
            string[] goals = new string[limit];

            for (int i = 0; i < limit; ++i)
            {
                goals[i] = null;
            }

            foreach (var line in Lines)
            {
                var goal = line.GetGoal();
                var rank = int.Parse(line.GetRank()) - 1;

                if (rank >= 0 && rank < limit)
                {
                    if (goals[rank] == null)
                    {
                        goals[rank] = goal;
                    }
                    else
                    {
                        goals = null;
                    }
                }
                else
                {
                    goals = null;
                }

                if (goals == null)
                    break;
            }

            return goals;
        }

        private void buttonContinue_Click(object sender, EventArgs e)
        {
            string[] goals = null;

            if (CheckForValidInput())
            {
                goals = (AreAllEmpty()) ? CollectGoals() :
                                          CollectGoalsInOrder();
            }

            if (goals != null)
            {
                FormGoal form = new FormGoal();
                form.Goals = goals;
                form.Mother = Mother;
                form.Instruct();
                Ended = true;
                this.Close();
            }
            else
            {
                MessageBox.Show("Enumere todos ou nenhum item", "Aviso!");
            }
        }

        private bool CheckForValidInput()
        {
            return AreAllEmpty() || AreAllFilledWithNumbers();
        }
    }
}
