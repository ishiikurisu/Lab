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
        public Form Mother { get; set; }
        private Queue<string> Areas { get; set; }
        private Queue<string> Goals { get; set; }

        public FormArea()
        {
            InitializeComponent();
            WindowState = FormWindowState.Maximized;
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
            FormGoal form = new FormGoal();
            form.Mother = Mother;
            form.Goals = Goals.ToArray<string>();
            form.Instruct();
            Close();
        }
    }
}
