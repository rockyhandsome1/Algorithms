def distributionCounting(lst,l,u,n):
    d = [0 for i in range(0,n)]
    S = [0 for i in range(0,n)]
    for i in range(0,n):
        d[lst[i]-l] = d[lst[i]-l]+1 #frequecy
    for j in range(1,u-l+1):
        d[j] = d[j-1] + d[j] #distribution
    for i in range(n-1, -1, -1):
        j = lst[i] - l
        S[d[j]-1] = lst[i]
        d[j] = d[j] - 1 
    return S
    
    
arr = list(map(int,input("Enter the elements:").split()))
print(distributionCounting(arr,min(arr),max(arr),len(arr)))
