using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BeckInventory
{
    public partial class FormInventory : Form
    {
        private DataAcessLayer DAL { get; set; }
        private Form Parent { get; set; }
        private string[] Questions { get; set; }
        private int Index;
        private int Score;

        public FormInventory()
        {
            this.DAL = new DataAcessLayer(@"assets\inventory.txt");
            InitializeComponent();
        }

        public void SetParent(Form parent)
        {
            Parent = parent;
        }

        public void Start()
        {
            Questions = DAL.Load();
            Index = Score = 0;
            SetQuestions();
            Parent.Hide();
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

            return result;
        }

        private void ShowResults()
        {
            FormResult form = new FormResult();
            form.SetScore(Score);
            form.SetParent(Parent);
            form.Show();
            this.Close();
        }
    }
}

