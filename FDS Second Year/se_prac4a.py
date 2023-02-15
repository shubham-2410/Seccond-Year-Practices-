def set_data(n):
    roll=[]
    for i in range(n):
        roll_no=int(input("Enter the roll number of student : "))
        roll.append(roll_no)
    print("\n")
    return roll

def linear_search(roll , n , key):
    for i in range(n):
        if roll[i]==key:
            print("Key is present at index : ",i , "\n")
            return i
    else:
        print("Key is not present \n")
        return -1

def sentinel_search(roll,n,key):
    last=roll[n-1]
    roll[n-1]=key
    i=0
    while (roll[i]!=key):
        i=i+1
    roll[n-1]=last
    if((i<n-1)or (roll[n-1]==key)):
        print(key,"is present at index ",i ,"\n")
    else:
        print("Element Not Founds \n")

def binary_search(roll,n,key):
    start=0
    end=n-1
    # counter=0
    while(start<end):
        mid=int((start+end)/2)
        if(roll[mid]==key):
            return mid
        elif(key>roll[mid]):
            start=mid+1
        else:
            end=mid-1
        # counter=counter +1
    return -1


def fibonacii_search(arr, x, n):

    fibMMm2 = 0  
    fibMMm1 = 1  
    fibM = fibMMm2 + fibMMm1  
    while (fibM < n):
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1

    offset = -1
    while (fibM > 1):
        i = min(offset+fibMMm2, n-1)
        if (arr[i] < x):
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i
        elif (arr[i] > x):
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1
        else:
            return i
    if(fibMMm1 and arr[n-1] == x):
        return n-1
    return -1
def main():

    while(True):
        print("1: For Linear search \n2: For Sentinel search\n3: For Binary search\n4: For Fibonacci Search\n5:Exit\n")
        ch=int(input("Enter your choice : ")) 
        if(ch==1):
            print("\n*********Linear Search***********\n")
            n=int(input("Enter the total number of students : "))
            arr=[n]
            arr=set_data(n)
            key=int(input("Enter the key to be find : "))
            linear_search(arr , n , key)
        elif (ch==2):
            print("\n*********Sentinel Search***********\n")
            n=int(input("Enter the total number of students : "))
            arr=[n]
            arr=set_data(n)
            key=int(input("Enter the key to be find : "))
            sentinel_search(arr,n,key)
        elif(ch==3):
            print("\n*********Binary Search***********\n")
            n=int(input("Enter the total number of students : "))
            arr=[n]
            arr=set_data(n)
            key=int(input("Enter the key to be find : "))
            i=binary_search(arr,n,key)
            if(i!=-1):
                print(key,"is present at index ",i,"\n")
            else:
                print(key, "is not present \n")
        elif(ch==4):
            # print("Not yet learned \n")
            # exit(0)
            print("\n*********Fibonacii Search***********\n")
            n=int(input("Enter the total number of students : "))
            arr=[n]
            arr=set_data(n)
            key=int(input("Enter the key to be find : "))
            i=fibonacii_search(arr,key,n)
            if(i!=-1):
                print(key,"is present at index ",i,"\n")
            else:
                print(key, "is not present \n")
        elif(ch==5):
            exit(0)
        else:
            print("Wrong Input")
            exit(0)
main()

