
file = io.open("test.lua", "w+")

file:write("Velit sit commodo aliqua exercitation aute enim id consequat do aliqua do irure.\n")

file:write("Nisi anim dolore Lorem reprehenderit tempor quis minim laborum incididunt ut proident.\n")

file:seek("set", 0)

print(file:read("*a"))

file:close()