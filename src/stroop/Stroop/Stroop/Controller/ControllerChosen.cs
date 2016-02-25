using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stroop.Controller
{
    class ControllerChosen : Controller
    {
        private string Source { get; set; }

        public ControllerChosen(string source)
        {
            this.Source = source;
        }
    }
}
