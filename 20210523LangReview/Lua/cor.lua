
co = coroutine.create(function()
    for i = 1, 10, 1 do 
        print(i)
        print(coroutine.status(co))
        if i == 5 then coroutine.yield() end
    end    
end)

print(coroutine.status(co))

coroutine.resume(co)

print(coroutine.status(co))


co2 = coroutine.create(function()
    for i = 100, 110, 1 do
        print(i)
    end
end)

coroutine.resume(co2)
coroutine.resume(co)