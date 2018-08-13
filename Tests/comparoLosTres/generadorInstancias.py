from random import randrange



def correrTests(cantTests):
	file = open("instanciasGeneradas.txt","a")

	for j in range(cantTests):
		cantItems = randrange(1,20,1)
		capacidad = 100

		file.write(str(cantItems)+" "+str(capacidad)+"\n")

		for i in range(cantItems):
			peso = randrange(1,200,1)
			beneficio = randrange(1,150,1)

			file.write(str(peso)+" "+str(beneficio)+"\n")
	
		file.write("\n")

	file.close()

correrTests(1000)		