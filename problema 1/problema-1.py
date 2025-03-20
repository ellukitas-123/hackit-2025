def read(n_calles):
		n_inters = int(input())
		m = [[0] * n_iters for i in range(n_inters)]
		for i in range(n_calles):
				line = input().strip().split(" ")
				m[int(line[0]) - 1][int(line[1]) - 1] += 1
				m[int(line[1]) - 1][int(line[0]) - 1] += 1
		return m

def es_recorrido_euclidiano(matriz_grafo):
	impares = 0

	for i in range(len(matriz_grafo)):
		grado = 0
		for j in range(len(matriz_grafo[i])):
			grado += matriz_grafo[i][j]
	
	if grado % 2 != 0:
		impares += 1

	return impares == 0 or impares == 2

if __name__ == "__main__":
		while True:
			n_calles = int(input())

			if n_calles == 0:
				break

			if es_recorrido_euclidiano(read(n_calles)):
					print("SI")
			else:
					print("NO")