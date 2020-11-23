data = input()
# import math
# data = input().split(",")
# version2

# def reverse_num(num):
#   l = []
#   for x in num:
#     l.append(x)
#   l = l[::-1]
#   return (l)
# def check_binary(num):
#   total = 0
#   p = 0
#   l = reverse_num(num)
#   for i in l:
#     total += int(i) * (2 ** p)
#     p += 1
#   return total % 5

# l = []
# for x in data:
#   if not check_binary(x):
#     l.append(x)

# print(",".join(l))
# verion 1
l = []
# for x in data:
#   num = int(x, 2)
#   if not num % 5:
#     l.append(x)

# print(",".join(l))
# ==========================================
# data = input().split(" ")
# version 1
# s = set(data)
# l = sorted(list(s))
# print(" ".join(l))
# version 2
# [data.remove(i) for i in data if data.count(i) > 1]
# data.sort()
# print(" ".join(data))
# version 3
# out_data = []
# for i in data:
#   if i not in out_data:
#     out_data.append(i)
# print(" ".join(sorted(out_data)))
# val = []
# def check_digit(s=str):
#   flag = 1
#   for i in range(len(s)):
#     if int(s[i]) % 2:
#       flag = 0
#   return flag

# for x in range(1000, 3001):
#   flag = check_digit(str(x))
#   if flag == 1:
#     val.append(str(x))

# print(",".join(val))

def is_digit(num=int):
  return ord(num) >= 48 and ord(num) <= 57

def is_letter(s=str):
  for i in s:
    return (ord(i) >= 97 and ord(i) <= 122) or (ord(i) >= 65 and ord(i) <= 90)

def cound_word_digit(data):
  count = 0
  letter = 0
  for x in data:
    if is_digit(x):
      count += 1
    if is_letter(str(x)):
      letter += 1
  return (count, letter)

def is_upper(s=str):
  return ord(s) >= 65 and ord(s) <= 90

def is_lower(s=str):
  return ord(s) >= 97 and ord(s) <= 122

def count_upper_lower(data):
  u = 0
  l = 0
  for x in data:
    if is_upper(x):
      u += 1
    elif is_lower(x):
      l += 1
  return (u, l)

c, w = cound_word_digit(data)
u,l = count_upper_lower(data)
print(f'LETTERS {w} \nDIGITS {c}')
print(f'UPPER {u} \nLOWER {l}')
