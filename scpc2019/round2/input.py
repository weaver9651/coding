#!/usr/bin/python

import random
import sys

T = input()
num = input()
print T
for i in range(1, T+1):
    print num
    for i in range(1, num+1):
        a = random.randrange(1, 10)
        print a,
        sys.stdout.write(" ")
    sys.stdout.write("\n")
    for i in range(1, num+1):
        a = random.randrange(1, 10)
        print a,
        sys.stdout.write(" ")
    sys.stdout.write("\n")
