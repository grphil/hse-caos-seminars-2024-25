def rang(a, b):
    i = a
    while i < b:
        yield i
        i += 1

for i in rang(1, 10):
    pass