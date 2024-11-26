import sys

def gcd(x,y):
    if y==0:
        while True:
            pass
    if x==0:
        return y
    while x!=0:
        y %= x
        t=x
        x=y
        y=t
    return y
def add(x,y):
    p = x[0]*y[1]+x[1]*y[0]
    q = x[1]*y[1]
    g = gcd(p,q)
    return (p//g,q//g)
def mul(x,y):
    p = x[0]*y[0]
    q = x[1]*y[1]
    g = gcd(p,q)
    return (p//g,q//g)

def Answer(ans):
    print("!",ans[0],ans[1])
    sys.stdout.flush()

def work1():
    global n
    global vx
    len=(0,1)
    ans=(0,1)
    for i in range(1,n-1):
        lstlen=len
        print("?",vx[i],1)
        sys.stdout.flush()
        instr = input().split()
        len = (int(instr[0]),int(instr[1]))
        ans = add(ans,mul(mul(add(len,lstlen),(1,2)),(vx[i]-vx[i-1],1)))
    ans = add(ans,mul(mul(len,(1,2)),(vx[n-1]-vx[n-2],1)))
    Answer(ans)

def work2():
    global n
    global vx
    ans=(0,1)
    for i in range(1,m):
        midx2 = vx[i]+vx[i-1]
        if(midx2%2==0):
            print("?",midx2//2,"1")
        else:
            print("?",midx2,"2")
        sys.stdout.flush()
        instr = input().split()
        len = (int(instr[0]),int(instr[1]))
        ans = add(ans,mul(len,(vx[i]-vx[i-1],1)))
    Answer(ans)

def work():
    global n
    global m
    global xs
    global vx
    n=int(input())
    xs={}
    vx=[]
    for i in range(1,n+1):
        instr=input().split()
        x=int(instr[0])
        xs[x]=True
    for i in xs:
        vx.append(i)
    m = len(vx)
    if(m==n):
        work1()
    else:
        work2()


T = int(input())
while T>0:
    T-=1
    work()