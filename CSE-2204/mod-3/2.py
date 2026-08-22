import math
def pascel(n:int):
    l=[1]
    for i in range(n):
        temp=[1]
        for j in range(len(l)-1):
            temp.append(l[j]+l[j+1])
        temp.append(1)
        l=temp
    return l

def missing(y:list):
    pscl=pascel(len(y)-1)

    sum=0
    div='*'
    i=0
    for a,b in zip(pscl,y):
        if b=='*':
            div=math.pow(-1,i)*a
        else:
            sum+=math.pow(-1,i)*a*b
        i+=1
    if div!='*':
        return sum/(-div)
    return None
print(missing([1,3,9,31,'*']))

