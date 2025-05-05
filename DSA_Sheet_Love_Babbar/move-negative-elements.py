from os import *
from sys import *
from collections import *
from math import *

def separateNegativeAndPositive(nums):
    # write your code here
    neg, pos, i = 0, len(nums) - 1, 0

    while i < pos:
        if nums[i] < 0:
            nums[i], nums[neg] = nums[neg], nums[i]
            i += 1
            neg += 1
        else:
            nums[i], nums[pos] = nums[pos], nums[i]
            pos -= 1
    
    return nums
    