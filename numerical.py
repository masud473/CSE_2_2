from math import sqrt
fx= lambda x:x**3-x-1
gx =lambda x: 1/sqrt(1+x)
dx= lambda x:3*x**2-1
e=1e-3
i=0
def bisection(a:float,b:float):
    global i
    x=(a+b)/2
    print(i,fx(x))
    i+=1
    if abs(fx(x))<=e: return x
    elif fx(x)*fx(a)<0: return bisection(a,x)
    else: return bisection(x,b)

def falsi(a:float,b:float):
    global i
    x=(a*fx(b)-b*fx(a))/(fx(b)-fx(a))
    print(i,fx(x))
    i+=1
    if abs(fx(x))<=e: return x
    elif fx(x)*fx(a)<0: return falsi(a,x)
    else: return falsi(x,b)

def secant(a:float,b:float):
    global i
    x=(a*fx(b)-b*fx(a))/(fx(b)-fx(a))
    print(i,fx(x))
    i+=1
    if abs(fx(x))<=e: return x
    else: return secant(b,x)

def newton(a:float):
    global i
    x=a-fx(a)/dx(a)
    print(i,fx(x))
    i+=1
    if abs(fx(x))<=e: return x
    else: return newton(x)

def fixed(a:float):
    global i
    x=gx(a)
    i+=1
    if abs(x-a)<=e: return x
    else: return fixed(x)

print(newton(1))