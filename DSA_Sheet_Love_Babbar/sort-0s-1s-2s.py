from os import *
from sys import *
from collections import *
from math import *

from sys import stdin,setrecursionlimit
setrecursionlimit(10**7)

def sort012(arr, n) :

	# write your code here
    # don't return anything 
    m, zero_index, two_index = 0, 0, n - 1

    while m <= two_index:
        if arr[m] == 0:
            arr[m], arr[zero_index] = arr[zero_index], 0
            m += 1
            zero_index += 1
        elif arr[m] == 1:
            m += 1
        else:
            arr[m], arr[two_index] = arr[two_index], arr[m]
            two_index -= 1


#taking inpit using fast I/O
def takeInput() :
	n = int(input().strip())

	if n == 0 :
		return list(), 0

	arr = list(map(int, stdin.readline().strip().split(" ")))

	return arr, n



def printAnswer(arr, n) :
    
    for i in range(n) :
        
        print(arr[i],end=" ")
        
    print()
    
#main

t = int(input().strip())
for i in range(t) :

    arr, n= takeInput()
    sort012(arr, n)
    printAnswer(arr, n)
