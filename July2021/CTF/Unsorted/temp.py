s = "cidb~5gcpvf1q45kZ4vZk5qZs6w|Zv6fpw6x";
r = "";
for x in s:
    r = r + chr(ord(x) ^ 5)
print(r)
