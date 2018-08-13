from random import randrange


file = open("testFB.txt","a")

for j in range(26):
	cantItems = j
	capacidad = 100

	file.write(str(cantItems)+" "+str(capacidad)+"\n")

	for i in range(cantItems):
		peso = randrange(1,150,5)
		beneficio = randrange(1,100,5)

		file.write(str(peso)+" "+str(beneficio)+"\n")
	
	file.write("\n")

file.close()
