class   Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def getName(self):
        return self.name
    
    def setName(self, other):
        self.name = other

class Student(Person):
    def __init__(self, name, age, year):
        super().__init__(name, age)
        self.year = year
    
    def getYear(self):
        return self.year


class MyList:
    def __iter__(self):
        self.a = 1
        return self
    
    def __next__(self):
        if self.a <= 20:
            x = self.a
            self.a += 1
            return x
        else:
            raise StopIteration


class Solution(object):
    def twoSum(self, nums, target):
        num = {}
        for i, v in enumerate(nums):
            n = target - v
            print("n = {}".format(n))
            if n not in num:
                num[v] = i
            else:
                return [num[n], i]


l = ["apple", "orange", "banana"]

for i in enumerate(l):
    print(i)