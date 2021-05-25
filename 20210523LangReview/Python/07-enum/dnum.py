import enum

class Color(enum.Enum):
    red = 1
    green = 2
    blue = 3

if __name__ == "__main__":
    r = Color.red
    if r == Color.red:
        print("red")
    elif r == Color.green:
        print("green")
    elif r == Color.blue:
        print("blue")
    else:
        print("nothing")
    
    for color in Color:
        print(color, color.value)
