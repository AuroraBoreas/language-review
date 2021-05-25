using System;


namespace TS
{
    enum Color {
        red,
        green,
        blue
    }

    class TS
    {
        static void Main(string[] args)
        {
            Color r = Color.red;
            switch(r)
            {
                case Color.red:
                    print("red"); break;
                case Color.green:
                    print("green"); break;
                case Color.blue:
                    print("blue"); break;
            }

            Console.ReadLine();
        }
    }
}