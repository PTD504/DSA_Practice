from sys import *
from collections import *
from math import *

def largestElement(arr: [], n: int) -> int:

    # Write your code from here.
    mx = arr[0]

    for i in range(1, len(arr)):
        mx = mx if mx > arr[i] else arr[i]
    
    return mx
