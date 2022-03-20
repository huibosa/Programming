current_users = ["Tom", "MARY", "john", "ben", "lihua"]
new_users = ["xiaoming", "Mary", "eric", "sam", "ben"]
lower_current_users = []

for current_user in current_users:
    lower_current_users.append(current_user.lower())

print(lower_current_users)


for user in new_users:
    if user.lower() in lower_current_users:
        print(f"Username {user} is invalid, please enter anotherone!")
    else:
        print(f"Username {user} is available.")
