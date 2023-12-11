# TODO
def main():
    while True:
        name = input("What is your name? ")
        name = name.strip()

        # Check if the name contains only letters and possibly spaces
        if name.replace(" ", "").isalpha():
            name = name.capitalize()
            print(f"hello, {name}")
            break
        else:
            print("Invalid input. Please enter a valid name.")

if __name__ == "__main__":
    main()
