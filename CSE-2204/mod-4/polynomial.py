from sympy import symbols,solve,Eq
def solver(xl:list,yl:list)->dict:
    x=sum(xl)
    x_2=sum(i*i for i in xl)
    x_3=sum(i*i*i for i in xl)
    x_4=sum(i*i*i*i for i in xl)

    y=sum(yl)
    xy=sum(i*j for i,j in zip(xl,yl))
    x2y=sum(i*i*j for i,j in zip(xl,yl))

    m=len(xl)
    X,Y,Z=symbols('x y z')
    print(X,Y,Z)
    eq1=Eq(m*X + x*Y+ x_2*Z,y )
    eq2=Eq(x*X+ x_2*Y+ x_3*Z,xy)
    eq3=Eq(x_2*X+ x_3*Y+ x_4*Z,x2y)
    
    return (solve((eq1,eq2,eq3),(X,Y,Z)))


x=[1,2,3,4,5]
y=[0.6,2.4,3.5,4.8,5.7]

a,b,c=solver(x,y).values()

print(f'Y = {a} + {b}X + {c}X^2')