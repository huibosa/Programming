import os


def main():
    CheckDir = input("Enter the name of the directory to check : ")
    print()

    if os.path.exists(CheckDir):
        print("The directory exists")
    else:
        print("No directory found for " + CheckDir)
        print()
        option = input("Would you like this directory craete? y/n: ")

        if option == "n":
            print("Goodbye")
            exit()
        elif option == "y":
            os.makedirs(CheckDir)
            print("Directory created for " + CheckDir)
        else:
            print("Not an option. Exiting")
            exit()


if __name__ == "__main__":
    main()
