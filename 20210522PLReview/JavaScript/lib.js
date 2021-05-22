/*

JavaScript, meta review

@ZL, 20210522

*/ 

const cls = require('./cls.js');

function variableDemo() {
    
    var x1 = 69;
    console.log(`x1 = ${x1}, type: ${typeof x1}`);
    x1 = Number(69);
    console.log(`x1 = ${x1}, type: ${typeof x1}`);

    let x2 = Boolean(x1); 
    console.log(`x2 = ${x2}, type: ${typeof x2}`);
    
    const pi = 3.14;
    console.log(`pi = ${pi}, type: ${typeof pi}`);
}

function functionDemo() {
    function fibonacci(n) {
        return n < 2? 1 : fibonacci(n-1) + fibonacci(n-2);
    }

    function factorial(n) {
        return n < 2? 1 : n * factorial(n-1);
    }

    console.log(`fibonacci(5) : ${fibonacci(5)}`);
    console.log(`factorial(5) : ${factorial(5)}`);

    const f1 = function(n) {
        return n * n;
    };

    const f2 = (x, y)=>{
        return x * x + y * y;
    };

    console.log(`anonymous function, f1(5): ${f1(5)}`);
    console.log(`lambda expression, f2(5): ${f2(3, 4)}`);

    (function(name){
        console.log(`hello ${name}`);
    })("TS");

    ((...arr)=>{
        let sum = 0;
        for(let elem of arr) {
            sum += elem;
        }
        console.log(`sum : ${sum}`);
    })(1, 2, 3, 4, 5);

    function funcInFunction(n) {
        function* gen(n) {
            for(let i=0; i<n; ++i) {
                yield i;
            }
        }
        let g = gen(n);
        return g;
    }
    
    let i = 0;
    const g = funcInFunction(10);
    while(i < 10) {
        console.log(g.next());
        ++i;
    }
    
    function clsInFunction(name, sex) {
        class Person {
            constructor(name, sex) {
                this.name = name;
                this.sex  = sex;
            }

            ToString() {
                return `name: ${name}, sex: ${sex}`;
            }
        }
        return new Person(name, sex);
    }
    console.log(`${clsInFunction("TS", "female").ToString()}`);
}

function statementDemo() {
    var x = 69, y = 42;
    // a
    console.log(`x = ${x}, y = ${y}; x + y : ${x + y}`);
    console.log(`x = ${x}, y = ${y}; x - y : ${x - y}`);
    console.log(`x = ${x}, y = ${y}; x * y : ${x * y}`);
    console.log(`x = ${x}, y = ${y}; x / y : ${x / y}`);
    console.log(`x = ${x}, y = ${y}; x % y : ${x % y}`);
    // r
    console.log(`x = ${x}, y = ${y}; x == y : ${x == y}`);
    console.log(`x = ${x}, y = ${y}; x != y : ${x != y}`);
    console.log(`x = ${x}, y = ${y}; x > y : ${x > y}`);
    console.log(`x = ${x}, y = ${y}; x >= y : ${x >= y}`);
    console.log(`x = ${x}, y = ${y}; x < y : ${x < y}`);
    console.log(`x = ${x}, y = ${y}; x <= y : ${x <= y}`);
    // l
    console.log(`x = ${x}, !x : ${!x}`);
    console.log(`x = ${x}, y = ${y}; x && y : ${x && y}`);
    console.log(`x = ${x}, y = ${y}; x || y : ${x || y}`);
    // a
    var obj = {
        'name' : 'TS',
        'sex'  : 'female',
        'age'  : 30
    };
    console.log(obj.name, obj.sex, obj.age);
    delete obj.age;
    console.log(obj.age);
    // bitwise
    console.log(`x = ${x}, ~x : ${~x}`);
    x = x << 2;
    console.log(`x = ${x}, x << 2 : ${x}`);
    x = 69;
    x = x >> 2;
    console.log(`x = ${x}, x >> 2 : ${x}`);
    x = 69;
    console.log(`x = ${x}, y = ${y}; x & y : ${x & y}`);
    console.log(`x = ${x}, y = ${y}; x | y : ${x | y}`);
    console.log(`x = ${x}, y = ${y}; x ^ y : ${x ^ y}`);

    // assign
    var z = 3.14;
    console.log(`z : ${z}`);
    z = Number(69);
    console.log(`z : ${z}`);

    // [x]cast
    // [*]op for storage
    // [*]op for other

    var s;
    let i = 69;
    s = i % 2 == 0? "even" : "odd";
    console.log(`s : ${s}`);

}

