-- ~ [control_flow]
-- if...else...;
-- try...catch...finally;
-- switch...case...default;

cflow = {}

cflow.cf = function()
    local a = 42; local b = 69;
    if a > b then
        print(string.format('a=%s, b=%s; a > b : %s', a, b, a > b))
    else
        print(string.format('a=%s, b=%s; a > b : %s', a, b, a <= b))
    end
end

return cflow