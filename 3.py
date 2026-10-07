fx= lambda x:x**3

def table(x:list,y:list):
    t:list[list]=[[] for _ in range(len(y))]
    t[0][:]=y
    for i in range(1,len(t)):
        for j in range(len(t[i-1])-1):
            t[i].append(t[i-1][j+1]-t[i-1][j])
    return t

def solve(x:list, y:list,h:int,val:int):
    t=table(x,y)
    t=[i[(len(i))//2] for i in t]
    p=(val-x[(len(x))//2])/h
    coefficient=[1.0]
    for i in range(len(t)-1):
        coefficient.append(coefficient[i]*(p+((-1)**(i))*((i+1)//2))/(i+1))

    ans=0
    for i,j in zip(t,coefficient):
        print(j)
        ans+=i*j
    return ans

    
t=solve([1.00,1.05,1.10,1.15,1.2,1.25,1.30],[2.7183,2.8577,3.0042,3.1582,3.3201,3.4903,3.6693],0.05,1.17)
print(t)