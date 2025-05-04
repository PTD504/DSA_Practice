from os import *
from sys import *
from collections import *
from math import *

def capitalize_first_letter(word):
    return word[0].upper() + word[1:]

def convertString(str):
    # Write your code here
    words = str.split()

    words = [capitalize_first_letter(word) for word in words]

    sentence = " ".join(words)

    return sentence