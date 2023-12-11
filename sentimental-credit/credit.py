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

    # checksum
    # print card type

        // TODO calculate checksum using Luhn's algo
    int sum = 0;
    long cardNumber = card;
    int length = 0;
    while (cardNumber > 0)
    {
        int digit = cardNumber % 10;
        length++;
        if (length % 2 == 0)
        {
            digit *= 2;
            sum += digit / 10 + digit % 10;
        }
        else
        {
            sum += digit;
        }
        cardNumber /= 10;
    }

    // TODO check for card length and starting digits
    if (sum % 10 == 0)
    {
        // TODO Getting the first two digits
        while (card >= 100)
        {
            card /= 10;
        }
        int firstTwoDigits = card;

        if ((length == 15) && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 16) && (firstTwoDigits >= 51 && firstTwoDigits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (firstTwoDigits / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;

def checksum(card):
    return


if __name__ == "__main__":
    main()
