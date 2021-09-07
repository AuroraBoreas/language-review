local lib = {}

function lib.var_demo()
    print('\n=== variable demo ===\n')
    -- ~ [varible]
    -- @ pattern: T N V
    -- @ primitive type: number, string, float, boolean, function, table, coroutine
    -- @ type conversion: dymanic_cast; static_cast; const_cast; reinterpret_cast;
    -- @ declare and definition: early-binding; late-binding;
    -- @ storage: auto; static; const; register
    -- @ keyword: local
    
    local a = 42;
    local b; b = 3.14
    local c = false
    local d = "hello world"

    io.write(string.format('a = %d, type : %s', a, type(a)), '\n')
    io.write(string.format('b = %f, type : %s', b, type(b)), '\n')
    io.write(string.format('c = %s, type : %s', c, type(c)), '\n')
    io.write(string.format('d = %s, type : %s', d, type(d)), '\n')
    
    print(string.format("c = %s, tonumber(%s) : %s", c, c, tonumber(c)))
end

lib.func_demo = function()
    print('\n=== function demo ===\n')

    -- ~ [function]
    -- @ T N P
    -- @ declare and define
    -- @ cat: regular; anonymous; lambda; closure; nested function; class inside function;
    -- @ return_type; function_name; parameters;
    -- @ function template

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
    
    local function _sum(n)
        return (n*(n+1))/2
    end

    local function __sum(...)
        local ttl = 0
        for k, v in pairs{...} do
            ttl = ttl + v
        end
        return ttl
    end
    
    local function GetInt()
        local i = 0
        return function()
            i = i + 1
            return i
        end
    end

    io.write(string.format('fibonacci(10) = %d', fibonacci(10)), '\n')
    io.write(string.format('factorial(10) = %d', factorial(10)), '\n')
    io.write(string.format('_sum(10) = %d', _sum(10)), '\n')
    io.write(string.format('__sum(1, 2, 3, 4) = %d', __sum(1, 2, 3, 4)), '\n')
    local g = GetInt()
    io.write(string.format('GetInt() = %d', g()), '\n')
    io.write(string.format('GetInt() = %d', g()), '\n')
    io.write(string.format('GetInt() = %d', g()), '\n')

end

lib.stat_demo = function()
    print('\n=== statement demo ===\n')
    -- ~ [statement demo]
    -- @ Arithmetic
    -- @ Relational
    -- @ Logic
    -- @ Access
    -- @ Bitwise
    -- @ Assign
    -- @ Cast
    -- @ Operator for storage
    -- @ Operator for other

    local a = 42;
    local b = 69;

    io.write(string.format('a = %d, b = %d; a + b = %d', a, b, a+b), '\n');
    io.write(string.format('a = %d, b = %d; a - b = %d', a, b, a-b), '\n');
    io.write(string.format('a = %d, b = %d; a * b = %d', a, b, a*b), '\n');
    io.write(string.format('a = %s, b = %s; a / b = %s', a, b, a/b), '\n');
    io.write(string.format('a = %d, b = %d; a %% b = %d', a, b, a%b), '\n');
    
    io.write(string.format('a = %d, b = %d; a == b : %s', a, b, a==b), '\n');
    io.write(string.format('a = %d, b = %d; a ~= b : %s', a, b, a~=b), '\n');
    io.write(string.format('a = %d, b = %d; a > b  : %s', a, b, a>b), '\n');
    io.write(string.format('a = %d, b = %d; a >= b : %s', a, b, a>=b), '\n');
    io.write(string.format('a = %d, b = %d; a < b  : %s', a, b, a<b), '\n');
    io.write(string.format('a = %d, b = %d; a <= b : %s', a, b, a<=b), '\n');
    
    io.write(string.format('a = %d, b = %d; not a : %s', a, b, not a), '\n');
    io.write(string.format('a = %d, b = %d; a and b : %s', a, b, a and b), '\n');
    io.write(string.format('a = %d, b = %d; a or b : %s', a, b, a or b), '\n');
    
    local c = a << 2
    io.write(string.format('a = %d, b = %d; a << 2 : %s', a, b, c), '\n');
    c = a >> 2
    io.write(string.format('a = %d, b = %d; a >> 2 : %s', a, b, c), '\n');
    c = ~a
    io.write(string.format('a = %d, b = %d; ~a : %s', a, b, c), '\n');
    c = a & b
    io.write(string.format('a = %d, b = %d; a & b : %s', a, b, c), '\n');
    c = a | b
    io.write(string.format('a = %d, b = %d; a | b : %s', a, b, c), '\n');
end

lib.controlflow_demo = function()
    print('\n=== controlflow demo ===\n')
    -- ~ [controlflow]
    -- @ if...else if...else...
    -- @ [x] switch...case...default
    -- @ [x] try...catch...finally
    
    function IsEven(n)
        return n%2 == 0
    end
    
    local x = 42;
    if IsEven(x) then
        print(tostring(x) .. " is even")
    else
        print(tostring(x) .. " is odd")
    end
end

lib.loop_demo = function()
    print('\n=== loop demo ===\n')
    -- ~ [loop]
    -- @ while
    -- @ for
    -- @ repeat

    local i = 0
    local m = 10
    while (i < m) do
        io.write(string.format('i = %d', i), '\n')
        i = i + 1
        if i == 8 then break end
    end

    for i = 1, m do
        io.write(string.format('%s*%s = %d', i, i, i*i), '\n')
    end
    
    repeat
        io.write(string.format('%s*%s = %d', i, i, i*i), '\n')
        i = i - 1
    until i == 0
end

lib.coroutine = function()
    print('\n=== coroutine demo ===\n')
end

lib.fileio = function()
    print('\n=== file io ===\n')
end

lib.oop = function()
    print('\n=== oop io ===\n')
end

lib.metatable = function()
    print('\n=== oop io ===\n')
end

return lib