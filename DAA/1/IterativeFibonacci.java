public class IterativeFibonacci {

    private static void fibonacci(int n) {
        long a = 0;
        long b = 1;
        long c = 0;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
            System.out.print(c + " ");
        }
    }

    public static void main(String[] args) {
        int n = 90;
        fibonacci(n);
    }

}