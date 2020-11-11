# Basic
""" list1 = [1, 2, 3, 4] # list
set1 = {1, 2, 3} # set
tuple1 = (1, 2, 3) # tuple
dict1 = {"name" : "ayoub", "age" : 22}
print(type(dict1)) """
""" import random

arr = []

for i in range(0, 9):
    arr[i] = random.randrange(1, 10)

def printArr(arr):
    for i in range(len(arr)):
        print("{}".format(arr))

printArr() """

# Strings
""" a = " hello, worlD! "
print(a)
print(a[1])
print(a[2:5])
print(a.strip())
print(a[-5:-2])
print(a.upper())
print(a.lower())
print(a.replace('l', 'i'))
b = a.split(',')
print(b[1]) """
""" import numpy as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

time_study = pd.array([4, 7, 10, 20, 30, 45, 50, 70, 90, 100, 121, 132]).reshape(-1, 1)
score = pd.array([8, 9, 10, 12, 13, 15, 15, 16, 18, 19, 19, 20]).reshape(-1, 1)
model = LinearRegression()
model.fit(time_study, score)
plt.scatter(time_study, score)
plt.plot(pd.linspace(0, 70, 100).reshape(-1, 1), model.predict(pd.linspace(0, 70, 100).reshape(-1, 1)), 'r')
plt.ylim(0, 100)
plt.show() """



"""
./a.out (a=3, b=4, c=9, eq=4)
==> a * x^2 + b * x + c = eq
{
    delta = 
    x1 = 
    x2 = 
}
"""

import pandas as pd
import os
import string
import sys
"""
if os.path.exists("data.csv"):
	with open("data.csv") as f:
		print(f.read())
def parse_file(file_name, km, price):
	try:
		with open(file_name, "r") as f:
			km = []
			price = []
			for line in f:
				index = line.index(",")
				km.append(line[0:index])
				price.append(line[index+1:len(line) - 1])
	except:
		print("Ops! something went wrong")
	finally:
		f.close()
	return (km, price)
"""
def getPrice():
	price = []
	for line in open("data.csv").readlines():
		index = line.index(',')
		tmp = line[index + 1:-1]
		try:
			tmp = float(tmp)  /1000
		except ValueError:
			tmp = tmp
		price.append(tmp)
	price = price[1:]
	return price

def getKm():
	km = []
	for line in open("data.csv").readlines():
		index = line.index(',')
		tmp = line[:index]
		try:
			tmp = float(tmp) / 1000
		except ValueError:
			tmp = tmp
		km.append(tmp)
	km = km[1:]
	return km
def get_dataset_len():
	km = []
	price = []
	km = getKm()
	price = getPrice()
	if (len(km) != len(price)):
		print("Error: Your data set is incorrect")
		sys.exit(0)
	m = len(km)
	return (int(m))
if __name__ == '__main__':
	m = get_dataset_len()
	print(m)
