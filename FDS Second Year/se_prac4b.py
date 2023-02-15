def Input(n):
    list=[]
    for i in range(0,n):
        k=int(input("Enter roll number of student  : "))
        list.append(k)
    print("Input taken Successfully")
    return list

def Ibuck(n):
    list=[]
    for i in range(0,n):
        k=float(input("Enter roll number of student  : "))
        list.append(k)
    print("Input taken Successfully")
    return list

def display(list,n):
    for i in range(0,n):
        print(list[i],end=' ')
    
def bubble(list,n):
    count=0
    for i in range (0,n-1):
        for j in range (n-i-1):
            if(list[j]>list[j+1]):
                temp=list[j]
                list[j]=list[j+1]
                list[j+1]=temp
    print(list)
    return list
    
def selection(list,n):
    for i in range(0,n):
        ind=i
        for j in range (i+1,n):
            if(list[ind]<list[j]):
                ind=j
        temp=list[i]
        list[i]=list[ind]
        list[ind]=temp
    return list

def insertion(list,n):
    for i in range(1,n):
        j=i-1
        key=list[i]
        while(j>=0 and list[j]>key):
            list[j+1]=list[j]
            j=j-1
        list[j+1]=key
    return list

def partition(list,l,r):
    pi=list[r]
    i=l-1
    for j in range (l,r):
        if(list[j]<=pi):
            i=i+1
            (list[i],list[j])=(list[j],list[i])

    (list[i+1],list[r])=(list[r],list[i+1])
    return i+1

def Quick(list,l,r):
    if(l<r):
        pi=partition(list,l,r)

        Quick(list,l,pi-1)
        Quick(list,pi+1,r)

def bucket(list,n):
    slot=10
    arr=[]
    for i in range (slot):
        arr.append([])
    for i in list:
        j=int(10*i)
        arr[j].append(i)
    for i in range(slot):
        insertion(arr[i],len(arr[i]))
    t=[]
    for i in range(slot):
        j=0
        if(len(arr[i])==0):
            continue
        while(j!=len(arr[i])):
            t.append(arr[i][j])
            j=j+1
    return t


def main():

    print("1.For Bubble Sort\n2.For Selection Sort\n3.Insertion sort\n4.Quick sort\n")
    ch=int(input("Enter your choice : "))
    if (ch==1):
        print("\n*********Bubble Sort***********\n")
        temp=[]
        size=int(input("Enter the total number of students : "))
        temp=Input(size)
        arr=[]
        arr=bubble(temp,size)
        display(arr,size)
    elif(ch==2):
        print("\n*********Selection Sort***********\n")
        temp=[]
        size=int(input("Enter the total number of students : "))
        temp=Input(size)
        arr=[]
        arr=selection(temp,size)
        display(arr,size)
    elif(ch==3):
        print("\n*********Insertion Sort***********\n")
        temp=[]
        size=int(input("Enter the total number of students : "))
        temp=Input(size)
        arr=[]
        t2=[]
        t2=temp
        arr=insertion(temp,size)
        display(arr,size)
    elif(ch==4):
        print("\n*********Quick Sort***********\n")
        temp=[]
        size=int(input("Enter the total number of students : "))
        temp=Input(size)
        Quick(temp,0,size-1)
        display(temp,size)
    elif(ch==5):
        print("\n*********Bucket Sort***********\n")
        temp=[]
        arr=[]
        size=int(input("Enter the total number of students : "))
        temp=Ibuck(size)
        arr=bucket(temp,size)
        display(arr,size)
main()