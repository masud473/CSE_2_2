from math import exp,pow,log,sin,cos
f=lambda x:exp(-x)-sin(x)
f1=lambda x:-exp(-x)-cos(x)
def is_replacable(p,q):
    return f(p)*f(q)>0

tol=1e-3

def bisection(a,b):
    k=0
    x=f(a)*f(b)
    if x>0:
        print('choose different a,b')
        return None
    elif x==0:
        if f(a)==0:
            return a
        else: return b
    else:
        while abs(a-b)>tol:
            x=(a+b)/2
            if is_replacable(a,x):a=x
            else: b=x
            k+=1

        return k

def falsi(a,b):
    x=f(a)*f(b)
    k=0
    if x>0:
        print('choose different a,b')
        return None
    elif x==0:
        if f(a)==0:
            return a
        else: return b
    else:
        x=(a*f(b)-b*f(a))/(f(b)-f(a))
        while abs(f(x))>tol:

            if is_replacable(a,x):a=x
            else: b=x
            x=(a*f(b)-b*f(a))/(f(b)-f(a))
            k+=1
        return k

def fixed(a):
    x=f(a)
    if x==0:
        if f(a)==0:
            return a
    else:
        while abs(a-x)>tol:
            a=x
            x=f(x)

        return x
def newton(a):
    if f(a)==0:return 0
    k=0
    while True:
        k+=1
        x=a-f(a)/f1(a)
        print(x)
        if abs(a-x)<tol:return k
        a=x

        return x
def secant(a,b):
    if f(a)==0 or f(b)==0:return 0
    k=0
    while True:
        k+=1
        x=(a*f(b)-b*f(a))/(f(b)-f(a))
        print(x)
        if abs(a-x)<tol:return k
        a=b
        b=x
print(secant(.4,.9))
