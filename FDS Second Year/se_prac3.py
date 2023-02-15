def palindrome():
	str1=input("Enter the string : ")
	a=len(str1)
	flag=0

	for i in range(int(a/2)):
		if str1[i]==str1[a-1-i]:
			flag=1
		else :
			flag=0
			break 

	if(flag==1):
		print("Entered string is palindrome")
	else:
		print("Entered string is not palindrome")		
#palindrome()

def freq():
	str1=input("Enter the string : ")
	f=input("Enter the character whose frequency to be find ")
	count=0
	for char in str1:
		if(char==f):
			count=count+1
	print("The frequency of character %s is "%(f) ,count)
#freq()

'''
def word():
	str1=input("Enter the string : ")
	sub_str1=input("Enter the substring to find : ")
	start=0
	count=0
	sub=0
	while(start<=len(sub_str1)):
		while(count<=len(str1)):
			if sub_str1[start]==str1[count]:
				count=count+1
				start=start+1
				break
			elif sub_str1[start]!=str1[count]:
				count=count+1
				start=0				
word()	
	'''
def long_word():
	str1=input("Enter the string : ")
	count=0
	mx=0
	temp=0
	index=0
	for i in range(0,len(str1)):
		if str1[i]!=' ':
			count=count+1
		elif str1[i]==' ':
			if count>=mx:
				mx=count
				index=i-mx
				count=0
	print("The length of longest word : ",mx)
	print("Index of the word : ",index)

long_word()
