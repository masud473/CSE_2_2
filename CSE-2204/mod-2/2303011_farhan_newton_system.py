f=lambda x,y: 3*y*pow(x,2) - 10*x + 7
g=lambda x,y: pow(y,2)-5*y+4
fx=lambda x,y: 6*y*x-10
fy=lambda x,y: 3*pow(x,2)
gx=lambda x,y: 0
gy=lambda x,y:2*y-5
eps=1e-5
def solver(a,b):
    while True:
        d=fx(a,b)*gy(a,b)-fy(a,b)*gx(a,b)
        h=(-f(a,b)*gy(a,b)-g(a,b)*fy(a,b))/d
        k=(-f(a,b)*gx(a,b)-g(a,b)*fx(a,b))/d
        a=a+h
        b=b+k
        if abs(h)<eps and abs(k)<eps:return (a,b)
print(solver(2,2))