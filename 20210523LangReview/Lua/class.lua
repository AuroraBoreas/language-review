Animal = {
    name = "anonymous",
    height = 0,
    weight = 0,
    sound  = "nothing",
}

function Animal:new(name, height, weight, sound)
    setmetatable({}, Animal)

    self.name = name
    self.height = height
    self.weight = weight
    self.sound = sound

    return self
end

function Animal:toString()
    return string.format('name: %s, height: %d, weight: %d, sound: %s', self.name, self.height, self.weight, self.sound)
end

local a1 = Animal:new("spot", 10, 15, "woof")
print(a1:toString())


-- inheritance
Cat = Animal:new()

function Cat:new(name, height, weight, sound, color)
    setmetatable({}, Animal)

    self.name = name
    self.height = height
    self.weight = weight
    self.sound = sound
    self.color = color

    return self
end

function Cat:toString()
    return string.format('name: %s, height: %d, weight: %d, sound: %s, color: %s', self.name, self.height, self.weight, self.sound, self.color)
end

c1 = Cat:new("Fluffy", 10, 20, "meow", "orange")
print(c1:toString())