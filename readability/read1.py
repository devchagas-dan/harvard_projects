# CÓDIGO ESTÁ QUASE PRONTO FALTA SÓ AJUSTAR ONDE ESTIVER O PROBEMA

from cs50 import get_string

def main():
    text = get_string ("Type your text: ")
    letters = count_letters (text)
    words = count_words(text)
    sentences = count_sentences(text)
    level = grade (letters, sentences, words)

    print_grade(level)

def count_letters(text):
    letter = 0
    for i in text:
        if i.isalpha():
            letter += 1
    return letter

def count_words(text):
    words = 0
    for i in text:
        if i.isspace():
            words += 1
    words += 1
    return words

def count_sentences(text):
    sentence = 0
    for i in text:
        if i in [".", "!", "?"]:
            sentence += 1
            return sentence

def grade (letters, sentences, words):
    L = letters / words * 100
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index

def print_grade (index):
    if index < 1:
        print ("Before Grade 1")
    elif index >= 16:
        print ("Grade 16+")
    else:
        print(f"Grade {index}")

main()