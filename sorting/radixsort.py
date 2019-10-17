def countSort(arr,exp):
    n=len(arr)
    output=[0]*n
    count=[0]*10
    for i in range(n):
        index=(arr[i]//exp)%10
        count[index]+=1
    print(count)
    for i in range(1,10):
        count[i]+=count[i-1]
    print(count)
    i=n-1
    while(i>=0):
        index=(arr[i]//exp)%10
        print("index: ",index,end="--")
        output[count[index]-1]=arr[i]
        count[index]-=1
        print("Count-> ",count)
        print(output,end='--')
        i-=1
    i=0
    for i in range(n):
      arr[i]=output[i]

def radixSort(arr):
    max1=max(arr)
    exp=1
    while(max1//exp):
        print("Countsort\n")
        countSort(arr,exp)
        exp*=10

arr=[180,34,85,95,813]
print(arr)
radixSort(arr)
print(arr)
