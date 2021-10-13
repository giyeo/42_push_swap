import os
from itertools import permutations
three = permutations([1, 2, 3], 3)
four = permutations([1, 2, 3, 4], 4)
five = permutations([1, 2, 3, 4, 5], 5)

for each in three:
	os.system("./pushswap " + str(each[0]) + " " + str(each[1]) + " " + str(each[2]))

for each in four:
	os.system("./pushswap " + str(each[0]) + " " + str(each[1]) + " " + str(each[2]) + " " + str(each[3]))

for each in five:
	os.system("./pushswap " + str(each[0]) + " " + str(each[1]) + " " + str(each[2]) + " " + str(each[3]) + " " + str(each[4]))