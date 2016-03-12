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
        private int NoQuestions { get; set; }
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
            string[] raw = DAL.Load(DAL.GetInventoryPath(Test));
            NoQuestions = int.Parse(raw[0]);
            Questions = Rest(raw);
            Answers = new int[Questions.Length/NoQuestions];
            Index = Score = 0;
            CreateRows();
            SetQuestions();
            Mother.Hide();
        }

        private void SetQuestions()
        {
            foreach (var label in Labels)
            {
                label.Text = Questions[Index++];
            }
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

            foreach (var radio in Radios)
            {
                if (radio.Checked)
                    break;
                else
                    result++;
            }

            Answers[(Index-1) / NoQuestions] = result;
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

