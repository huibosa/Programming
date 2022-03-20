guest_list = ["guido van rossum", "jack turner", "lyn hill"]

print(f"\n{guest_list[0].title()}, please come to dinner")
print(f"{guest_list[1].title()}, please come to dinner")
print(f"{guest_list[2].title()}, please come to dinner")

print(f"{2} can't make it to the dinner")

del guest_list[2]
guest_list.insert(1, "gary snyder")

print(f"\n{guest_list[0].title()}, please come to dinner")
print(f"{guest_list[1].title()}, please come to dinner")
print(f"{guest_list[2].title()}, please come to dinner")

print(f"\nGuys, I just found a bigger dinner table")

guest_list.insert(0, "frida kahlo")
guest_list.insert(2, "reinhold messner")
guest_list.append("elizabeth peratrovich")

print(f"\n{guest_list[0].title()}, please come to dinner")
print(f"{guest_list[1].title()}, please come to dinner")
print(f"{guest_list[2].title()}, please come to dinner")
print(f"{guest_list[3].title()}, please come to dinner")
print(f"{guest_list[4].title()}, please come to dinner")
