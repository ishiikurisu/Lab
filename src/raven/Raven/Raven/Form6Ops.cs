using System;
using System.Diagnostics;
using System.Drawing;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Raven
{
    public partial class Form6Ops : Form
    {
        private Aplicador App { get; set; }
        private PictureBox[] Pics { get; set; }
        private int NoRodada { get; set; }
        private bool Respondeu { get; set; }

        public Form6Ops()
        {
            InitializeComponent();
            Pics = new PictureBox[6];
            this.KeyUp += new KeyEventHandler(this.Form6Ops_KeyUp);

            Pics[0] = picOp1;
            Pics[1] = picOp2;
            Pics[2] = picOp3;
            Pics[3] = picOp4;
            Pics[4] = picOp5;
            Pics[5] = picOp6;
        }

        public Form6Ops(string nomeTeste) : this()
        {
            this.App = new Aplicador(nomeTeste);
        }

        public async void StartTest()
        {
            Stopwatch clock = new Stopwatch();

            this.App.PrepararTeste();
            for (NoRodada = 0; NoRodada < this.App.Imagens.Length; NoRodada++)
            {
                clock.Start();
                DefinirTela(this.App.CarregarImagens(NoRodada));
                await RecebeuResposta();
                clock.Stop();

                App.OuvirDuracao(NoRodada, clock.ElapsedMilliseconds);
                clock.Reset();
            }

            MostrarResultado();
        }

        private void MostrarResultado()
        {
            Resultado R = new Resultado(App.NoRespostasCorretas);
            R.Show();
            Close();
        }

        private void DefinirTela(string[] imagens)
        {
            picMain.Image = Image.FromFile(imagens[0]);
            for (int i = 1; i <= 6; ++i)
            {
                Pics[i - 1].Image = Image.FromFile(imagens[i]);
            }

            Show();
        }

        private void ReceberResposta(int resposta)
        {
            this.App.OuvirResposta(NoRodada, resposta);
        }

        private async Task<string> RecebeuResposta()
        {
            Respondeu = false;

            while (!Respondeu)
            {
                await Task.Delay(10);
            }

            return "Respondido";
        }

        private void Form6Ops_KeyUp(object sender, KeyEventArgs e)
        {
            int resposta = 0;

            switch (e.KeyCode.ToString())
            {
                case "NumPad1":
                    resposta = 1;
                    break;
                case "NumPad2":
                    resposta = 2;
                    break;
                case "NumPad3":
                    resposta = 3;
                    break;
                case "NumPad4":
                    resposta = 4;
                    break;
                case "NumPad5":
                    resposta = 5;
                    break;
                case "NumPad6":
                    resposta = 6;
                    break;
            }

            if (resposta > 0)
            {
                Respondeu = true;
                App.OuvirResposta(NoRodada, resposta);
            }
                
        }

        private void picOp1_Click(object sender, EventArgs e)
        {
            Respondeu = true;
            App.OuvirResposta(NoRodada, 1);
        }

        private void picOp2_Click(object sender, EventArgs e)
        {
            Respondeu = true;
            App.OuvirResposta(NoRodada, 2);
        }

        private void picOp3_Click(object sender, EventArgs e)
        {
            Respondeu = true;
            App.OuvirResposta(NoRodada, 3);
        }

        private void picOp4_Click(object sender, EventArgs e)
        {
            Respondeu = true;
            App.OuvirResposta(NoRodada, 4);
        }

        private void picOp5_Click(object sender, EventArgs e)
        {
            Respondeu = true;
            App.OuvirResposta(NoRodada, 5);
        }

        private void picOp6_Click(object sender, EventArgs e)
        {
            Respondeu = true;
            App.OuvirResposta(NoRodada, 6);
        }
    }
}
