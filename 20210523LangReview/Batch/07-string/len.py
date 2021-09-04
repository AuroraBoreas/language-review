# text = "hello zhang liang fuck scy"
# print(len(text))


def sum(*args)->float:
    rv = 0
    for i in args:
        rv += i
    return rv

numbers = (1, 2, 3)
print(sum(*numbers))