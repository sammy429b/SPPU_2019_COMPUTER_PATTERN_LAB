import java.util.Arrays;
import java.util.Scanner;

public class FractionalKnapsack {

    static class Item implements Comparable<Item> {
        int weight;
        int profit;
        double profitPerWeight;

        Item(int weight, int profit, double profitPerWeight) {
            this.weight = weight;
            this.profit = profit;
            this.profitPerWeight = profitPerWeight;
        }

        public int compareTo(Item o) {
            if (this.profitPerWeight > o.profitPerWeight) {
                return -1;
            } else if (this.profitPerWeight < o.profitPerWeight) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of items: ");
        int n = sc.nextInt();
        int[] weight = new int[n];
        int[] profit = new int[n];

        // input weight and profit of each item
        System.out.println("Enter the weight and profit of each item:");
        for (int i = 0; i < n; i++) {
            weight[i] = sc.nextInt();
            profit[i] = sc.nextInt();
        }

        // input capacity of knapsack
        System.out.print("Enter the capacity of knapsack: ");
        int capacity = sc.nextInt();

        // storing all items in array
        Item[] item = new Item[n];
        for (int i = 0; i < n; i++) {
            Item itm = new Item(weight[i], profit[i], (double) profit[i] / weight[i]);
            item[i] = itm;
        }

        // sorting items in decreasing order of profit per weight
        Arrays.sort(item);

        // calculating maximum profit
        int rc = capacity;
        double valueBag = 0;
        for (int i = 0; i < n; i++) {
            if (item[i].weight <= rc) {
                valueBag = valueBag + item[i].profit;
                rc = rc - item[i].weight;
            } else {
                valueBag = valueBag + item[i].profit * ((double) rc / item[i].weight);
                rc = 0;
                break;
            }
        }
        System.out.print(valueBag);
        sc.close();
    }
}

// Time Complexity: O(n * log(n))
// Space Complexity: O(n)