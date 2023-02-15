marks=[ ]
def inputs(marks , n):
    for i in range (1 , n+1):       
        mark = input('Enter the marks of %d student : ' %(i))
        if mark=='AB' or mark=='ab':
            mark=-1
            marks.append(mark)
        elif int(mark)<0 and int(mark)>30:
            print('Wrong input')
            break 
        elif int(mark)>=0 and int(mark)<=30:
            marks.append(int(mark))
    return marks,n
       
def display(marks, n):
    for i in range (0 , n):
        if marks[i]== -1:
            print('Marks of student %d is :' %(i+1) , 'Absent')
        else:
            print('Marks of student %d is :' %(i+1), marks[i])

def countting(marks, n):
    count=0
    for i in range (0,n):
        if marks[i]== -1:
            count=count+1
        else :
            count=count
    return count

def avg(marks , n):
    avg =0
    summ=0
    for i in range (0,n):
        if marks[i]!= -1:
            summ = summ+ marks[i]
        elif marks[i]== -1:
            summ=summ
            
    count=0
    for i in range (0,n):
        if marks[i]== -1:
            count=count+1
        else :
            count=count
    avg=(summ/(n-count))
    print('Average of Marks',avg)

def max_min(marks,n ):
    maxx=marks[0]
    for i in range(1,n):
        if maxx>=marks[i]:
            maxx=maxx
        elif marks[i]>maxx:
            maxx=marks[i]
        
    minn=30
    for i in range(0,n):
        if marks[i]==-1:
            continue 
        elif marks[i]<=minn:
            minn=marks[i]

    print('Minimum marks are : ', minn)
    print('Maximum marks are : ',maxx)  
    
def frequency(marks,n ):
    freq=0
    m=0
    for i in range(0,n):
        k=marks[i]
        temp=0
        for j in range (0,n):
            if (k==marks[i] and marks[i]==-1):
                continue 
            elif (k==marks[j]):
                temp=temp +1
        if(temp>freq):
            freq=temp
            m=k
    if freq==1:
        print ("There is no such highest frequency every student have different marks")
    else :
        print("The highest frequency is %d of marks %d "%(freq,m))

def main():
    n = int(input('Enter the number of students :'))
    inputs(marks,n)
    print("\n1 : Display the marks of the students")
    print("2 : Number of absent students ")
    print("3 : Average of marks of present students")
    print("4 : Minimum and maximum marks of the students")
    print("5 : Frequency of marks ")
    print("6 : Exit ")
    while (True):
        ch=int(input("\nEnter your choice : "))
        if ch==1:
            display(marks,n)
        elif ch==2:
            print ('Number of absent students is ' ,countting( marks,n))
        elif ch==4:
            max_min(marks,n )   
        elif ch==3:
            avg(marks,n) 
        elif ch==5:
            frequency(marks,n)
        elif ch==6:
            exit(0)
        else:
            print("Wrong Input")
            exit(0)
main()