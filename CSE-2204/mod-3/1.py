import math
fx=lambda x:math.pow(x,3)
def diff_table(fx:function, x:list):
    y=[[] for i in range(len(x))]
    y[0][:]=[fx(i) for i in x]
    for i in range(1,len(x)):
        for j in range(len(x)-i):
            y[i].append(y[i-1][j+1]-y[i-1][j])
    return y

y=diff_table(fx,[0,1,2,3,4,5])
n=len(y[0])
for i in range(n):
    for j in range(n):
        if i<len(y[j]):
            print(y[j][i],end='    a')
    print()
    

