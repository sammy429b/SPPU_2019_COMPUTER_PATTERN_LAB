public class Fibonacci {

    private static long[] fibonacciCache;

    private static long fibonacci(int n) {
        if (n <= 1)
            return n;
        if (fibonacciCache[n] != 0)
            return fibonacciCache[n];
        long nthFibonacci = fibonacci(n - 1) + fibonacci(n - 2);
        fibonacciCache[n] = nthFibonacci;
        return nthFibonacci;
    }

    public static void main(String args[]) {
        int n = 90;
        fibonacciCache = new long[n + 1];
        System.out.println("Fibonacci of " + n + " is " + fibonacci(n));
    }
}