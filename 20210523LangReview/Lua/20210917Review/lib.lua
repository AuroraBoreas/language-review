local lib = {}

function lib.var_demo()
    print("\n=== var demo ===\n")
    local a = 42
    local b; b = 3.14
    local c = true
    local d = "hello world"
    print(string.format("%s, type: %s", a, type(a)))
    print(string.format("%s, type: %s", b, type(b)))
    print(string.format("%s, type: %s", c, type(c)))
    print(string.format("%s, type: %s", d, type(d)))
end

lib.func_demo = function()
    print("\n=== func demo ===\n")

    local function fibonacci(n)
        if n < 2 then
            return 1
        else
            return fibonacci(n-1) + fibonacci(n-2)
        end
    end

    local function factorial(n)
        if n < 2 then
            return 1
        else
            return n * factorial(n-1)
        end
    end

    local function mysum(n)
        return n * (n+1) / 2
    end

    local function getOne()
        local i = 0
        return function ()
            i = i + 1
            return i
        end
    end
    
    local function bigsum(...)
        local rv = 0
        for _, v in pairs{...} do
            rv = rv + v
        end
        return rv
    end
    print(string.format("fibonacci(10) : %s", fibonacci(10)))
    print(string.format("factorial(10) : %s", factorial(10)))
    print(string.format("mysum(10) : %s", mysum(10)))
    print(string.format("bigsum(1, 2, 3, 5) : %s", bigsum(1, 2, 3, 5)))

    local g = getOne()
    for _ = 1, 3, 1 do
        print(string.format("i = %s", g()))
    end
end

function lib.statement_demo()
    print("\n=== statement demo ===\n")
    local a = 42; local b = 69
    -- A
    print(string.format("a = %s, b = %s; a + b = %s", a, b, a + b))
    print(string.format("a = %s, b = %s; a - b = %s", a, b, a - b))
    print(string.format("a = %s, b = %s; a * b = %s", a, b, a * b))
    print(string.format("a = %s, b = %s; a / b = %s", a, b, a / b))
    print(string.format("a = %s, b = %s; a %% b = %s", a, b, a % b))
    -- R
    print(string.format("a = %s, b = %s; not a = %s", a, b, not a))
    print(string.format("a = %s, b = %s; a and b = %s", a, b, a and b))
    print(string.format("a = %s, b = %s; a or b = %s", a, b, a or b))
    -- L
    print(string.format("a = %s, b = %s; a == b = %s", a, b, a == b))
    print(string.format("a = %s, b = %s; a ~= b = %s", a, b, a ~= b))
    print(string.format("a = %s, b = %s; a > b = %s", a, b, a > b))
    print(string.format("a = %s, b = %s; a >= b = %s", a, b, a >= b))
    print(string.format("a = %s, b = %s; a < b = %s", a, b, a < b))
    print(string.format("a = %s, b = %s; a <= b = %s", a, b, a <= b))
    -- A
    local Person = {
        name="",
        age =0,
    }
    print(Person.age)
    
    --B
    local c;
    c = a << 2
    print(string.format("a = %s, b = %s; a << 2 : %s", a, b, c))
    c = a >> 2
    print(string.format("a = %s, b = %s; a >> 2 : %s", a, b, c))
    c = a and b
    print(string.format("a = %s, b = %s; a & b = %s", a, b, c))
    c = a or b
    print(string.format("a = %s, b = %s; a | b = %s", a, b, c))
    c = a ^ b
    print(string.format("a = %s, b = %s; a ^ b = %s", a, b, c))

    -- A
    local x = 3.14
    print(x)
    -- Cast
    -- Op for storage
    -- Op for other
end

function lib.controlflow_demo()
    print("\n=== controlflow demo ===\n")
    
    local function isEven(n)
        if n % 2 == 0 then
            return true
        end
        return false
    end

    print(string.format("isEven(3), %s", isEven(3)))
end

function lib.loop_demo()
    print("\n=== loop demo ===\n")
    local numbers = {1, 2, 3, 4, 5}
    for i = 1, #numbers, 1 do
        io.write(string.format("%s ", numbers[i]))
    end
    print()
    
    local i = #numbers
    while i > 0 do
        io.write(string.format("%s ", numbers[i]))
        i = i - 1
    end
    print()

    i = 1
    repeat
        io.write(string.format("%s ", numbers[i]))
        i = i + 1
    until i > #numbers
    print()
end

function lib.class_demo()
    print("\n=== class demo ===\n")
    local Animal = {
        name="anonymous",
        age=1,
        sex="male",
    }
    function Animal:new(name, age, sex)
        setmetatable({}, Animal)
        self.name = name
        self.age = age
        self.sex = sex
        return self
    end
    
    function Animal:toString()
        return string.format("name=%s\nage=%s\nsex=%s\n", self.name, self.age, self.sex)
    end

    local a1 = Animal:new("fluffy", 2, "male")
    print(a1:toString())

    local Dog = Animal:new()
    function Dog:new(name, age, sex, food)
        setmetatable({}, Animal)
        self.name = name
        self.age = age
        self.sex = sex
        self.food = food
        return self
    end

    function Dog:toString()
        return string.format("name=%s\nage=%s\nsex%s\nfood=%s\n", self.name, self.age, self.sex, self.food)
    end
    local d1 = Dog:new("json", 3, "female", "pizza")
    print(d1:toString())
end

function lib.metatable_demo()
    print("\n=== metatable demo ===\n")
    local mt = {
        __add = function (table1, table2)
            local rv = {}
            for i = 1, #table1, 1 do
                if (table1[i] ~= nil) and (table2[i] ~= nil) then
                    rv[i] = table1[i] + table2[i]
                else
                    rv[i] = 0
                end
            end
            return rv
        end,

        __eq = function (table1, table2)
            return table1.values == table2.values
        end
    }

    local numbers = {1, 2, 3, 4, 5}
    setmetatable(numbers, mt)
    local merged = numbers + numbers
    print(table.concat(merged, ", "))
    print(numbers == merged)

end

function lib.fileio_demo()
    print("\n=== fileio demo ===\n")
    local file = io.open("lua.csv", "w+")
    file:write("Eiusmod Lorem sint eiusmod ipsum duis consequat ut.\n")
    file:write("Reprehenderit labore proident eiusmod enim magna duis sunt dolor.\n")
    file:seek("set", 0)
    print(file:read("a"))
    file:close()
end

function lib.coroutine_demo()
    print("\n=== coroutine demo ===\n")

    local co1 = coroutine.create(function (last)
        for i = 1, last, 1 do
            print(i)
            if i == 6 then
                coroutine.yield(co1)
                print(coroutine.status(co1))
            end
        end
    end)

    local co2 = coroutine.create(function (last)
        for i = 101, last, 1 do
            print(i)
        end
    end)

    print(coroutine.status(co1))
    coroutine.resume(co1, 10)
    coroutine.resume(co2, 120)
    print(coroutine.status(co1))
    print(coroutine.status(co2))
end

return lib