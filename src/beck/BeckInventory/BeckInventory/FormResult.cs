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
            DataParser DP;
            string[] results = DAL.Load(DAL.GetResultsPath(Test));
            string result = "";
            labelScore.Text = string.Format("Você marcou {0} ponto(s).", score);

            foreach (var line in results)
            {
                DP = new DataParser(line);
                int lowerbound = DP.Lowerbound;
                int upperbound = DP.Upperbound;
                string message = DP.Message;

                if (score >= lowerbound && score < upperbound)
                {
                    result = message;
                    break;
                }
            }

            labelResult.Text = result;
        }

        private void buttonFinish_Click(object sender, EventArgs e)
        {
            Mother.Show();
            this.Close();
        }
    }
}
