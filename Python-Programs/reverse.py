#Python program to reverse a number using function
def reverse_Num(Number):  #Define a function
    Reverse=0             #declarae and initialize variable Reserve
    while(Number>0):
        Reminder=Number %10
        Reverse=(Reverse *10)+Reminder
        Number=Number//10;
    return Reverse    #return reverse value to function
Number=int(input("Please enter a number: "))
Reverse=reverse_Num(Number)#Call the function
print("The entered number is: %d" %Number)
print("The reverse number is: %d" %Reverse)
