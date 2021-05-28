import cocoa


// @ extension : literally, just like the name means itself;
// & requirement: can NOT override exsiting methods

extension Double {
    var m:  { return self }
    var cm: { return self / 100.0 }
    var mm: { return self / 1_000.0 }
    var km: { return self * 1_000.0 }   
}

let oneInch = 25.5.mm
print("One Inch is \(oneInch) meter.")

let threeKm = 3.0.km
print("three kilometers is \(threeKm) meter.")

// ? why
// ^ just like C#, multiple inheritances are not supported by Swift, to reduce complexiy
// ^ using protocol, extension to achieve the same effect is possible
extension Int {
    func repetitions(_ f: ()->Void) {
        for _ in 0..<3 {
            f()
        }
    }
}

3.repetitions {
    print("hello TS")
}