import cs50
# TODO

def main():
    # Get user card input
    while True:
        try:
            card = cs50.get_int("Number: ")
            if card > 0:
                break
            else:
                print("Invalid number.")
        except ValueError:
            print("Please enter numbers only.")

    # TODO calculate checksum using Luhn's algo
    sum = 0
    card_number = card
    length = 0
    while card_number > 0:
        digit = cardNumber % 10
        length += 1
        if length % 2 == 0:
            digit *= 2
            sum += digit // 10 + digit % 10
        else
            sum += digit
        cardNumber //= 10


    # TODO check for card length and starting digits
    if sum % 10 == 0:
        # Getting the first two digits
        first_two_digits = int(str(card)[:2])

        if (length == 15) and (first_two_digits == 34 or first_two_digits == 37):
            print("AMEX")
        elif (length == 16) and (51 <= first_two_digits <= 55):
            print("MASTERCARD")
        elif (length == 13 or length == 16) and (first_two_digits // 10 == 4):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
