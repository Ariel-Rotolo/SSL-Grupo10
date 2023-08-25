using System.Diagnostics;

class Program
{
    static List<ulong> GenerarFibonacci(int n)
    {
        List<ulong> secuenciaFibonacci = new();  // Inicio con una lista vacía
        ulong a = 0, b = 1;  // Establezco los dos primeros números de la secuencia Fibonacci
        for (int i = 0; i < n; i++) // Realizo un bucle que se ejecutará 'n' veces
        {
            secuenciaFibonacci.Add(a);  // Añado el número actual 'a' a la lista
            ulong temp = a;
            a = b;
            b = temp + b;  // Actualizo 'a' y 'b' siendo la siguiente secuencia la suma de las ultimas dos
        }
        return secuenciaFibonacci;  // Devuelvo la lista con los números de Fibonacci
    }

    static void Main()
    {
        Stopwatch stopwatch = new();
        stopwatch.Start();
        List<ulong> secuenciaFibonacci = GenerarFibonacci(100000); // Llamo a la función para generar 100,000 números de Fibonacci
        stopwatch.Stop();
        // Console.WriteLine(string.Join(", ", secuenciaFibonacci));
        Console.WriteLine("Tiempo de ejecución en milisegundos: " + stopwatch.ElapsedMilliseconds); // Imprimo el tiempo de ejecución total en milisegundos
    }
}
