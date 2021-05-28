import cocoa
import UIKit

@propertyWrapper
struct Limits {
    private limit: Double

    var wrappedValue: Double {
        get { return self.limit }
        set {
            if newValue < 0.280 || newValue > 0.290 {
                self.limit = 0.280
            } else {
                self.limit = newValue
            }
        }
    }
    
    init() {
        self.limit = 0.0
    }
}