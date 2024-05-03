from cs50 import get_string


def main():
    text = get_string("Type your text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    level = grade(letters, sentences, words)

    print_grade(level)


def count_letters(text):
    letters = 0
    words = text.split()

    for word in words:
        for letter in word:
            if letter.isalpha():
                letters += 1
    return letters


def count_words(text):
    words = 0
    for i in text:
        if i.isspace():
            words += 1
    words += 1
    return words


def count_sentences(text):
    sentences = 0
    for i in text:
        if i == "." or i == "!" or i == "?":
            sentences += 1
    return sentences


def grade(letters, sentences, words):
    L = letters / words * 100
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


def print_grade(index):
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()