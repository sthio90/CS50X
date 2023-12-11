# TODO
def main():
    # Get user height input
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                break
            else:
                print("Height must be between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a whole number.")

    # Print out blocks of height
    print_blocks(height)

def print_blocks(height):
    # Print spaces, L blocks, gap, R blocks
    for i in range(height):
        for j in range(height - i - 1): # Spaces
            print(" ")
        for j in range(height + 1): # L blocks
            print("#")

        print("  ") # Gap

        for j in range(height + 1): # R blocks
            print("#")


if __name__ == "__main__":
    main()
