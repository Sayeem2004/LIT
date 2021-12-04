import random

def unshuffle(shuffled_message, key):
    random.seed(key)
    l = [i for i in range(len(shuffled_message))]
    random.shuffle(l)
    out = [None] * len(shuffled_message)
    for i, x in enumerate(l):
        out[x] = shuffled_message[i]
    return ''.join(out)

f = open("flag.txt", "r").read().split("\n")
for i in range(0, 1000):
    s = unshuffle(f[0], i);
    print(s)
