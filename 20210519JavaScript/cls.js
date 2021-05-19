/*

JS meta review

@ZL, 20210519

*/ 

class Point{
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
        return `Point[${X},${Y}]`;
    }

    Add(other){
        return new Point(X + other.X, Y + other.Y);
    }

    Sub(other){
        return new Point(X + other.X, Y + other.Y);
    }
}

class Base{
    ToString(){
        return `class Base says hi`;
    }
}

class Derived extends Base{
    Greet(){
        return `class Derived says hi`;
    }
}

exports.Point   = Point;
exports.Base    = Base;
exports.Derived = Derived;
