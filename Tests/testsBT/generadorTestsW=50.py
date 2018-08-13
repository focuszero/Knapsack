from random import randrange
from random import shuffle



file = open("instanciasGeneradasW=50.txt","a")
for j in range(20):

	file.write(str(j)+" "+str(50)+"\n")
	pesosYbeneficios = list()


	for i in range(j):
		peso = randrange(51,100,2)
		beneficio = randrange(1,150,5)
		pair = (peso,beneficio)
		pesosYbeneficios.append(pair)

	for k in range(20-j):
		peso = randrange(1,50,2)
		beneficio = randrange(1,150,5)
		pair = (peso,beneficio)
		pesosYbeneficios.append(pair)

	shuffle(pesosYbeneficios)


	for p in pesosYbeneficios:	
		file.write(str(p[0])+" "+str(p[1])+"\n")	
	
	file.write("\n")

file.close()	