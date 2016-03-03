namespace BeckInventory
{
    class DataParser
    {
        private string Inlet { get; set; }
        public int Lowerbound { get; private set; }
        public int Upperbound { get; private set; }
        public string Message { get; private set; }

        public DataParser(string inlet)
        {
            var stuff = inlet.Split(' ');
            Lowerbound = int.Parse(stuff[0]);
            Upperbound = int.Parse(stuff[1]);
            Message = stuff[2];

            for (int i = 3; i < stuff.Length; ++i)
            {
                Message += " " + stuff[i];
            }
        }

    }
}
