matriz_grafo = [];
impares = 0

for i in range(len(matriz_grafo)):
	grado = 0
	for j in range(len(matriz_grafo[i])):
		grado += matriz_grafo[i][j]
	
	if grado % 2 != 0:
		impares += 1

if impares == 0 or impares == 2:
	print("SI")
else:
	print("NO")