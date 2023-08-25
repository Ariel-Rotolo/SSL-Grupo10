import time
import random

# Bubble sort en Python
def bubbleSort(array):
    len_arr = len(array) # Guardo la longitud del array
    for i in range(len_arr): # Primer loop que recorre todo el array
        for j in range(0, len_arr - i - 1): # Segundo loop comparando los elementos adyacentes entre si
            if array[j] > array[j + 1]: # Cambiar > a < para hacer orden descendente
                arr[j], arr[j+1] = arr[j+1], arr[j] # Hace un cambio entre los elementos del array

if __name__ == "__main__":
    arr = [random.randint(1,100000) for _ in range(10000)]
    start_time = time.time()
    bubbleSort(arr)
    end_time = time.time()
    print(arr)
    print("Tiempo de ejecución en segundos:", end_time - start_time)
