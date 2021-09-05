-- ~ [loop] 
-- while
-- for
-- for_each
-- do while

loop = {}

loop.wh = function()
    local a = 10;
    local i = 0;
    while(i <= a) do
        io.write(string.format("%s \t", i))
        i = i + 1
        if i == 8 then
            break
        end
    end
end

loop.rp = function()
    repeat
        io.write("enter your guess: ")
        local guess = io.read()
    until tonumber(guess) == 15
end

loop.fo = function()
    local start = 1; local stop = 10; local step = 2;
    local i;

    for i = start, stop, step do
        io.write(string.format('%s\t', i))    
    end
end

loop.arr = function()
    local months = {
        'Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun',
        'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'
    }
    for k, v in pairs(months) do
        io.write(string.format('%s : %s\n', k, v))
    end
end

loop.tbl = function()
    local numbers = {};
    for i = 1, 5, 1 do
        numbers[i] = i * i;
    end

    for i = 1, #numbers do 
        io.write(string.format('%s\t', numbers[i]))
    end

    print()
    print(table.concat(numbers, ', '))
    table.insert(numbers, 1, 10)
    print(table.concat(numbers, ', '))
end

return loop