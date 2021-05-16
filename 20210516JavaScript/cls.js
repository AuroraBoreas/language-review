/*
JavaScript meta-lang review

@ZL, 20210516;

*/ 

class Point {
    _x;
    _y;

    constructor(x, y){
        this._x = x;
        this._y = y;
    }

    get X(){
        return this._x;
    }

    set X(val){
        this._x = val;
    }

    get Y(){
        return this._y;
    }

    set Y(val){
        this._y = val;
    }

    ToString(){
        return `Point[${this.X}, ${this.Y}]`;
    }
}

class A {
    ToString(){
        return 'class A says hello!';
    }
};

class B extends A {

    BigDick(){
        return 'class B says hey!';
    }
};


exports.Point = Point;
exports.A = A;
exports.B = B;

// p1 = new Point(1, 1);
// p2 = new Point(1, 2);

// console.log(p1.ToString())
// console.log(p2.ToString())
