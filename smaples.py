import sys
from random import randint


data_count = int(sys.argv[1])
out_file = sys.argv[2]
with open(out_file, "w") as file:
    for i in range(data_count):
        randomNum = randint(1, 1000000)
        line = str(randomNum) + '\n'
        file.write(line)
