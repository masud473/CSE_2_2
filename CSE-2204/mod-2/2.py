from math import exp,pow,log,sin,cos
f=lambda x:exp(-x)-sin(x)
f1=lambda x:-exp(-x)-cos(x)

tol=1e-3

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
        print(b,x,abs(b-x))
        if abs(b-x)<tol:return k
        a=b
        b=x


def ramanujan(a):
    b=[1,a[0]]
    i=2
    while True:
        x=0
        for j in range(0,min(i,len(a))):
            x+=b[-1-j]*a[j]
        b.append(x)
        i+=1
        if abs(b[-2]/b[-1]-b[-3]/b[-2])<tol:return b[-2]/b[-1]


print(ramanujan([3/2,1/4,-1/48]))