"""                           Group A - Assignment 1
In second year computer engineering class, group A students play cricket,
group B students play badminton and group C students play football. 
Write a python program using functions to compute following: - 
a)	List of students who play both cricket and badminton 
b)	List of students who play either cricket or badminton but not both 
c)	Number of students who play neither cricket nor badminton
d)	Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use SET built-in functions)
"""
grp_a=[]
grp_b=[]
grp_c=[]
grp_aUb=[]
grp_aUc=[]
grp_aAb=[]
grp_aEb=[]
grp_oC=[]

def inputt(g1 , sport):
    n=int(input("Enter the number students playing %s :" %(sport)))
    for i in range (n):
        x=input("Enter the roll number of student playing %s : "%(sport))
        g1.append(x)
    print("Input taken sucessfully \n")
    return g1

def inter(g1 , g2):
    intersection=[]
    for x in g1:
        for y in g2:
            if x==y:
                intersection.append(x)
    return intersection

def union(g1,g2):
    gnew=[]
    flag=0
    for i in g1:
        gnew.append(i)
    for i in g2 :
        for j in g1:
            if i==j:
                flag=0
                break
            else :
                flag=1
        if flag==1:
            gnew.append(i)
    return gnew

def either(g1Ug2,g1Ag2):
    gnew=[]
    flag=0
    for i in g1Ug2:
        for j in g1Ag2:
            if i==j:
                flag=0
                break
            else:
                flag=1
        if flag==1:
            gnew.append(i)
    return gnew

def only(g1Ug2 , g3):
    gnew=[]
    flag=0
    for i in g3:
        for j in g1Ug2:
            if i==j:
                flag=0
                break
            else :
                flag=1
        if flag==1:
            gnew.append(i)
    return gnew

def notB(g1Ug3 , g2):
    gnew=[]
    flag=0
    for i in g1Ug3:
        for j in g2:
            if i==j:
                flag=0
                break
            else :
                flag=1
        if flag==1:
            gnew.append(i)
    return gnew

def main():
    inputt(grp_a , 'cricket')    
    inputt(grp_b , 'Badminton')   
    inputt(grp_c , 'Football')   

    grp_aAb = inter(grp_a,grp_b)
    grp_aUb= union(grp_a,grp_b)   
    grp_aUc=union(grp_a,grp_c)   
    grp_aEb=either(grp_aUb,grp_aAb)
    grp_oC=only(grp_aUb,grp_c)
    grp_nB=notB(grp_aUc,grp_b)
    
    print("1 = List of students who play both cricket and badminton ")
    print("2 = List of students who play either cricket or badminton but not both ")
    print("3 = Number of students who play neither cricket nor badminton ")
    print("4 = Number of students who play cricket and football but not badminton ")
    print("5 = Exit\n")

    while(True):
        ch=int(input("Enter your choice : "))
        if ch==1:
            print("List of students who play both cricket and badminton :", grp_aAb ,"\n")
        elif ch==2:
            print("List of students who play either cricket or badminton but not both :", grp_aEb , "\n")
        elif ch==3:
            print(grp_oC)
            print("Number of students who play neither cricket nor badminton :",len(grp_oC), "\n")
        elif ch==4:
            print(grp_nB)
            print("Number of students who play cricket and football but not badminton : ",len(grp_nB) ,"\n")
        else :
            break
main()