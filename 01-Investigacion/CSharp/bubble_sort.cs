using System.Diagnostics;

class Program {
    static void BubbleSort(int[] array) {
        int len_arr = array.Length; // Longitud del array
        int temp; // Variable temporal para el intercambio
        for (int i = 0; i < len_arr; i++) { // Primer loop
            for (int j = 0; j < len_arr - i - 1; j++) { // Segundo loop
                if (array[j] > array[j + 1]) { // Cambia > por < para orden descendente
                    // Intercambio de elementos
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    static void Main() {
        int[] array = new int[10000];
        Random random = new();

        for (int i = 0; i < array.Length; i++) {
            array[i] = random.Next(1, 100001); // Genera números aleatorios entre 1 y 100000
        }

        Stopwatch time = new();
        time.Start();
        BubbleSort(array);
        time.Stop();

        foreach (int item in array) {
            Console.Write(item + " ");
        }

        Console.WriteLine("\nTiempo de ejecución en milisegundos: " + time.ElapsedMilliseconds);
    }
}
