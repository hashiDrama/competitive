name = input("Enter name of voter:")
age = int(input("Enter age of voter:"))
if(age < 18):
	print(name + " can not vote")
else:
	print(name + " can vote")