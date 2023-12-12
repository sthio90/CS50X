import re


def main():
    # Take user text input
    text = input("Text: ")

    # Count letters, words, and sentences
    count = count_letters(text)

    words = count_words(text)

    sentences = count_sentences(text)

    # Calculate and print grade
    grade = cl_index(count, words, sentences)
    if grade > 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


def count_letters(text):
    return sum(1 for char in text if char.isalpha())


def count_words(text):
    return len(text.split())


def count_sentences(text):
    return len(re.findall(r"[.!?]", text))


def cl_index(letter_count, word_count, sentence_count):
    L = letter_count * 100.0 / word_count
    S = sentence_count * 100.0 / word_count
    cl_grade = 0.0588 * L - 0.296 * S - 15.8
    return round(cl_grade)


if __name__ == "__main__":
    main()
