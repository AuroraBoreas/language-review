/*
    C++ >= 11, review meta;

    [ c++ meta ]
    ===
    * variable
    * function
    * statement
    * control flow
    * loop
    * class
    * io
    * data structure
    * algorithm
    ====

    @ZL, 20210414

*/


#include <iostream>
#include "meta.h"

int main()
{
    // variable
    {
        /*
        [ variable ]
        ====
        * concept: box
        * pattern: T N V
        * feature:
            - variable template;
            - primitive types;
            - type traits;

            - type conversion;
                -- implicit and explicit
                -- upcasting and downcasting

            - initialization;
                -- list_initializer, {}
                -- ctor, ()
                -- assignment ctor, =
                -- copy ctor,
                -- move ctor, &&
                -- move copy ctor, &&
                -- destructor, ~

            - value, address, pointer;
                -- ByVal, literal
                -- ByRef, &, &&
                -- ByPtr, *, **

        * constraints:
            - const
            - static
            - register
            - auto
            - constexpr
        ====
        */
        variableDemo();
    }

    // function
    {
        /*
        [ function ]
        ====
        * concept: black box
        * pattern: T N P
        * feature:
            - function template;
            - category;
                -- regular function
                -- anonymous function
                -- lambda expr
                -- immediate function
                -- function pointer

            - return_type;
                -- ByVal
                -- ByRef
                -- ByPtr

            - func_name;
                -- overloading
                -- template

            - args;
                -- ByVal
                -- ByRef
                -- ByPtr
                -- Param


        * constraints:
            - const
            - static
            - register
            - auto
            - constexpr
        ====
        */
        functionDemo();
    }

    // statement
    {
        /*
        [ statement ]
        ====
        * concept: symbol
        * pattern: symbol
        * feature:
            - Arithmetic;
                -- precedence

            - Relational;
                -- comparison

            - Logical;
                -- logic

            - Access;
                -- (.)

            - Bitwise;
                -- binary system

            - Assign;

            - Cast;
                -- dynamic_cast
                -- static_cast
                -- const_cast
                -- reinterpret_cast

            - operator for storage;
                -- new
                -- delete
                -- std::memory

            - operator for other
                -- ternary

        * operator overloading;
                -- type conversion
        ====
        */

        statementDemo();
    }

    // control flow
    {
        /*

        [ control flow ]
        ====
        * concept: branch
        * pattern: branch
        * feature:
            - if...else if...else;
            - switch...case...default;
            -- try...catch...finally;
        ====
        */

        controlflowDemo();
    }

    // loop
    {
        /*
        [ loop ]
        ====
        * concept: loop
        * pattern: circle
        * feature:
            - for(;;);
                -- for(;;)
                -- foreach
            - while;

            - do...while;
        ====
        */
        loopDemo();
    }

    // class
    {
        /*

        [ class ]
        ====
        * concept: simulator
        * pattern: simulator
        * feature:
            - Abstract
            - Encapsulation
            - Inheritance
            - Polymorphism

            - SRP
            - OCP
            - LSP
            - ISP
            - DIP

        * keywords:
            - default
            - delete
            - explicit
            - final
            - virtual
            - override
            - =0

        * other:
            -- [x]interface
            -- [x]abstract
        ====
        */
        classDemo();
    }

    // io
    {
        /*

        [ io ]
        ====
        * concept: input or output equipments vs CPU
        * pattern: NA
        * feature:
            - iostream
            - sstream
        ====
        */
    }

    // data structure
    {
        /*
        [ data structure ]
        ====
        * concept: container
        * pattern: container
        * feature:
            - seq;
                -- std::array
                -- std::forward_list
                -- std::list
                -- std::dequeue

            - adapter;
                -- queue
                -- stack
                -- priority queue

            - associative;
                -- set
                -- multiset
                -- map
                -- multimap
        ====
        */
    }

    // algorithm
    {
        /*
        [ algorithm ]
        ====
        * concept: API
        * pattern: API
        * feature:
            - Iterator
                -- const_iterator
                -- iterator

                -- bidirectional iterator
                -- forward_iterator

            - Capacity
                -- length
                -- sizeof

            - Access
            - Modify
            - List observation
            - Bucket
            - Hash policy
        ====
        */
    }

    return 0;
}
