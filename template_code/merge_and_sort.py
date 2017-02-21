""" Algo qui merge deux listes et les sort """


def merge(x, y):
    if len(x) == 0:
        return y
    if len(y) == 0:
        return x
    if x[0] <= y[0]:
        return [x[0]] + merge(x[1:], y)
    else:
        return [y[0]] + merge(x, y[1:])

x = [2, 4, 6]
y = [1, 3, 5]
assert merge(x, y) == [1, 2, 3, 4, 5, 6]
assert merge2(x, y) == [1, 2, 3, 4, 5, 6]