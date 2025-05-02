from os import *
from sys import *
from collections import *
from math import *

def sumOfMaxMin(arr):
    # Write your code here
    mn, mx = arr[0], arr[0]

    for i in range(1, len(arr)):
        if arr[i] > mx:
            mx = arr[i]
        elif arr[i] < mn:
            mn = arr[i]
    
    return mn + mx