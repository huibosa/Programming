usernames = ["eric", "willie", "admin", "erin", "Ever"]
new_users = ["sarah", "Willie", "PHIL", "ever", "Iona"]

current_usernames = [x.lower() for x in usernames]

for new_user in new_users:
    if new_user.lower() in current_usernames:
        print(f"Sorry {new_user}, that name is taken.")
    else:
        print(f"Great, {new_user} is still available.")
