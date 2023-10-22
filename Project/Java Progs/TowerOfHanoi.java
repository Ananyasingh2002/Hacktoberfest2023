public class TowerOfHanoi {
    public static void main(String[] args) {
        int n = 3; // Change this to the number of disks you want to solve for
        solveHanoi(n, 'A', 'B', 'C');
    }

    public static void solveHanoi(int n, char source, char auxiliary, char target) {
        if (n == 1) {
            System.out.println("Move disk 1 from peg " + source + " to peg " + target);
            return;
        }

        solveHanoi(n - 1, source, target, auxiliary);
        System.out.println("Move disk " + n + " from peg " + source + " to peg " + target);
        solveHanoi(n - 1, auxiliary, source, target);
    }
}
