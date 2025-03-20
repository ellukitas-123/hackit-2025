def calculardimension(numero):
    return len(str(numero))
def numerotoarray(numero, dimension):
    array = [0] * dimension
    dimactual = 0
    dimoriginal = dimension
    while dimactual < dimoriginal:
        divisor = 10 ** (dimoriginal -dimactual - 1)
        array[dimactual] = numero // divisor
        numero %= divisor
        dimactual += 1
    return array
def arraytonumber(array):
    numero = 0
    for digit in array:
        numero = numero * 10 + digit
    return numero

def encontrarcapicuasiguiente(array, dimension):


    numero_actual = arraytonumber(array) + 1

    if dimension == 1:
        return numero_actual

    else:
        while True:
            if str(numero_actual) == str(numero_actual)[::-1]:
                return numero_actual
            numero_actual += 1



def encontrardistancia(numeroorigen,numerodestino):
    return numerodestino - numeroorigen

if __name__ == "__main__":
    numero = int(input(" "))
    contadormax = numero
    while i < contadormax:
            numero = int(input(" "))
            dimension = calculardimension(numero)
            array = numerotoarray(numero, dimension)
            capicua_siguiente = encontrarcapicuasiguiente(array, dimension)
            distancia = encontrardistancia(numero, capicua_siguiente)
            print(distancia)
            i += 1
