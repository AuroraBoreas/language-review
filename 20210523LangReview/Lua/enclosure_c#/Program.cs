using System;

namespace enclosure_cs
{
    class Program
    {
        public delegate int myDelegate();
        static void Main(string[] args)
        {
            myDelegate g = GetInt();
            for(int i=0; i<5; ++i)
            {
                Console.WriteLine(g());
            }

            Console.ReadLine();
        }

        private static myDelegate GetInt()
        {
            int i = 0;
            return () => { return ++i; };
        }
    }
}
