'''
7. Write a menu driven program to perform the following on strings:
a) Find the length of string.
b) Return maximum of three strings.
c) Accept a string and replace all vowels with “#”
d) Find number of words in the given string.
e) Check whether the string is a palindrome or not.
'''

def lenOfString():
    '''
    Prints the lenght of string iterative method.
    '''
    str = input("\nEnter the string: ")
    position = 0
    while str[position:]:
        position += 1
    print("Length of {} is {}".format(str, position))

def maxOfString():
    '''
    Calculates the maximium of the three input strings.
    Returns: corresponding maximum string.
    '''
    str1 = input("\nEnter the string 1: ")
    str2 = input("Enter the string 2: ")
    str3 = input("Enter the string 3: ")
    if str1 > str2 and str1 > str3:
        return str1
    elif str2 > str1 and str2 > str3:
        return str2
    else:
        return str3
    
def replaceVowels():
    '''
    Prints the input string after replacing all vowels with input character.
    '''
    str = input("\nEnter the string: ")
    sym = input("Enter the character to replace vowel: ")
    str1 = ""
    for i in range(len(str)):
        ch = str[i]
        if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or\
           ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U':
           str1 = str1 + sym
        else:
            str1 += ch
    
    print("\nThe new string is:",str1)
    
def wordsInString():
    '''
    Prints the no. of words present in the input string.
    '''
    str = input("\nEnter the string: ")
    str = str + ' '
    c = 0
    for i in range(len(str)):
        if str[i] == ' ':
            c += 1
    
    print("Number of words in the string are:", c)
    
def palindrome():
    '''
    Calculates and print for the palindrome of the input string.
    '''
    str = input("\nEnter the string: ")
    str = str.lower()
    str1 = ''
    for i in range(len(str)):
        str1 = str[i] + str1
    
    if str1 == str:
        print("\n{} is palindrome!".format(str))
    else:
        print("\n{} is not palindrome!".format(str))

def exit():
    quit()

switcher = {
                1: lenOfString,
                2: maxOfString,
                3: replaceVowels,
                4: wordsInString,
                5: palindrome,
                0: exit
            }

def main():
    print("\n========= Menu =========")
    print("1. Length of string\
         \n2. Maximum of three strings\
         \n3. Replace vowels\
         \n4. Number of words in a string\
         \n5. Check palindrome\
         \n0. Exit")
         
    ch = int(input("\nEnter your choice: "))
    func = switcher.get(ch, lambda: print("\nInvlaid Choice!"))
    if ch == 2:
        print("\nThe maximum of three strings is:",func())
    else:
        func()

if __name__ == "__main__":
    while(1):
        main()