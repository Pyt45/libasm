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
import math
data = input().split(",")
# verion 1
# l = []
# for x in data:
#   num = int(x, 2)
#   if not num % 5:
#     l.append(x)

# print(",".join(l))

# version2

def reverse_num(num):
  l = []
  for x in num:
    l.append(x)
  l = l[::-1]
  return (l)
def check_binary(num):
  total = 0
  p = 0
  l = reverse_num(num)
  for i in l:
    total += int(i) * math.pow(2, p)
    p += 1
  return total % 5

l = []
for x in data:
  if not check_binary(x):
    l.append(x)

print(",".join(l))
