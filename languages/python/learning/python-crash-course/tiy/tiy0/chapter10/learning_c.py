filename = "learning_python.txt"

with open(filename) as f:
    lines = f.readlines()

for line in lines:
    line = line.strip()
    print(line.replace("C", "Python"))
