x = input("Enter an integer between 0 and 1024 -- ")
x = int(x)
a = 0
b = 1024
test = True
if x == 0:
    print("Your number is 0, thank you for playing.")
    test = False
else:
    if x == 1024:
        print("Your number is 1024, thanks for playing")
        test = False

        while test == True:
            m = int((a+b)/2)
            if m == x:
                print("Your number is ", m, ", thank you for playing")
                break
            else:
                if m < x:
                    a = m
                else:
                    b = m
