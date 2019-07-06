#!/usr/bin/python

import random
import sys

for i in range(1, 41):
    while True:
        a = random.randrange(1,10001)
        b = random.randrange(1,10001)
        if a <= b:
            break;

    print a,
    print b
