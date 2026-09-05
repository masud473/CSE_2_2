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


x=[1,2,3,4,5]
y=[0.6,2.4,3.5,4.8,5.7]

a,b=solver(x,y).values()

print(f'Y = {a} + {b}X')