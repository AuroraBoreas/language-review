
-- ~ [statement]
-- Arithmetic
-- Relational
-- Logic
-- Access
-- Bitwise
-- Assignment
-- Cast
-- Operator for storage
-- Operator for other

stat = {}
stat.statment_demo = function()
    print("inside statemment_demo\n")

    local a = 42 --!strick 
    local b = 69 --!strick
    print()
    io.write(string.format("a=%s, b=%s; a + b = %s\n", a, b, a+b));
    io.write(string.format("a=%s, b=%s; a - b = %s\n", a, b, a-b));
    io.write(string.format("a=%s, b=%s; a * b = %s\n", a, b, a*b));
    io.write(string.format("a=%s, b=%s; a / b = %s\n", a, b, a/b));
    io.write(string.format("a=%s, b=%s; a %% b = %s\n", a, b, a%b));
    
    io.write('\n')
    io.write(string.format("a=%s, b=%s; a == b : %s\n", a, b, a==b));
    io.write(string.format("a=%s, b=%s; a != b : %s\n", a, b, a~=b));
    io.write(string.format("a=%s, b=%s; a > b  : %s\n", a, b, a>b));
    io.write(string.format("a=%s, b=%s; a >= b : %s\n", a, b, a>=b));
    io.write(string.format("a=%s, b=%s; a < b  : %s\n", a, b, a<b));
    io.write(string.format("a=%s, b=%s; a <= b : %s\n", a, b, a<=b));

    print()
    io.write(string.format("a=%s, b=%s; !a : %s\n", a, b, not a));
    io.write(string.format("a=%s, b=%s; a && b: %s\n", a, b, a and b));
    io.write(string.format("a=%s, b=%s; a or b: %s\n", a, b, a or b));

    print()
    c = a << 2;
    io.write(string.format("a=%s, b=%s; a << 2: %s\n", a, b, c));
    c = a >> 2;
    io.write(string.format("a=%s, b=%s; a >> 2: %s\n", a, b, c));
    c = ~a;
    io.write(string.format("a=%s, b=%s; ~a: %s\n", a, b, c));
    c = a|b;
    io.write(string.format("a=%s, b=%s; a|b: %s\n", a, b, c));
    c = a&b;
    io.write(string.format("a=%s, b=%s; a&b: %s\n", a, b, c));
    -- bitwise xor not implemented in LUA;
    -- c = a^b;
    -- io.write(string.format("a=%s, b=%s; a^b: %s\n", a, b, c));
    
end

return stat