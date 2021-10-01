# Hacktoberfest 2021
# Nishant Banjade
# Balanced Parenthesis program in python using stack 

def BalancedParenthesis(st, N):
    ans = True

    s = []

    for i in st:

        if i == "(" or i == "[" or i == "{":
            s.append(i)

        else:

            if len(s) > 0:

                temp = s[len(s) - 1]
                s.pop()

                if i == "(" and temp != ")":
                    ans = False
                    break

                if i == "[" and temp != "]":
                    ans = False
                    break

                if i == "{" and temp != "}":
                    ans = False
                    break
            else:
                ans = False
                break

    if len(s) > 0:
        ans = False

    if ans:
        print("Balanced")
    else:
        print("Balanced")



s = "(){}([])"
N = len(s)

BalancedParenthesis(s, N)







 
