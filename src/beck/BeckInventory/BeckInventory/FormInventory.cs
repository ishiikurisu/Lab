using System;
using System.Windows.Forms;

namespace BeckInventory
{
    public partial class FormInventory : Form
    {
        private DataAcessLayer DAL { get; set; }
        private Form Mother { get; set; }
        private string Test { get; set; }
        private string Patient { get; set; }
        private string[] Questions { get; set; }
        private int[] Answers { get; set; }
        private int Index;
        private int Score;

        public FormInventory()
        {
            this.DAL = new DataAcessLayer();
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
            Questions = DAL.Load(DAL.GetInventoryPath(Test));
            Answers = new int[Questions.Length/4];
            Index = Score = 0;
            SetQuestions();
            Mother.Hide();
        }

        private void SetQuestions()
        {
            label1.Text = Questions[Index++];
            label2.Text = Questions[Index++];
            label3.Text = Questions[Index++];
            label4.Text = Questions[Index++];
        }

        private void buttonContinue_Click(object sender, EventArgs e)
        {
            Score += ExtractScore();

            if (Index >= Questions.Length)
                ShowResults();
            else
                SetQuestions();
        }

        private int ExtractScore()
        {
            int result = 0;

            if (radio2.Checked)
                result = 1;
            else if (radio3.Checked)
                result = 2;
            else if (radio4.Checked)
                result = 3;

            Answers[(Index-1) / 4] = result;
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

