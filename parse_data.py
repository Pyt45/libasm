import sys
import re
import string
from check_file import check_file, check_exists

def     getkm():
    km = []
    for line in open("data.csv"):
        index = line.index(',')
        km.append(line[:index])
    km = km[1:]
    return km

def     getPrice():
    price = []
    for line in open("data.csv"):
        index = line.index(',')
        price.append(line[index + 1:-1])
    price = price[1:]
    return price

def     data_set_len():
    km = []
    price = []
    km = getkm()
    price = getPrice()

    if len(km) != len(price):
        print("Your data is invalide")
    return (int(len(km)))

def     fun(n):
    return lambda a : a * n

if __name__ == '__main__':
    file = check_exists("data.csv")
    if file:
        km = []
        price = []
        km = getkm()
        price = getPrice()
        print(km)
    else:
        print("Error file not found")
