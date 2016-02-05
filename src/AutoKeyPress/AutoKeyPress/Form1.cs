using System;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AutoKeyPress
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private async void button1_Click(object sender, EventArgs e)
        {
            while (true)
            {
                SendKeys.SendWait("z");
                await Task.Delay(1000);
            }
        }
    }
}
