import numpy as np
def helper(x,y=1,a=1):
    if type(y)==int:
        return ([i**y for i in x])
    return ([(i**a)*j for i,j in zip(x,y)])
itertable=None
def calc(table:list[tuple])->tuple:
    global itertable
    x=[1/i for i,j in table]
    y=[1/j for i,j in table]
    x2=[i**2 for i in x]
    xy=[i*j for i,j in zip(x,y)]
    itertable=map(list,zip(x,y,x2,xy))
    return np.linalg.solve(np.array([[len(x),sum(x)],[sum(x),sum(x2)]]),np.array([sum(y),sum(xy)]))
table=[(3, 7.148), (5, 10.231), (8, 13.509), (12, 16.434)]

# print(*calc(table))
print(calc(table))
for i in itertable:
    print(i)