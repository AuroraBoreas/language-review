/*

JavaScript, meta review

@ZL, 20210522

*/ 


class Point {
    _x;
    _y;

    constructor(x, y) {
        this._x = x;
        this._y = y;
    }

    get X() { return this._x; }
    get Y() { return this._y; }
    set X(val) { this._x = val; }
    set Y(val) { this._y = val; }

    ToString() {
        return `Point[${this.X}, ${this.Y}]`;
    }

    Add(other) {
        return new Point(this.X + other.X, this.Y + other.Y);
    }
}

class A {
    ToString() {
        return "class A says hi";
    }
}

class B extends A {
    ToString() {
        return "class B says hi";
    }
}

exports.Point = Point;
exports.A = A;
exports.B = B;