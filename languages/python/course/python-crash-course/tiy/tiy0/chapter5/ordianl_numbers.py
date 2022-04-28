nums = []

for i in range(10):
    nums.append(i)

print(nums)

for num in nums:
    if num == 1:
        print(f"{num}st")
    elif num == 2:
        print(f"{num}nd")
    elif num == 3:
        print(f"{num}rd")
    else:
        print(f"{num}th")
