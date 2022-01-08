import csv
import matplotlib.pyplot as plt

# x axis values
x = []
# corresponding y axis values
y = []

with open('fivehundred.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    counter = 0
    start = 20
    sumall = 0
    for row in csv_reader:
        sumall += int(row[1])
        counter += 1
        if(counter == 100):
            x.append(start)
            y.append(sumall / 100)
            start += 1
            counter = 0
            sumall = 0



# plotting the points
plt.plot(x, y)
 
# naming the x axis
plt.xlabel('x - axis')
# naming the y axis
plt.ylabel('y - axis')
plt.xticks(x)
# giving a title to my graph
plt.title('Operations per chunk')
 
# function to show the plot
plt.show()