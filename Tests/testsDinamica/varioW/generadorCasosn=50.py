from random import randrange



def correrTests(cantTests):
	file = open("instanciasGeneradasn=50.txt","a")

	for j in range(cantTests):
		cantItems = 50
		capacidad = randrange(1,5000,5)

		file.write(str(cantItems)+" "+str(capacidad)+"\n")

		for i in range(cantItems):
			peso = randrange(1,capacidad+500,5)
			beneficio = randrange(1,150,1)

			file.write(str(peso)+" "+str(beneficio)+"\n")
	
		file.write("\n")

	file.close()

correrTests(1000)		