function controlflowDemo() {
    function isLeapYear(year) {
        return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    }

    function setDate(y, m, d) {
        if(y < 0) { return false; }
        if(m < 0 || m > 12) { return false; }
        if(d < 0 || d > 31) { return false; }
        switch(m) {
            case 2: if(isLeapYear(y)) {
                        if(d > 29) { return false; }
                    } else {
                        if(d > 28) { return false; }
                    }
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(d > 31) { return false; }
        }

        return true;
    }
    console.log(`2021/5/22 is a valid date? setDate(2021, 5, 22): ${setDate(2021, 5, 22)}`);

    function dividZero(x, y) {
        try {
            rv = x / y;
        } catch(ex) {
            console.error(ex);
        } finally {
            console.log('finally clause');
        }
        console.log(rv);
    }

    dividZero(10, 0);
}

function loopDemo() {
    var numbers = [1, 2, 3, 4, 5];
    for(let i=0; i<numbers.length; ++i) {
        console.log(`${i}, ${numbers[i]}`);
    }

    for(let elem of numbers) {
        console.log(elem);
    }

    for(let elem in numbers) {
        console.log(elem, numbers[elem]);
    }

    let i = 0;
    while(i<numbers.length) {
        console.log(numbers[i]);
        ++i;
    }
    i = numbers.length - 1;
    do {
        console.log(numbers[i]);
        i--;
    } while(i >= 0);
}

function classDemo() {
    var p1 = new cls.Point();
    console.log(p1.ToString());

    var b1 = new cls.B();
    console.log(`${b1.ToString()}, b1 instanceof cls.A`, b1 instanceof cls.A);
}

function datastructureDemo() {
    var numbers = [1, 2, 3, 4, 5];
    console.log(numbers);
    numbers.forEach((elem)=>{
        console.log(elem);
    });

    var m1 = new Map();
    m1.set(1, "ZL");
    m1.set(2, "TS");
    m1.set(3, "SCY");
    m1.forEach((k, v)=>{
        console.log(k, v);
    });

    var s1 = new Set();
    s1.add("ZL");
    s1.add("TS");
    s1.add("TS");
    s1.add("TS");
    s1.add("SCY");
    s1.add("ZL");

    s1.forEach((elem)=>{
        console.log(elem);
    });
}

function algorithmDemo() {
    function intersection(A, B) {
        let tmp = new Set(A);
        for(let elem of A) {
            if(!B.has(elem)) {
                tmp.delete(elem);
            }
        }
        return tmp;
    }

    function union(A, B) {
        let tmp = new Set(A);
        for(let elem of B) {
            if(!A.has(elem)) {
                tmp.add(elem);
            }
        }
        return tmp;
    }
    
    function difference(A, B) {
        let tmp = new Set(A);
        for(let elem of B) {
            if(A.has(elem)) {
                tmp.delete(elem);
            }
        }
        return tmp;
    }
    
    function symmetricDifference(A, B) {
        let tmp = new Set(A);
        for(let elem of B) {
            if(A.has(elem)) {
                tmp.delete(elem);
            } else {
                tmp.add(elem);
            }
        }
        return tmp;
    }
    
    var A = new Set([2, 3, 4, 5]);
    var B = new Set([4, 5, 6, 7]);

    console.log('\n--- intersection ---');
    intersection(A, B).forEach((elem)=>{
        console.log(elem);
    })

    console.log('\n--- union ---');
    union(A, B).forEach((elem)=>{
        console.log(elem);
    })

    console.log('\n--- difference ---');
    difference(A, B).forEach((elem)=>{
        console.log(elem);
    })

    console.log('\n--- symmetricDifference ---');
    symmetricDifference(A, B).forEach((elem)=>{
        console.log(elem);
    })
}

exports.variableDemo = variableDemo;
exports.functionDemo = functionDemo;
exports.statementDemo = statementDemo;
exports.controlflowDemo = controlflowDemo;
exports.loopDemo = loopDemo;
exports.classDemo = classDemo;
exports.datastructureDemo = datastructureDemo;
exports.algorithmDemo = algorithmDemo;