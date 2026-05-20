import random

for i in [19]:
    path = str(i)+".in"
    path2 = str(i-7)+".in"
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
                    if x == 42043:
                        x = 42044
                    ff.write(c[0] + " " + str(x) + " " + str(x+random.randrange(100)) + "\n")
                else:
                    ff.write(c[0] + " " + c[1] + " " + c[2] + "\n")


