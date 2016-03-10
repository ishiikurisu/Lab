using System;
using System.Linq;
using System.Windows.Forms;

namespace BeckInventory
{
    public partial class FormResult : Form
    {
        public Form Mother { get; private set; }
        private string Test { get; set; }
        private string Patient { get; set; }
        private int[] Answers { get; set; }

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

        public void SetPatient(string patient)
        {
            Patient = patient;
        }

        public void SetAnswers(int[] answers)
        {
            Answers = answers;
        }

        public void SetScore(int score)
        {
            DataParser DP;
            DataAcessLayer DAL = new DataAcessLayer();
            string[] results = DAL.Load(DAL.GetResultsPath(Test));
            string result = "";
            int index = 1;

            /* Obtain result */
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

            /* Write answers */
            string[] parts =
            {
                string.Format("Teste: {0}", Test),
                string.Format("Paciente: {0}", Patient),
                string.Format("Pontuação: {0} ponto(s)", score),
                string.Format("Resultado: {0}", result),
                Answers.Aggregate("Respostas:\r\n", 
                                  (acc, x) => string.Format("{0}  {1}. {2}\r\n", acc, index++, x))
            };
            DAL.Save(DAL.GenerateResultsPath(Patient), 
                     parts.Aggregate("", (acc, x) => string.Format("{0}{1}\r\n", acc, x)));
        }

        private void buttonFinish_Click(object sender, EventArgs e)
        {
            Mother.Show();
            this.Close();
        }
    }
}
