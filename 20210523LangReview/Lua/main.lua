local lib = require('lib')
print("hello world!")

print("\n=== variable demo ===")
print(var.name, type(var.name));
io.write("size of string: ", #var.sex, "\n");
io.write("type of age: ", type(var.age), '\n');
io.write("type of deposit: ", type(var.deposit), '\n');
io.write("type of married: ", type(var.married), '\n');
io.write(var.name .. '\n' .. var.longstr);

print("\n=== statement demo ===")
stat.statment_demo()

print("\n=== controlflow demo ===")
cflow.cf()

print("\n=== loop demo ===")
loop.wh()
print()
loop.rp()
loop.fo()
print()
loop.arr()
loop.tbl()
print(string.format('fibonacci(5) = %s', func.fibonacci(5)))
print(string.format('factorial(5) = %s', func.factorial(5)))
print(string.format('sum(5)       = %s', func.sum(5)))

strtbl, n = func.split("Nulla proident proident occaecat laborum eu nisi culpa exercitation magna eu.")

print(table.concat(strtbl, ", "))

print(string.format("paramarray(1, 2, 3, 4, 5) = %s", func.paramarray(1,2,3,4,5)))