from random import randrange

def correrTests(cantTests):
	file = open("n=Wpolinomial.txt","a")

	for j in range(cantTests):
		cantItems = randrange(1,100,1)
		capacidad = cantItems

		file.write(str(cantItems)+" "+str(capacidad)+"\n")

		for i in range(cantItems):
			peso = randrange(1,2*capacidad,5)
			beneficio = randrange(1,150,1)

			file.write(str(peso)+" "+str(beneficio)+"\n")
	
		file.write("\n")

	file.close()

correrTests(300)		