using System;

namespace MetaReview
{
    class TS
    {
        public static void VariableDemo()
        {
            /*
            @ variable
            ===
            * concept: box
            * pattern: TNV
            * feature:
                - primitive types(meta types)
                    $ char
                    $ short
                    $ int
                    $ long

                    $ float
                    $ double
                    $ long double

                    $ [x]byte
                    $ boolean
                    $ [x]decimal

                - type traits(reflect)
                - type conversion
                    $ implicit vs explicit
                    $ downcasting vs upcasting
                    $ narrowing

                - initialization
                    $ resource acquisition is initialization
                    $ copy assignment operator
                    $ copy ctor
                    $ list initialization

                - ByVal, ByRef, ByPtr
                    $ ByVal
                        ~ lvalue
                        ~ rvalue
                    $ ByRef
                        ~ r-ref
                        ~ l-ref
                    $ ByPtr
                        ~ raw pointer
                        ~ array
                        ~ smart pointer

                - variable template
                    $ generic

                - keywords
                    $ storage
                        ~ static
                        ~ const
                            % const and variable
                            % const and pointer
                            % const and function
                            
                        ~ extern
                        ~ register
                        ~ auto
                    
                    $ compile time
                        ~ constexpr
                        ~ string literal

                - parameter vs argument
                    $ argument means actual variable
                    $ parameter means placeholder variable
            ===    
            */ 

            char x0; x0 = 'c';
            short x1 = 123;
            int x2 = 69;
            long x3 = 123456789L;

            float x4 = 2.718281828F;
            double x5 = 3.14;

            byte x6 = 128;
            bool x7 = true;
            decimal x8 = 42.0M;

            System.Console.WriteLine($"x0 = {x0}");
            System.Console.WriteLine($"x1 = {x1}");
            System.Console.WriteLine($"x2 = {x2}");
            System.Console.WriteLine($"x3 = {x3}");
            System.Console.WriteLine($"x4 = {x4}");
            System.Console.WriteLine($"x5 = {x5}");
            System.Console.WriteLine($"x6 = {x6}");
            System.Console.WriteLine($"x7 = {x7}");
            System.Console.WriteLine($"x8 = {x8}");
        }

        private static int Fibonacci(int n)
        {
            return n < 2 ? 1 : Fibonacci(n-1) + Fibonacci(n-2);
        }

        private static int Factorial(int n)
        {
            return n < 2 ? 1: n * Factorial(n-1);
        }

        private static void AddOne1(int n)
        { n++; }

        private static void AddOne2(ref int n)
        { n++; }

        private static void AddOne3(in int n)
        { System.Console.WriteLine($"n = {n}"); }

        private static void AddOne4(out int n)
        { n = 1; }

        private static void ParamsDemo(params int[] arr)
        {
            for(int i=0; i<arr.Length; ++i)
            {
                System.Console.WriteLine($"{i}, {arr[i]}");
            }
        }

        private static int Sum(int x, int y)
        {
            return x + y;
        }

        private static void Hello(string name)
        {
            System.Console.WriteLine($"hello {name}");
        }

        private static void PrintPersonInfo(string name, int age)
        {
            System.Console.WriteLine($"{name} is {age}");
        }

        private static void SayHello(string name, int age)
        {
            System.Console.WriteLine($"say hello to {name}, your age is {age}");
        }
        
        public delegate void FuncPtr(string name, int age);

        public static void FunctionDemo() 
        {
            /*
            @ function
            ===
            * concept: black box
            * pattern: TNP
            * feature:
                - regular
                - [x]anonymous
                - lambda
                - [x]immediate
                
                - function pointer
                - [x]decorator
                - [x]generator
                - [x]nested function
                - class in function

                - return_type
                    $ ByVal
                    $ ByRef
                    $ ByPtr
                
                - func_name
                    $ overload
                    $ operator overload
                    $ function template

                - args
                    $ ByVal
                    $ ByRef
                    $ ByPtr

                - keywords
                    $ inline vs macro
                    $ const
                    $ constexpr
                    $ noexcept
                    $ [[deprecated]]
            ===
            */ 
            
            AddOne4(out int x);
            System.Console.WriteLine($"x = {x}");
            AddOne3(in x);
            System.Console.WriteLine($"x = {x}");
            AddOne2(ref x);
            AddOne1(x);
            System.Console.WriteLine($"x = {x}");

            ParamsDemo(1, 2, 3, 4);
            
            Func<int, int, int> MyFunc = Sum;
            System.Console.WriteLine($"Func<T>, {MyFunc(3, 4)}");
            
            Action<string> MyHello = Hello;
            MyHello("TS");

            FuncPtr f1 = PrintPersonInfo;
            f1("TS", 30);

            FuncPtr f2 = SayHello;
            f2("SCY", 30);

            int[] numbes  = new int[] { 1, 2, 3, 4 };
            IEnumerable<int> NumberQuery = 
            from elem in numbes
            where elem % 2 == 0
            select elem;
            
            foreach(var item in NumberQuery)
            {
                System.Console.WriteLine(item);
            } 
            
        }

