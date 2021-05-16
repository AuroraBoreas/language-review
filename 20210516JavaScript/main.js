/*
JavaScript meta-lang review

@ZL, 20210516;

*/ 

const lib = require('./lib.js')

function main(){
    console.log("\n=== variable ===\n");
    lib.variableDemo();

    console.log("\n=== function ===\n");
    lib.functionDemo();

    console.log("\n=== statement ===\n");
    lib.statementDemo();

    console.log("\n=== controlflow ===\n");
    lib.controlflowDemo();

    console.log("\n=== loop ===\n");
    lib.loopDemo();

    console.log("\n=== class ===\n");
    lib.classDemo();

    console.log("\n=== io ===\n");
    lib.ioDemo();

    console.log("\n=== datastructure ===\n");
    lib.datastructureDemo();

    console.log("\n=== algorithm ===\n");
    lib.algorithmDemo();

}

main();