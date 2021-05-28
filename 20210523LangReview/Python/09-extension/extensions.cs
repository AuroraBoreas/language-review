/*

C#, extension concept

@ZL, 20210526

*/ 

using System;

namespace TS
{
    public static class StringExtension
    {
        public static int GetWordCounter(string s)
        => s.Split().Length;
    }
    class TS
    {
        static void Main(string[] args)
        {
            string fox = "the quick brown fox jumped over the lazy dogs down " +
            "9876543210 times";
            // ^ behind the scene, compiler will change this line to
            // ^ `int wordCounter = StringExtension.GetWordCounter(fox);`
            int wordCount = fox.GetWordCounter();
            System.Console.WriteLine($"the sentence has {wordCount} words.");
            Console.ReadLine();
        }
    }
}