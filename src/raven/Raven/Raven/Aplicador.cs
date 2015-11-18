using System;

namespace Raven
{
    public class Aplicador
    {
        public string NomeTeste { get; private set; }
        public Preparador DAL { get; private set; }
        public string[] Imagens { get; private set; }
        public int NoRespostasCorretas { get; private set; }

        public Aplicador()
        {
            DAL = new Preparador();
        }

        public Aplicador(string nomeTeste) : this()
        {
            this.NomeTeste = nomeTeste;
            DAL.CarregarOpcoes(nomeTeste);
            Imagens = DAL.ImagensPrincipais;
        }

        public string[] CarregarImagens(int rodada)
        {
            return DAL.CarregarImagens(NomeTeste, 
                                       Imagens[rodada], 
                                       DAL.Opcoes[rodada]);
        }

        public void PrepararTeste()
        {
            NoRespostasCorretas = 0;
        }

        public void OuvirResposta(int rodada, int resposta)
        {

        }

    }
}
