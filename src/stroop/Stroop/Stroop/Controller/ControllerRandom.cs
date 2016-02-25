using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stroop.Controller
{
    class ControllerRandom : Controller
    {
        private int Duration { get; set; }

        public ControllerRandom(int howLong)
        {
            Duration = howLong;
        }

    }
}
