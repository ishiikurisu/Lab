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
        public Form1 Mother { get; set; }
        private bool Ended { get; set; }
        private Queue<string> Areas { get; set; }
        private Queue<string> Goals { get; set; }

        public FormArea()
        {
            InitializeComponent();
            WindowState = FormWindowState.Maximized;
            Areas = new Queue<string>(DataAccessLayer.LoadLines(DataAccessLayer.AssetsPath + 
                                                                "Matters.txt"));
            Goals = new Queue<string>();
            Ended = false;
            NextArea();
        }

        private void buttonContinue_Click(object sender, EventArgs e)
        {
            CollectData();
            if (Areas.Count > 0)
                NextArea();
            else
                Finish();
        }
        
        private void CollectData()
        {
            TextBox[] goals = { textGoal0, textGoal1, textGoal2 };
            foreach (var goal in goals)
            {
                Goals.Enqueue(goal.Text);
                goal.Text = "";
            }
        }

        private void NextArea()
        {
            this.labelArea.Text = Areas.Dequeue();
        }

        private void Finish()
        {
            FormRank form = new FormRank();
            form.Mother = Mother;
            form.SetGoals(Goals.ToArray<string>());
            form.Show();
            Ended = true;
            Close();
        }
    }
}
