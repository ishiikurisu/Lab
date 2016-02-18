using System;
using System.Windows.Forms;

namespace BeckInventory
{
    public partial class FormResult : Form
    {
        public Form Mother { get; private set; }
        private const string Recomendation = "Uma pontuação maior do que 17 persistente indica que você deve procurar um tratamento médico.";
        private string Test { get; set; }

        public FormResult()
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

        public void SetScore(int score)
        {
            DataAcessLayer DAL = new DataAcessLayer();
            string[] results = DAL.Load(DAL.GetResultsPath(Test));
            string result = "Estes altos e baixos são considerados normais.";
            labelScore.Text = string.Format("Você marcou {0} ponto(s).", score);

            if (score >= 11 && score < 17)
                result = "Variação emocional media.";
            else if (score >= 17 && score < 21)
                result = results[0];
            else if (score >= 21 && score < 31)
                result = results[1];
            else if (score >= 31 && score <= 40)
                result = results[2];
            else if (score > 40)
                result = results[3];

            if (score >= 17)
                result += "\n" + Recomendation;

            labelResult.Text = result;
        }

        private void buttonFinish_Click(object sender, EventArgs e)
        {
            Mother.Show();
            this.Close();
        }
    }
}
