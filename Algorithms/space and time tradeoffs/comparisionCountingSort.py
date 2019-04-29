def comparisonContingSort(lst,n):
    
    count = [0 for i in range(0,n)]
    S = [0 for i in range(0,n)]
    for i in range(0,n-1):
        for j in range(i+1,n):
            if lst[i] < lst[j]:
                count[j] = count[j] + 1
            else:
                count[i] = count[i] + 1
    for i in range(0,n):
        S[count[i]] = lst[i]
    return S
            
          

arr = list(map(int,input("Enter the array elements:").split()))

print(comparisonContingSort(arr,len(arr)))
