from math import *
import sys

def mul(a,b):
    p = a[0]*b[0]
    q = a[1]*b[1]
    g = gcd(p,q)
    return (p//g,q//g)

def add(a,b):
    p = a[0]*b[1]+a[1]*b[0]
    q = a[1]*b[1]
    g = gcd(p,q)
    return (p//g,q//g)

def work():
    n = int(input())
    points = []
    for i in range(n):
        instr = input().split()
        points.append((int(instr[0]),int(instr[1])))
    points.sort()

    lstlen = (0,1)
    curlen = (0,1)
    area = (0,1)
    for i in range(1,n-1):
        lstlen = curlen
        print("?",points[i][0],1)
        sys.stdout.flush()
        instr = input().split()
        curlen = (int(instr[0]),int(instr[1]))
        area = add(area, mul(mul(add(curlen,lstlen),(1,2)),(points[i][0]-points[i-1][0],1)))
    area = add(area, mul(mul(curlen,(1,2)),(points[n-1][0]-points[n-2][0],1)))

    print("!",area[0],area[1])
    sys.stdout.flush()
    

T = int(input())
while T!=0:
    T -= 1
    work()