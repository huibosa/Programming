x = 24
epsilon = .001
numGuess = 0

low = .0
high = max(1.0, x)
ans = (high + low) / 2.0

while abs(ans**2 - x) >= epsilon:
    numGuess += 1
    if ans ** 2 < x:
        low = ans
    else:
        high = ans
    ans = (high + low) / 2.0

print("Num guesses = ", numGuess)
print("Answer = ", ans)
