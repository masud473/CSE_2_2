from math import cos,sin
fx= lambda x: 1/2*(3+cos(x))
dx= lambda x: -1/2*(sin(x))
i=0
def atkin(x0:int):
    global i
    i+=1
    x1=fx(x0)
    x2=fx(x1)
    x3=x2- ((x2-x1)**2)/((x2-x1)-(x1-x0))
    if abs(x3-x1)<1e-3:
        return x3
    return atkin(x3)

print(atkin(1.5))
print(i)