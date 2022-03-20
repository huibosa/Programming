guest_list = ["guido van rossum", "jack turner", "lyn hill"]

print(f"{guest_list[0].title()}, please come to dinner")
print(f"{guest_list[1].title()}, please come to dinner")
print(f"{guest_list[2].title()}, please come to dinner")

print(f"{2} can't make it to the dinner")

del guest_list[2]
guest_list.insert(1, "gary snyder")

print(f"{guest_list[0].title()}, please come to dinner")
print(f"{guest_list[1].title()}, please come to dinner")
print(f"{guest_list[2].title()}, please come to dinner")
