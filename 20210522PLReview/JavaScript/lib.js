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

}

function statementDemo() {

}

function controlflowDemo() {

}

function loopDemo() {

}

function classDemo() {
    var p1 = new cls.Point();
    console.log(p1.ToString());

    var b1 = new cls.B();
    console.log(`${b1.ToString()}, b1 instanceof cls.A`, b1 instanceof cls.A);
}

function datastructureDemo() {

}

function algorithmDemo() {

}

exports.variableDemo = variableDemo;
exports.functionDemo = functionDemo;
exports.statementDemo = statementDemo;
exports.controlflowDemo = controlflowDemo;
exports.loopDemo = loopDemo;
exports.classDemo = classDemo;
exports.datastructureDemo = datastructureDemo;
exports.algorithmDemo = algorithmDemo;