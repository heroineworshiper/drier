#!/usr/bin/python

# generate the log table

import math


print("#include <stdint.h>")
print("const uint8_t log_table[] = {")
print("\t%d, // << 3 if i == 0" % (2047 >> 3))

for i in range(1, 100):
    value = -int(math.log(float(i) / 100) * 256)
    hint = ''
    if value >= 1024:
        hint = '// << 3 if i == {}'.format(i)
        value >>= 3
    elif value >= 512:
        hint = '// << 2 if i == {}'.format(i)
        value >>= 2
    elif value >= 256:
        hint = '// << 1 if i == {}'.format(i)
        value >>= 1

    print("\t%d, %s" % (value, hint))
print("};")
