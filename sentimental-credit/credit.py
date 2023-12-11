import cs50


def main():
    # Get user card input
    while True:
        card = cs50.get_int("Number: ")
        if card > 0:
            break
        else:
            print("Invalid number.")

    if is_valid_card(card):
        print_card_type(card)
    else:
        print("INVALID")


def is_valid_card(card):
    card_str = str(card)
    sum = 0

    # Luhn’s Algorithm
    for i, digit in enumerate(reversed(card_str)):
        num = int(digit)
        if i % 2 == 1:
            num *= 2
            if num > 9:
                num -= 9
        sum += num

    return sum % 10 == 0


def print_card_type(card):
    card_str = str(card)
    length = len(card_str)
    first_two_digits = int(card_str[:2])

    if length == 15 and first_two_digits in [34, 37]:
        print("AMEX")
    elif length == 16 and 51 <= first_two_digits <= 55:
        print("MASTERCARD")
    elif length in [13, 16] and card_str.startswith("4"):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
