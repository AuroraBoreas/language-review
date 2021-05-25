/*
a simple module demonstrates closure mechnsim in JavaScript

@ZL, 20210525

[ expriment result ]
- by default, JavaScript has exactly same behavior (access local variable) like swift

*/

function func(n) {
    let total = 0;
    const f = ()=>{
        total += n;
        return total;
    }
    return f;
}

let f = func(10);

console.log("1st call, ", f());
console.log("2nd call, ", f());
console.log("3rd call, ", f());