using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Stroop.Controller;

namespace Stroop
{
    public partial class FormStroop : Form
    {
        private string TestType { get; set; }
        private int Duration { get; set; }
        private Form Subject { get; set; }
        private Form Mother { get; set; }
        private bool Begun { get; set; }
        private Controller.Controller Exam { get; set; }

        public FormStroop()
        {
            InitializeComponent();
            Subject = new FormSubject();
            Begun = false;
        }

        public void setMother(Form mother)
        {
            Mother = mother;
        }

        public void setTest(string testType, int howLong)
        {
            if (testType == "random")
            {
                Exam = new ControllerRandom(howLong);
            }
            else
            {
                Exam = new ControllerChosen(TestType);
            }
        }

        protected override void OnShown(EventArgs e)
        {
            base.OnShown(e);
            Subject.Show();
        }

        private void buttonNext_Click(object sender, EventArgs e)
        {
            if (Begun)
            {
                // store time elapsed
                // get next image
                // restart clock
            }
            else
            {
                Begun = true;
            }
        }
    }
}
