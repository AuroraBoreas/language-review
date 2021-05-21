/*

meta js review

@ZL, 20210521

*/ 

class Point {
    _x; _y;

    constructor(x, y) {
        this._x = x;
        this._y = y;
    }

    get X() { return this._x; }
    get Y() { return this._y; }
    set X(val) { this._x = val; }
    set Y(val) { this._y = val; }
    
    ToString() {
        return `Point[${X},${Y}]`;
    }

    Add(other) {
        return new Point(this.X + other.X, this.Y + other.Y);
    }

    Sub(other) {
        return new Point(this.X - other.X, this.Y - other.Y);
    }
}

class Polynomial {
    constructor(...args) {
        this.args = args;
    }

    ToString() {
        return `Polynomial(${this.args})`;
    }
}

class A {
    ToString() {
        return "class A says hi!";
    }
}

class B extends A {
    ToString() {
        return "class B say hi!";
    }
}

exports.Point = Point;
exports.Polynomial = Polynomial;
exports.A = A;
exports.B = B;
