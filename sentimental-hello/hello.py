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

    print_blocks(height)

def print_blocks(height):
    # Print spaces, L blocks, gap, R blocks
    for i in range(height):
        for j in range(height - i - 1): # Spaces
            print("#")
        for j in range

if __name__ == "__main__":
    main()
