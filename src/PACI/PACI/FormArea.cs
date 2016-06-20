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
            try
            {
                CollectData();
            }
            catch (Exception any)
            {
                AskForAtLeastOne();
                return;
            }

            if (Areas.Count > 0)
                NextArea();
            else
                Finish();
        }

        private void AskForAtLeastOne()
        {
            MessageBox.Show("Adicione pelo menos um objetivo.", "Aviso!");
        }
        
        private void CollectData()
        {
            TextBox[] goals = { textGoal0, textGoal1, textGoal2 };
            Queue<string> answers = new Queue<string>();

            goals.Where(goal => goal.Text.Length > 0).ToList()
                 .Select(goal => goal.Text).ToList()
                 .ForEach(answer => answers.Enqueue(answer));

            if (answers.Count > 0)
            {
                answers.ToList().ForEach(answer => Goals.Enqueue(answer));
                goals.ToList().ForEach(goal => goal.Text = "");
            }
            else
            {
                throw new Exception();
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
