with open("8.out", "r") as file:
    for riga in file:
        if int(riga.strip()) > 100:
            print("ERROR")