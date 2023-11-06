import java.util.Random;
import java.util.Scanner;
public class RandomizedQuicksort {
    public static int partition(int[] arr, int start, int end) {
        Random random = new Random();
        int pivotIndex = random.nextInt(end - start + 1) + start;
        int pivot = arr[pivotIndex];
        int temp = arr[start];
        arr[start] = arr[pivotIndex];
        arr[pivotIndex] = temp;

        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot) {
                count++;
            }
        }
        pivotIndex = start + count;
        temp = arr[start];
        arr[start] = arr[pivotIndex];
        arr[pivotIndex] = temp;

        int i = start, j = end;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }
        return pivotIndex;
    }
    public static void quickSort(int arr[], int start, int end) {
        if (start >= end)
            return;

        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int size = sc.nextInt();
        int[] arr = new int[size];
        System.out.print("Enter unsorted array elements: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        quickSort(arr, 0, size - 1);

        System.out.print("Sorted Array: ");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
