/*

this module is to demonstrate interface concept in C#

@ZL, 20210526

[ conclusion ]
===
- C# does support interface
===

*/

using System;

namespace TS
{

    interface Pack
    {
        virtual string start();
    }

    class Carton: Pack
    {
        private string m_name = "noname";
        private int m_age = 0;

        public Carton(string name, int age)
        {
            m_name = name;
            m_age = age;
        }

        override string start()
        {
            return "class Carton says hello";
        } 
    }

    class TS
    {
        static void Main(string[] args)
        {
            const Carton c = new Carton("TS", 30);
            System.Console.WriteLine(c.start());
            Console.ReadLine();
        }
    }
}