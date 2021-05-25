using System;

namespace TS
{
    class TS 
    {
        public static void Main(string[] args)
        {
            Func<int> f = func(1);

            Console.WriteLine($"1st call, {0}", f());
            Console.WriteLine($"2nd call, {0}", f());
            Console.WriteLine($"3rd call, {0}", f());
        }

        static Func<int> func(int n)
        {
            int total = 0;
            int inner()
            {
                total += n;
                return total;
            }
            return inner;
        }
    }
}