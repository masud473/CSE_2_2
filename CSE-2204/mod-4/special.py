from math import log
from sympy import symbols,solve,Eq
def solver(xl:list,yl:list)->dict:
    xy=sum(i*j for i,j in zip(xl,yl))
    y=sum(yl)
    x=sum(xl)
    x_2=sum(i*i for i in xl)
    m=len(xl)
    X,Y=symbols('x y')
    eq1=Eq(m*X + x*Y,y )
    eq2=Eq(x*X+ x_2*Y,xy)
    
    return (solve((eq1,eq2),(X,Y)))

f1=lambda i: log(i)
x=[1,3,5,7,9]
y=[2.473,6.722,18.274,49.673,135.026]

y=[f1(i) for i in y]
a,b=solver(x,y).values()

print(a,b)