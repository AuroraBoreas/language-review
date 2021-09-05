import UIKit

func GetInt()->()->Int{
    var i = 0;
    
    func AddOne()->Int{
        i += 1
        return i
    }
    return AddOne
}

let g = GetInt()
for _ in 0...4{
    print(g())
}
