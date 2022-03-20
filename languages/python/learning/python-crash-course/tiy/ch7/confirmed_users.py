# Start with users that need to be verified,
# and an empty list to hold confirmed users.
unconfirmed_users = ["alice", "brian", "candace"]
confirmed_users = []

while True:
    user = unconfirmed_users.pop()
    confirmed_users.append(user)
    if len(unconfirmed_users) == 0:
        break

print(unconfirmed_users)
print(confirmed_users)
