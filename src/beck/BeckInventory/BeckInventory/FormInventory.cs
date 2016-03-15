using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace BeckInventory
{
    public partial class FormInventory : Form
    {
        private Form Mother { get; set; }
        private string Test { get; set; }
        private string Patient { get; set; }
        private int NoQuestions { get; set; }
        private int CurrentQuestion { get; set; }
        private Queue<string> Questions { get; set; }
        private int[] Answers { get; set; }
        private int Score { get; set; }

        public FormInventory()
        {
            InitializeComponent();
        }

        public void SetMother(Form mother)
        {
            Mother = mother;
        }

        public void SetTest(string test)
        {
            Test = test;
        }

        public void SetPatient(string patient)
        {
            Patient = patient;
        }

        public void Start()
        {
            DataAcessLayer DAL = new DataAcessLayer();
            string[] raw = DAL.Load(DAL.GetInventoryPath(Test));
            NoQuestions = int.Parse(raw[0]);
            Questions = new Queue<string>(Rest(raw));
            Answers = new int[Questions.Count/(NoQuestions+1)];
            Score = CurrentQuestion = 0;

            CreateRows();
            SetQuestions();
            Mother.Hide();
        }

        private void SetQuestions()
        {
            labelQuestion.Text = Questions.Dequeue();
            foreach (var label in Labels)
            {
                label.Text = Questions.Dequeue();
            }
        }

        private void buttonContinue_Click(object sender, EventArgs e)
        {
            Score += ExtractScore();

            if (Questions.Count == 0)
                ShowResults();
            else
                SetQuestions();
        }

        private int ExtractScore()
        {
            int result = 0;

            foreach (var radio in Radios)
            {
                if (radio.Checked)
                    break;
                else
                    result++;
            }

            Answers[CurrentQuestion++] = result;
            return result;
        }

        private void ShowResults()
        {
            var form = new FormResult();
            form.SetMother(Mother);
            form.SetTest(Test);
            form.SetPatient(Patient);
            form.SetAnswers(Answers);
            form.SetScore(Score);
            form.Show();
            this.Close();
        }
    }
}

