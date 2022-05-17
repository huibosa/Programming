def isPalindrome(s):
    def toChars(s):
        s = s.lower()
        ret = ""
        for c in s:
            if c.isalpha():
                ret += c

    def isPal(s):
        if len(s) <= 1:
            return True
        else:
            return s[0] == s[-1] and isPal(s[1:-1])

    return isPal(toChars(s))


if __name__ == "__main__":
    s = input("String: ")
    print(isPalindrome(s))
