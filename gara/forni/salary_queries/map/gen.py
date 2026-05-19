import random

for i in [6,7,8,9,14]:
    path = str(i)+".in"
    path2 = str(i+14)+".in"
    with open(path, "r")  as f:
        with open(path2, "w") as ff:
            a = f.readline()
            ff.write(a + "\n")
            q= int(a.split(" ")[1])
            b=f.readline()
            ff.write(b + "\n")
            for j in range(q):
                c = f.readline().split(" ")
                if c[0] == "?":
                    x = int(c[1])
                    ff.write(c[0] + " " + str(x) + " " + str(x+random.randrange(100)) + "\n")
                else:
                    ff.write(c[0] + " " + c[1] + " " + c[2] + "\n")


