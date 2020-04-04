mod = 1000000000

def multiply(a,b):
    global mod
    ra = len(a)
    ca = 0
    if(ra>0):
        ca = len(a[0])
    rb = len(b)
    cb = 0
    if(rb>0):
        cb = len(b[0])
    x = [[0 for i in range(cb)] for j in range(ra) ]
    for i in range(ra):
        for j in range(cb):
            for k in range(rb):
                x[i][j] = (x[i][j]+(a[i][k]*b[k][j])%mod)%mod
    return x

def seq(a,n,k):
    if(n==0):
        x = [[0 for i in range(k)]for j in range(k)]
        for i in range(k):
            x[i][i]=1
        return x
    if(n%2 == 0):
        return seq(multiply(a,a),n//2,k)
    return multiply(a,seq(multiply(a,a),n//2,k))

q = int(input())

for num in range(q):
    k = int(input())
    b = list(map(int,input().strip().split()))
    c = list(map(int,input().strip().split()))
    n = int(input())
    if(n<=k):
        print(b[n-1])
    else:
        m = [[0 for i in range(k)]for j in range(k)]
        for i in range(k-1):
            m[i][i+1]=1
        for i in range(k):
            m[k-1][i] = c[k-i-1]
        A = []
        for i in range(k):
            A.append([b[i]])
        x = seq(m,n-k,k)
        print(multiply(x,A)[k-1][0])
        