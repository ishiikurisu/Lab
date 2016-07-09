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
    public partial class FormGoal : Form
    {
        public string[] Goals { get; set; }
        private bool Ended { get; set; }
        private string[] Questions { get; set; }
        private Queue<int> Answers { get; set; }
        public Form1 Mother { get; set; }
        private FormText Instructions { get; set; }
        private int CurrentGoal { get; set; }
        private int CurrentQuestion { get; set; }

        public FormGoal()
        {
            InitializeComponent();
            Ended = false;
            WindowState = FormWindowState.Maximized;
            CurrentGoal = CurrentQuestion = 0;
            Answers = new Queue<int>();
            Questions = DataAccessLayer.LoadLines(DataAccessLayer.AssetsPath + 
                                                  "AnswerSheetQuestions.txt");
        }

        public void Instruct()
        {
            Instructions = new FormText();
            Instructions.Text = DataAccessLayer.LoadText(DataAccessLayer.AssetsPath +
                                                         "QuestionnaireText.txt");
            Instructions.HowToProceed(this.StartTest);
            Instructions.Show();
        }

        private void StartTest(object sender, EventArgs e)
        {
            NextStep();
            Show();
            Instructions.Close();
        }

        private void buttonContinue_Click(object sender, EventArgs e)
        {
            CollectData();
            if (CurrentQuestion % Questions.Length == 0)
                CurrentGoal++;
            NextStep();
        }

        private void NextStep()
        {
            if (CurrentGoal == Goals.Length)
            {
                Ended = true;

                // Save data
                DataAccessLayer.SaveLines(string.Format("{0}{1}.txt", 
                                                        DataAccessLayer.ResultsPath,
                                                        Mother.Subject), 
                                          this.FormatData());

                // Finish test
                var form = new FormThanks();
                form.Mother = Mother;
                form.Show();
                Close();
            }
            else
            {
                // Setup next question
                labelGoal.Text = string.Format("Objetivo\n{0}", FormatGoal(Goals[CurrentGoal]));
                labelQuestion.Text = Questions[(CurrentQuestion++) % Questions.Length];
            }
        }

        private string FormatGoal(string inlet)
        {
            int lowerBound = 0;
            while (inlet[lowerBound++] != ':') ;
            return inlet.Substring(lowerBound + 1);
        }

        private void CollectData()
        {
            // Add life area to answer
            Answers.Enqueue(GetAnswer());
        }

        private string[] FormatData()
        {
            // thinking about this, maybe I should
            // separate this function from the rest
            // of the class?
            List<string> outlet = new List<string>();
            int dutyCycle = Answers.Count / Goals.Length;

            foreach (var goal in Goals)
            {
                outlet.Add(goal);
                for (int i = 0; i < dutyCycle; i++)
                {
                    outlet.Add(Questions[i]);
                    outlet.Add(Answers.Dequeue().ToString());
                }
            }

            return outlet.ToArray<string>();
        }
    }
}
