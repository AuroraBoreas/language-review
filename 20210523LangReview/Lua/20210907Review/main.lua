local lib = require('lib')

lib.var_demo()

lib.func_demo()

lib.stat_demo()

lib.controlflow_demo()

lib.loop_demo()

lib.coroutine()

-- ~ coroutine

local co1 = coroutine.create(function()
    for i = 1, 10, 1 do
        print(i)
        print(coroutine.status(co1))
        if i == 5 then
            coroutine.yield()
        end
    end
end)

local co2 = coroutine.create(function()
    for i = 100, 110, 1 do
        print(i)
    end
end)

coroutine.resume(co1)
print(coroutine.status(co1))
coroutine.resume(co2)
print(coroutine.status(co2))

lib.oop()
Animal = {
    name='anonymous',
    age=0,
    sex='female'
}

function Animal:new(name, age, sex)
    setmetatable({}, Animal)
    self.name = name
    self.age  = age
    self.sex  = sex
    return self
end

function Animal:toString()
    return string.format('name:%s, age: %d, sex: %s', self.name, self.age, self.sex)
end

local a1 = Animal:new("fluffy", 3, "female")
print(a1:toString())

Cat = Animal:new()

function Cat:new(name, age, sex, sound)
    self.name = name
    self.age  = age
    self.sex  = sex
    self.sound = sound
    return self
end

function Cat:toString()
    return string.format('name:%s, age:%d, sex:%s, sound:%s', self.name, self.age, self.sex, self.sound)
end

local c1 = Cat:new("doggy", 4, "male", "woof")
print(c1:toString())


lib.metatable()
local numbers = {}
for i = 1, 10, 1 do
    numbers[i] = i * i
end

local mt = {
    __add = function(table1, table2)
        local tmp = {}
        for i = 1, #table1 do
            if (table1[i] ~= nil and table2[i] ~= nil) then
                tmp[i] = table1[i] + table2[i]
            else
                tmp[i] = 0
            end
        end
        return tmp
    end,

    __eq = function(table1, table2)
        return table1.value() == table2.value()
    end,
}

setmetatable(numbers, mt)

local sumtbl = numbers + numbers
print(table.concat(sumtbl, ", "))
print(numbers == numbers)

lib.fileio()
local file = io.open("test.txt", "w+")
file:write("Dolore sit enim exercitation commodo.\n")
file:write("Exercitation eiusmod nisi proident do.\n")
file:seek("set", 0)
print(file:read("*a"))
file:close()