import pyperclip
import re

REGEX = '#include  *\"(\S*)\"'
main = open("main.cpp")

result = []
for line in main:
    temp = re.search(REGEX,line)
    if(temp):
        a = open(temp.group(1))
        result.append(a.read())
        a.close()
    else:
        result.append(line)

result = "\n".join(result)
print(result)
pyperclip.copy(result)
print("Copiado.")

