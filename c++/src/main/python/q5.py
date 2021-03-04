#ques1
name = input("Enter name of voter:")
age = int(input("Enter age of voter:"))
if(age < 18):
	print(name + " can not vote")
else:
	print(name + " can vote")
	
#ques2
num = int(input("Enter a number:"))
if(num == 1):
	print("This is my 1st hello to you")
elif(num == 2):
	print("This is my 2nd hello to you")
elif(num == 3):
	print("This is my 3rd hello to you")
elif(num == 4):
	print("This is my 4th hello to you")
elif(num == 5):
	print("This is my 5th hello to you")
elif(num == 6):
	print("This is my 6th hello to you")
elif(num == 7):
	print("This is my 7th hello to you")
elif(num == 8):
	print("This is my 8th hello to you")
elif(num == 9):
	print("This is my 9th hello to you")

#ques3
num1 = int(input("Enter first number:"))
num2 = int(input("Enter second number:"))
if(num1 == num2):
	print("Numbers are same")
elif(num1 > num2):
	print(str(num1) + " is larger")
else:
	print(str(num2) + " is larger")

#ques4
num = int(input("Enter a number between 1 and 7:"))
if(num == 1):
	print("Sunday")
if(num == 2):
	print("Monday")
if(num == 3):
	print("Tuesday")
if(num == 4):
	print("Wednesday")
if(num == 5):
	print("Thursday")
if(num == 6):
	print("Friday")
if(num == 7):
	print("Saturday")

#ques5
year = int(input("Enter year in YYYY format:"))
if((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)):
	print("It is a leap year")
else:
	print("It is a normal year")


#ques 6
a = int(input("Enter 1st side of triangle:"))
b = int(input("Enter 2nd side of triangle:"))
c = int(input("Enter 3rd side of triangle:"))
if(a == b and b == c):
	print("The triangle is equilateral")
elif((a == b and b != c) or 
	(a == c and c != b) or 
	(b == c and a != b)):
	print("The triangle is isosceles")
else:
	print("The triangle is scalene")

#ques 7
month = int(input("Enter a number:"))
if(month == 2):
	print("Number of days are 29")
elif(month == 8):
	print("Number of days are 31")
elif(month % 2 == 0):
	print("Number of days are 30")
else:
	print("Number of days are 31")

#ques 8
physics = int(input("Enter marks in physics:"))
chemistry = int(input("Enter marks in chemistry:"))
biology = int(input("Enter marks in biology:"))
mathematics = int(input("Enter marks in mathematics:"))
computer = int(input("Enter marks in computer:"))

total = physics + chemistry + biology + mathematics + computer
percentage = (total  / 500) * 100 
if(percentage >= 90):
	grade = "A"
elif(percentage < 90 and percentage >= 80):
	grade = "B"
elif(percentage < 80 and percentage >= 70):
	grade = "C"
elif(percentage < 70 and percentage >= 60):
	grade = "D"
elif(percentage < 60 and percentage >= 40):
	grade = "E"
else:
	grade = "F"
print("Percentage is " + str(percentage) + " and grade is " + grade)


#ques 9
basic = int(input("Enter basic salary of employee:"))
if(basic <= 10000):
	hra = basic * 0.20
	da = basic * 0.80
elif(basic > 10000 and basic <= 20000):
	hra = basic * 0.25
	da = basic * 0.95
else:
	hra = basic * 0.30
	da = basic * 0.95
gross = basic + hra + da
print(gross)


#ques 10
units = int(input("Enter electricity units consumed:"))
if(units > 250):
	cost = 1.50 * (units-250) + 100 * 1.20 + 100 * 0.75 + 50 * 0.50
elif(units > 150 and units <= 250):
	cost = 1.20 * (units-150) + 100 * 0.75 + 50 * 0.50
elif(units > 50 and units <= 150):
	cost = 0.75 * (units - 50) + 50 * 0.50
else:
	cost = 0.50 * units
print(cost)