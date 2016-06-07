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
        private string[] Questions { get; set; }
        private Queue<int> Answers { get; set; }
        public Form Mother { get; set; }
        private FormText Instructions { get; set; }
        private int CurrentGoal { get; set; }
        private int CurrentQuestion { get; set; }

        public FormGoal()
        {
            InitializeComponent();
            WindowState = FormWindowState.Maximized;
            CurrentGoal = CurrentQuestion = 0;
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
            ResetQuestion();
            if (CurrentQuestion % Questions.Length == 0)
                CurrentGoal++;
            NextStep();
        }

        private void NextStep()
        {
            if (CurrentGoal == Goals.Length)
            {
                // Finish test
                Mother.Show();
                Close();
            }
            else
            {
                // Setup next question
                labelGoal.Text = Goals[CurrentGoal];
                labelQuestion.Text = Questions[(CurrentQuestion++) % Questions.Length];
            }

        }

        private void ResetQuestion()
        {
            // TODO: Reset question
        }

        private void CollectData()
        {
            // TODO: Collect answer
        }
    }
}
