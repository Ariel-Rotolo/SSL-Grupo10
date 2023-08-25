import time # Importo la biblioteca time para medir el tiempo de ejecución

def generar_fibonacci(n):
    secuencia_fibonacci = [] # Comienzo con una lista vacia
    a, b = 0, 1 # Utilizo los primeros 2 numeros de la secuencia
    for _ in range(n): # Genera n numeros de fibonacci
        secuencia_fibonacci.append(a) # Añado el número actual 'a' a la lista
        a, b = b, a + b # Actualizo los valores de 'a' y 'b' siendo b = a + b
    return secuencia_fibonacci

if __name__ == "__main__":
    start_time = time.time()
    fibonacci_numbers = generar_fibonacci(100000) # Genera una lista de 100.000 numeros de fibonacci
    end_time = time.time()
    # print(fibonacci_numbers)
    print("Tiempo de ejecución en segundos:", end_time - start_time)
