local lib = {}

function lib.var_demo()
    io.write("\n=== var demo ===\n")
    -- ~ [ var demo ]
    -- pattern: T N V
    -- primitive:
        -- number
        -- boolean
        -- string
    -- reflection: type
    -- type conversion:
        -- dynamic_cast
        -- static_cast
        -- const_cast
        -- reinterpret_cast
        -- C-style cast
    -- string interpolation: string.format()
    -- storage:
        -- static
        -- const
        -- auto
        -- register
    -- passing:
        -- ByVal
        -- ByRef
        -- ByPtr
    -- constraints: const
    -- LEGB: local
    -- constness

    local a; a = 42
    local b = 2.718281828
    local c = true
    local d = "hello world"

    io.write(string.format("a = %d, type a : %s\n", a, type(a)))
    io.write(string.format("b = %f, type b : %s\n", b, type(b)))
    io.write(string.format("c = %s, type c : %s\n", c, type(c)))
    io.write(string.format("d = %s, type d : %s\n", d, type(d)))
end

lib.func_demo = function()
    io.write("\n=== function demo ===\n")
    -- ~ [ function demo ]
    -- pattern: T N P
    -- category:
        -- regular
        -- anonymous
        -- lambda
        -- nested function
        -- decorator
        -- generator
        -- class inside function
        -- (generic) function template
        -- delegate
    -- return_type
    -- func_name: overload, overwrite
    -- parameter:
        -- paramarray
        -- position vs keyword
        -- (swift) labels: parameter vs argument
        -- ByVal, ByRef, ByPtr
    -- constness
        -- [[const]] return_type
        -- [[const]] func_name
        -- [[const]] args
    -- keywords:
        -- function
        -- local
        -- global
    
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
        return n * (n + 1) /2
    end

    local function pasum(...)
        local rv = 0
        for _, v in pairs{...} do
            rv = rv + v
        end
        return rv
    end

    local getOne = function()
        local x = 0
        return function ()
            x = x + 1
            return x
        end
    end

    print(string.format("fibonacci(10) = %d", fibonacci(10)))
    print(string.format("factorial(10) = %d", factorial(10)))
    print(string.format("mysum(10) = %f", mysum(10)))
    
    local g = getOne()
    for _ = 1, 3, 1 do
        print(string.format("local x inside function getOne, x = %d", g()))
    end
        
    print(string.format("pasum(1, 2, 3, 10) = %d", pasum(1, 2, 3, 10)))
    
end

function lib.statement_demo()
    -- ~ [statement demo]
    -- Arithmetic
    -- Relational
    -- Logical
    -- Access
    -- Bitwise
    -- Assignment
    -- Cast
    -- Operator for storage
    -- Operator for other

    io.write("\n=== statement demo ===\n")

    local a = 42; local b = 69;
    io.write(string.format("a = %s, b = %s; a + b = %s \n", a, b, a + b))
    io.write(string.format("a = %s, b = %s; a - b = %s \n", a, b, a - b))
    io.write(string.format("a = %s, b = %s; a * b = %s \n", a, b, a * b))
    io.write(string.format("a = %s, b = %s; a / b = %s \n", a, b, a / b))
    io.write(string.format("a = %s, b = %s; a %% b = %s \n", a, b, a % b))

    io.write(string.format("a = %s, b = %s; a == b : %s \n", a, b, a == b))
    io.write(string.format("a = %s, b = %s; a ~= b : %s \n", a, b, a ~= b))
    io.write(string.format("a = %s, b = %s; a > b  : %s \n", a, b, a > b))
    io.write(string.format("a = %s, b = %s; a >= b : %s \n", a, b, a >= b))
    io.write(string.format("a = %s, b = %s; a < b  : %s \n", a, b, a < b))
    io.write(string.format("a = %s, b = %s; a <= b : %s \n", a, b, a <= b))
    
    io.write(string.format("a = %s, b = %s; not a = %s \n", a, b, ~a))
    io.write(string.format("a = %s, b = %s; a and b = %s \n", a, b, a and b))
    io.write(string.format("a = %s, b = %s; a or b = %s \n", a, b, a or b))
    
    local Dog = {name="woof", age=1}
    function Dog:new(name, age)
        setmetatable({}, Dog)
        self.name = name
        self.age = age
        return self
    end
    function Dog:toString()
        return string.format("name = %s, age = %d", self.name, self.age)
    end
    
    local d1 = Dog:new("fluffy", 2)
    print(d1.name, d1.age)
    
    local c; c = a << 2
    io.write(string.format("a = %s, b = %s; a << 2 : %s \n", a, b, c))
    c = a >> 2
    io.write(string.format("a = %s, b = %s; a >> 2 : %s \n", a, b, c))
    c = ~a
    io.write(string.format("a = %s, b = %s; ~a : %s \n", a, b, c))
    c = a and b
    io.write(string.format("a = %s, b = %s; a and b : %s \n", a, b, c))
    c = a or b
    io.write(string.format("a = %s, b = %s; a or b : %s \n", a, b, c))
    c = a ^ b
    io.write(string.format("a = %s, b = %s; a ^ b : %s \n", a, b, c))
