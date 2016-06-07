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
        private Queue<string> Areas { get; set; }
        private Queue<string> Goals { get; set; }

        public FormArea()
        {
            InitializeComponent();
            Areas = new Queue<string>(DataAccessLayer.LoadLines(DataAccessLayer.AssetsPath + 
                                                                "Matters.txt"));
            Goals = new Queue<string>();
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
            // TODO: Use correct ranking algorithm
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
            DataAccessLayer.SaveLines(DataAccessLayer.ResultsPath + "temp.txt",
                                      Goals.ToArray<string>());
            Parent.Show();
            Close();
        }
    }
}
