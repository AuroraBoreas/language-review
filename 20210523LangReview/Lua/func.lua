func = {}

func.fibonacci = function(n)
    if n < 2 then
        return 1
    else
        return func.fibonacci(n-1) + func.fibonacci(n-2)
    end
end

func.factorial = function(n)
    if n < 2 then
        return 1
    else
        return n * func.factorial(n-1)
    end
end

func.sum = function(n)
    return (n * (n+1))/2
end

func.split = function(s)
    local rv = {}
    local i = 1

    for word in string.gmatch(s, "[^%s]+") do
        rv[i] = word
        i = i + 1
    end

    return rv, i
end

func.paramarray = function(...)
    local ttl = 0
    for k, v in pairs{...} do
        ttl = ttl + v
    end
    return ttl
end

return func