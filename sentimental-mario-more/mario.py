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
        # Print left spaces
        print(" " * (height - i - 1), end="")

        # Print left blocks
        print("#" * (i + 1), end="")

        # Print gap
        print("  ", end="")

        # Print right blocks
        print("#" * (i + 1))


if __name__ == "__main__":
    main()
