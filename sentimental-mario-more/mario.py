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


if __name__ == "__main__":
    main()
