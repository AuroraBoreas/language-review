/*

this module is to demonstrate interface concept in JavaScript

@ZL, 20210526

[ conclusion ]
===
- JavaScript does not support interface
- but it does have a walkaround, using class

*/

class Pack {
    start() {}
}

class Carton extends Pack {
    constructor(name, age) {
        super();
        this.name = name;
        this.age =  age;
    }

    start() {
        return "class Carton says hello";
    }
}

let c = new Carton("TS", 30);
print(c.start());