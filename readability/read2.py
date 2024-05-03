from cs50 import get_string

text = get_string("Type your text: ")

letters = 0
for l in text:
    if l.isalpha():
        letters += 1

words = len(text.split())

sentences = text.count(".") + text.count("!") + text.count("?")

grade = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")