from random import randrange

def correrTests(cantTests):
	file = open("PDitems75.txt","a")

	for j in range(cantTests):
		cantItems = randrange(1,1000,1)
		capacidad = 75

		file.write(str(cantItems)+" "+str(capacidad)+"\n")

		for i in range(cantItems):
			peso = randrange(1,2*capacidad,5)
			beneficio = randrange(1,150,1)

			file.write(str(peso)+" "+str(beneficio)+"\n")
	
		file.write("\n")

	file.close()

correrTests(1000)		