        public static void StatementDemo() 
        {
            /*
            @ statement
            ===
            * concept: link
            * pattern: symbol
            * feature:
                - arithmetic
                    $ +, -, *, /, %
                    $ (prefix)++, --; (postfix) ++, --

                - relational
                    $ ==, !=
                    $ >, >=
                    $ <. <=

                - logic
                    $ !
                    $ &&
                    $ ||

                - access
                    $ (*ptr).
                    $ ptr->

                - bitwise
                    $ ~
                    $ <<, >>
                    $ &, |, ^

                - assign
                    $ T var_name = val;
                    $ T var_name(val);
                    $ T var_name{val}
                    $ T var_name = T(val);
                    $ T var_name = T{val}

                - cast
                    $ dynamic_cast
                    $ static_cast
                    $ const_cast
                    $ reinterpret_cast
                    $ C-style cast

                - op
                    $ new
                    $ delete

                - op
                    $ .
                    $ ,
                    $ ;
                    $ ()
                    $ []
                    $ {}
                    $ <>

            ===
            */

        }

        public static void ControlflowDemo() 
        {
            /*
            @ controlflow
            ===
            * concept: branch
            * pattern: branch
            * feature:
                - if...else if...else
                - switch...case...default
                - try...catch...
            ===
            
            */ 

        }

        public static void LoopDemo() 
        {
            /*
            @ loop
            ===
            * concept: circle
            * pattern: circle
            * feature:
                - for(;;)
                - for(:)
                - while
                - do...while 
            ===
            
            */ 
        }

        public static void ClassDemo() 
        {
            /*
            @ class
            ===
            * concept: sim
            * pattern: sim
            * feature:
                - Abstract
                    $ concrete vs abstract

                - Encapsulation
                    $ access privilages
                        ~ private
                        ~ public
                        ~ friend
                        ~ static

                - Inheritance
                    $ is-a
                    $ has-a

                - Polymorphism
                    $ virtual
                    $ =0
                    $ override
                    $ operator

            * structure:
                ^ default ctor
                ^ default dtor
                ^ copy ctor
                ^ copy assignment operator
                ^ move ctor
                ^ move assignment operator

            * principles:
                # SRP
                # OCP
                # LSP
                # ISP
                # DIP
                # Delimiter principle

            * keywords:
                $ default
                $ explicit (operator opol for type conversion)
                $ override
                $ virtual
                $ =0 (abstract vs concret; abstract class is not allowed to create obj in C++)
            
            * privilage:
                % private
                % public
                % friend

            * other:
                & class vs struct vs enum
                & class template
                & dependency injection
                & class in class? 
            ===
            */ 

        }

        public static void DatastructureDemo() 
        {
            /*
            @ datastructure
            ===
            * concept: container
            * pattern: container
            * feature:
                - seq
                    $ array -> fixed size
                    $ vector
                    $ list
                    $ forward_list
                    $ deque

                - adaptor
                    $ stack
                    $ queue
                    $ priority_queue

                - associative
                    $ map
                    $ multimap
                    $ set
                    $ multiset

                - unordered associative
                    $ unordered_set
                    $ unordered_multiset
                    $ unordered_map
                    $ unordered_multimap
            ===
            */ 

        }

        public static void AlgorithmDemo() 
        {
            /*
            @ algorithm
            ===
            * concept: calculation methods
            * pattern: world map of STL algorithm
            * feature:
                - permutation
                - queries
                    ^ value queries
                        $ count
                        $ transform_inclusive_scan
                        $ transform_exclusive_scan
                        $ inclusive_scan
                        $ exclusive_scan

                    ^ property queries
                    ^ search
                    ^ 2-ranges properties

                - secrete runes
                    $ *_n
                    $ *_if
                    $ *_copy
                    $ stable_*
                    $ is_*
                    $ is_*_until

                - movers
                - lone island
                - raw memory 
                - value modifier
                - structure changer
            ===
            */

        }
    }
    
}