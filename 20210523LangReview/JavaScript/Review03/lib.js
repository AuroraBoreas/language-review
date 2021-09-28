/*
@ [JavaScript Meta]
---
* Review
* @ZL, 20210917
---
*/

function var_demo() {
    console.log("\n=== var_demo ===\n");
    
    let a = 42;
    var b; b = 2.7182818;
    const c = true;
    let d = "hello world";

    console.log(`a = ${a}, type : ${type(a)}`);
    console.log(`b = ${b}, type : ${type(b)}`);
    console.log(`c = ${c}, type : ${type(c)}`);
    console.log(`d = ${d}, type : ${type(d)}`);
};

function func_demo() {
    console.log("\n=== func_demo ===\n");
    
    function fibonacci(n) {
        return n < 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
    };

    function factorial(n) {
        return n < 2 ? 1 : n * factorial(n-1);
    };

    function _sum(n) {
        return n * (n + 1) / 2;
    };

    function getOne() {
        let i = 0;
        function gen() { return ++i; };
        return gen;
    };

    function bigsum(...args) {
        let rv = 0;
        for(let e of args) {
            rv += e;
        };
        return rv;
    };

    console.log(`fibonacci(10) : ${fibonacci(10)}`);
    console.log(`factorial(10) : ${factorial(10)}`);
    console.log(`_sum(10)      : ${_sum(10)}`);
    console.log(`bigsum(1, 2, 3, 10) : ${bigsum(1, 2, 3, 10)}`);

    let g = getOne();
    for(let i=0; i<3; ++i) {
        console.log(`x = ${g()}`);
    };
};

function statement_demo() {
    console.log("\n=== statement_demo ===\n");

    const x = 42; const y = 69;

    // A
    console.log(`x = ${x}, y = ${y}; x + y = ${x+y}`);
    console.log(`x = ${x}, y = ${y}; x - y = ${x-y}`);
    console.log(`x = ${x}, y = ${y}; x * y = ${x*y}`);
    console.log(`x = ${x}, y = ${y}; x / y = ${x/y}`);
    console.log(`x = ${x}, y = ${y}; x % y = ${x%y}`);
    // R
    console.log(`x = ${x}, y = ${y}; !x = ${!x}`);
    console.log(`x = ${x}, y = ${y}; x && y = ${x&&y}`);
    console.log(`x = ${x}, y = ${y}; x || y = ${x||y}`);
    // L
    console.log(`x = ${x}, y = ${y}; x == y : ${x==y}`);
    console.log(`x = ${x}, y = ${y}; x != y : ${x!=y}`);
    console.log(`x = ${x}, y = ${y}; x > y  : ${x>y}`);
    console.log(`x = ${x}, y = ${y}; x >= y : ${x>=y}`);
    console.log(`x = ${x}, y = ${y}; x < y  : ${x<y}`);
    console.log(`x = ${x}, y = ${y}; x <= y : ${x<=y}`);
    // A
    class Person {
        _name = "";
        _age = 12;
        
        constructor(name, age) {
            this._name = name;
            this._age = age;
        }

        get Name() {
            return this._name;
        }
        
        set Name(val) {
            this._name = val;
        }
        
        tostring() {
            return `name: ${this._name}\nage:${this._age}`;
        }
    }

    let p1 = new Person("ZL", 123);
    console.log(p1.tostring());
    
    // B
    let c = 0;
    c = a << 2;
    console.log(`x = ${x}, y = ${y}; x << 2 : ${c}`);
    c = a >> 2;
    console.log(`x = ${x}, y = ${y}; x >> 2 : ${c}`);
    console.log(`x = ${x}, y = ${y}; x & y  : ${x&y}`);
    console.log(`x = ${x}, y = ${y}; x | y  : ${x|y}`);
    console.log(`x = ${x}, y = ${y}; x ^ y  : ${x^y}`);
    console.log(`x = ${x}, y = ${y}; ~x     : ${~x}`);

    // A
    // Cast
    // Op for storage
    // Op for other
};

