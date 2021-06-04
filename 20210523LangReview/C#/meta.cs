using System;

using lib = MetaReview;

namespace TS
{
    class TS
    {
        static void Main(string[] args)
        {
            
            Console.WriteLine("\n=== Variable ===");
            lib.VariableDemo();

            Console.WriteLine("\n=== Function ===");
            lib.FunctionDemo();

            Console.WriteLine("\n=== Statement ===");
            lib.StatementDemo();

            Console.WriteLine("\n=== Controlflow ===");
            lib.ControlflowDemo();

            Console.WriteLine("\n=== Loop ===");
            lib.LoopDemo();

            Console.WriteLine("\n=== Class ===");
            lib.ClassDemo();

            Console.WriteLine("\n=== Datastructure ===");
            lib.DatastructureDemo();

            Console.WriteLine("\n=== Algorithm ===");
            lib.AlgorithmDemo();

            Console.ReadLine();
            
        }
    }
}