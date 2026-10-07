from math import exp,pow,log,sin,cos
f=lambda x:exp(-x)-sin(x)
f1=lambda x:-exp(-x)-cos(x)

tol=1e-3


def ramanujan(a):
    b=[1,a[0]]
    while True:
        x=0
        for j in range(min(len(a),len(b))):
            x+=b[-1-j]*a[j]
        b.append(x)
        if abs(b[-2]/b[-1]-b[-3]/b[-2])<tol:return b[-2]/b[-1]



print(ramanujan([3/2,1/4,0,-1/48]))