function controlflow_demo() {
    console.log("\n=== controlflow_demo ===\n");

    function IsEven(n) {
        return n % 2 == 0;
    };

    function IsLeapYear(year) {
        return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    };

    function SetDate(y, m, d) {
        if (y < 1) { return false; }
        if (m < 1 || m > 12) { return false; }
        if (d < 1 || d > 31) { return false; }
        switch (m) {
            case 2: if(IsLeapYear(y)) {
                        if(d > 29) { return false; }
                    } else {
                        if(d > 28) { return true; }
                    }; 
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(d > 30) { return false; }
                break;
            default:
                break;
        }
        return true;
    }
};

function loop_demo() {
    console.log("\n=== loop_demo ===\n");

    let numbers = new Array();
    for(let i=0; i<10; i++) {
        numbers.push(i);
    }
    
    /// for...of
    for(let e of numbers) {
        console.log(e * e);
    }

    /// for...in
    for(let e in numbers) {
        console.log(e);
    }

    let i = 0;
    while(i < numbers.length) {
        console.log($`{i}, {numbers[i]}`);
        i += 1;
    }

    let i = numbers.length - 1;
    do {
        console.log(numbers[i])
    } while (i >= 0);
    
};

function class_demo() {
    console.log("\n=== class_demo ===\n");

    class Point {
        _x; _y;
        
        constructor(x, y) {
            this._x = x;
            this._y = y;
        };

        get X() { return this._x; };
        set X(val) { this._x = val; };

        get Y() { return this._y; };
        set Y(val) { this._y = val; };
        
        toString() {
            return $`Point({this.X}, {this.Y})`;
        };

        add(rhs) {
            return new Point(this.X + rhs.X, this.Y + rhs.Y);
        };
    };

    class Points {
        _coll;
        
        constructor(coll) {
            this._coll = coll;
        };

        get length() {
            return this.coll.length;
        };

        toString() {
            return this._coll.toString();
        };
    };

    let points = new Points(
        new Point(1, 1),
        new Point(1, 2),
        new Point(2, 1),
        new Point(2, 2),
    );

    console.log($`length of points : {points.length}`);
    console.log(points.toString());
};

function datastructure_demo() {
    console.log("\n=== datastructure_demo ===\n");

    /// array
    let numbers = new Array();
    numbers.push(1);
    numbers.push(2);
    numbers.push(3);
    console.log(numbers.toString());

    /// hashmap
    let m = new Map();
    m.set(1, "ZL");
    m.set(2, "SCY");
    m.set(3, "TS");
    for(let k of m.keys) {
        console.log($`{k}, {m.get(k)}`);
    }

    /// set
    let s = new Set([1, 2, 3, 4, 5, 5]);
    for(let e of s) {
        console.log(e);
    }
};

function algorithm_demo() {
    console.log("\n=== algorithm_demo ===\n");

    function set_union(s1, s2) {
        let tmp = new Set(s1);
        for(let e of s2) {
            if(!s1.has(e)){
                tmp.add(e);
            }
        }
        return tmp;
    };

    function set_intersection(s1, s2) {
        let tmp = new Set(s1);
        for(let e of s2) {
            if(!s1.has(e)) {
                tmp.delete(e);
            }
        }
        return tmp;
    };
    
    function set_difference(s1, s2) {
        let tmp = new Set(s1);
        for(let e of s2) {
            if(s1.has(e)) {
                tmp.delete(e);
            }
        }
        return tmp;
    };

    function set_symmetric_difference(s1, s2) {
        let tmp = new Set(s1);
        for(let e of s2) {
            if(s1.has(e)) {
                tmp.delete(e);
            } else {
                tmp.add(e);
            }
        }
        return tmp;
    };

    let S1 = new Set([1, 2, 3, 4, 5, 5]);
    let S2 = new Set([4, 5, 6, 7, 8, 8]);
    console.log(set_union(S1, S2));
    console.log(set_intersection(S1, S2));
    console.log(set_difference(S1, S2));
    console.log(set_symmetric_difference(S1, S2));
};

exports.var_demo = var_demo;
exports.func_demo = func_demo;
exports.statement_demo = statement_demo;
exports.controlflow_demo = controlflow_demo;
exports.loop_demo = loop_demo;
exports.class_demo = class_demo;
exports.datastructure_demo = datastructure_demo;
exports.algorithm_demo = algorithm_demo;