numbers = {}

for i = 1, 10, 1 do
    numbers[i] = i * i
end

mt = {
    __add = function(table1, table2)
        table_tmp = {}
        for i = 1, #table1 do
            if (table1[i] ~= nil and table2[i] ~= nil) then
                table_tmp[i] = table1[i] + table2[i]
            else
                table_tmp[i] = 0
            end
        end
        return table_tmp
    end,

    __eq = function(table1, table2)
        return table1.value == table2.value
    end,
}

setmetatable(numbers, mt)
print(numbers == numbers)

sumTable = {}

sumTable = numbers + numbers

print(table.concat(sumTable, ", "))