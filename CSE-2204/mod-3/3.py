import math
fx=lambda x:math.pow(x,3)
def diff_table(y:list,n:int):
    lst=[[] for i in range(n)]
    lst[0][:]=y
    for i in range(1,n):
        for j in range(n-i):
            lst[i].append(lst[i-1][j+1]-lst[i-1][j])
    return lst
def forward(p:int,n:int):
    tbl=[1,p]
    for i in range(2,n):
        tbl.append((tbl[-1]*(p-i+1)))

    ans=[tbl[i]/math.factorial(i) for i in range(n)]

    return ans

def forward_interpol(y:list,x:list,h:int,val:int):
    p=(val-x[0])/h
    diff=diff_table(y,len(y))
    diff=[diff[i][0] for i in range(len(diff))]

    tbl=forward(p,len(diff))
    sum=0
    for a,b in zip(diff,tbl):
        sum+=a*b
    return sum

def backward(p:int,n:int):
    tbl=[1,p]
    for i in range(2,n):
        tbl.append((tbl[-1]*(p+i-1)))

    ans=[tbl[i]/math.factorial(i) for i in range(n)]

    return ans

def backward_interpol(y:list,x:list,h:int,val:int):
    p=(val-x[-1])/h
    diff=diff_table(y,len(y))
    diff=[diff[i][-1] for i in range(len(diff))]

    tbl=backward(p,len(diff))
    sum=0
    for a,b in zip(diff,tbl):
        sum+=a*b
    return sum
def central_backward(p:int,n:int):
    tbl=[1,p]
    for i in range(2,n):
        tbl.append((tbl[-1]*(p-(i//2) if  i&1 else p+(i//2))))
    ans=[tbl[i]/math.factorial(i) for i in range(n)]

    return ans

def central_backward_interpol(y:list,x:list,h:float,val:int):
    p=(val-x[((len(x))-1)//2])/h
    diff=diff_table(y,len(y))
    diff=[diff[i][(len(diff[i])-1)//2] for i in range(len(diff))]

    tbl=central_backward(p,len(diff))
    sum=0
    for a,b in zip(diff,tbl):
        sum+=a*b
    return sum
print('forward interpolation: ',forward_interpol([24,120,336,720],[1,3,5,7],2,8))
print('backward interpolation:',backward_interpol([24,120,336,720],[1,3,5,7],2,8))
print('gauss',central_backward_interpol([2.7183,2.8577,3.0042,3.1582,3.3201,3.4903,3.6693],[1,1.05,1.1,1.15,1.2,1.25,1.3],.4,1.17))
    



