prompt = "\nTell me something, and I will repeat it back to you"
prompt += "\Enter 'quit' to end the program."

active = True
while active:
    message = input(prompt)
    if message == "quit":
        break
    else:
        print(message)
