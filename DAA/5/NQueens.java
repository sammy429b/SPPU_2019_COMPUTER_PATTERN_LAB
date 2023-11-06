import java.util.Random;

public class NQueens {
    public static void main(String[] args) {
        int n = 8; // Change this to the desired board size

        int[][] board = new int[n][n];
        placeRandomQueen(board);
        solveNQueens(board, 0);
        printBoard(board);
    }

    static boolean solveNQueens(int[][] board, int col) {
        int n = board.length;
        if (col >= n) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;

                if (solveNQueens(board, col + 1)) {
                    return true;
                }

                board[i][col] = 0; // Backtrack
            }
        }
        return false;
    }

    static boolean isSafe(int[][] board, int row, int col) {
        int n = board.length;

        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    static void placeRandomQueen(int[][] board) {
        int n = board.length;
        Random random = new Random();
        int randomRow = random.nextInt(n);
        int randomCol = random.nextInt(n);
        board[randomRow][randomCol] = 1;
    }

    static void printBoard(int[][] board) {
        int n = board.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}

