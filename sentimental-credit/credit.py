import cs50
# TODO

def main():
    # Get user card input
    while True:
        try:
            card = get_int("Number: ")
            if card > 0:
                break
            else:
                print("Invalid number.")
        except ValueError:
            print("Please enter numbers only.")

    # checksum
    # print card type

def checksum(card):


if __name__ == "__main__":
    main()
