// codechef question no 1
// link: https://www.codechef.com/problems/THREEQ
// Author: Malay jeena

import java.util.Scanner;

public class OldSaintThreeQuest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while (t-->0) {
            int[] saintsAr = new int[3];
            for (int i = 0; i < 3; i++) {
                saintsAr[i] = sc.nextInt();
            }

            int[] heroAr = new int[3];
            for (int i = 0; i < 3; i++) {
                heroAr[i] = sc.nextInt();
            }

            int noOfOnesSaint = 0;
            for (int val:saintsAr) {
                if (val == 1) {
                    noOfOnesSaint++;
                }
            }

            int noOfOnesHero = 0;
            for (int val: heroAr) {
                if (val == 1) {
                     noOfOnesHero++;
                }
            }

            if (noOfOnesHero == noOfOnesSaint) {
                System.out.println("Pass");
            }else {
                System.out.println("Fail");
            }
        }
    }
}