end

function lib.controlflow_demo()
    -- ~ [controlflow]
    -- if...else if...else
    -- [x]switch...case...default
    -- [x]try...catch...except...finally
    io.write("\n=== controlflow demo ===\n")
    local function IsEven(n)
        if n % 2 == 0 then return true end
        return false
    end

    io.write(string.format("if...else..., IsEven(3) : %s\n", IsEven(3)))
end

function lib.loop_demo()
    -- ~ [loop]
    -- for...do
    -- while...
    -- repeat...
    io.write("\n=== loop demo ===\n")
    local numbers = {1, 2, 3, 4, 5}

    for i = 1, #numbers, 1 do
        io.write(string.format("%s, %s \n", i, numbers[i]))
    end

    local i = #numbers
    while i > 0 do
        io.write(string.format("%s, %s \n", i, numbers[i]))
        i = i - 1
    end

    i = 1
    repeat
        io.write(string.format("%s, %s \n", i, numbers[i]))
        i = i + 1
    until i > #numbers
end

function lib.mt_demo()
    -- ~ metatable
    -- pattern: iterface
    io.write("\n=== mt demo ===\n")

    local mt = {
        __add = function(tbl1, tbl2)
            local rv = {}
            for i = 1, #tbl1, 1 do
                if (tbl1[i] ~= nil and tbl2[i] ~= nil) then
                    rv[i] = tbl1[i] + tbl2[i]
                else
                    rv[i] = 0
                end
            end
            return rv
        end,

        __eq = function(tbl1, tbl2)
            return tbl1.values == tbl2.values
        end
    }

    local numbers = {1, 2, 3, 4, 5}
    setmetatable(numbers, mt)
    local tables = numbers + numbers
    print(table.concat(tables, ", "))
    print(numbers ~= numbers)
end

function lib.fileio_demo()
    -- ~ [file io]
    -- io.open
        -- r
        -- w
        -- a
        -- +
    -- file:write
    -- file:seek
    -- file:close
    io.write("\n=== fileio demo ===\n")
    local file = io.open("lua.csv", "w+")
    file:write("Deserunt ipsum quis fugiat\n")
    file:write("Velit dolor veniam exercitation\n")
    file:seek("set", 0)
    print(file:read("*a"))
    file:close()
end

function lib.oop_demo()
    -- ~ [oop meme]
    -- regular table
    -- binding class:new() to "self"
    -- return "self" function pointer
    -- using instances of class like other langs;
    io.write("\n=== oop demo ===\n")
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
        return string.format("name = %s\nage = %s\nsex = %s\n", self.name, self.age, self.sex)
    end

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
        return string.format("name = %s\nage = %s\nsex = %s\nfood = %s\n", self.name, self.age, self.sex, self.food)
    end

    local a1 = Animal:new("Object001", 2, "male")
    print(a1:toString())
    local b1 = Dog:new("json", 3, "female", "canddy")
    print(b1:toString())
end

function lib.coroutine_demo()
    -- ~ [coroutine]
    -- coroutine.create
    -- coroutine.yield
    -- conoutine.status

    -- ^ [asyn vs syn]
    -- synchronous
    io.write("\n=== coroutine demo ===\n")
    local co1 = coroutine.create(function (last)
        for i = 1, last, 1 do
            print(i)
            if i == 8 then
                coroutine.yield(co1)
            end
        end
    end)

    local co2 = coroutine.create(function (last)
        for i = 101, last, 1 do
            print(i)
        end
    end)

    coroutine.resume(co1, 10)
    print(coroutine.status(co1))
    coroutine.resume(co2, 120)
    print(coroutine.status(co1))
    print(coroutine.status(co2))
end

return lib