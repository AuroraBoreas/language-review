import cocoa
import UIKit

enum Color: CaseIterable {
    case red, green, blue
}

func enumDemo() -> Void {
    print(Color.allCases.count)

    let c: Color = Color.red
    
    switch(c) {
    case .red:
        print("red"); break
    case .green:
        print("green"); break
    case .blue:
        print("blue"); break
    }
}

enumDemo()