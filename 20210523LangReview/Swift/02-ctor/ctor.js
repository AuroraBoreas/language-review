/*

[ expriment result ]
===
- it turns out that JavaScript suppurts ctor inheritance
===
*/ 

class Base {
    m_x;
    constructor(x) {
        this.m_x = x;
    }
}

class Derived extends Base {

}

let d1 = new Derived(1); // OK
console.log(`${d1.m_x}`);