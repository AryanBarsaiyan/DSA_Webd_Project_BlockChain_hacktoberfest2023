// Java program to find GCD using Euclidean Algorithm

import java.lang.*;
import java.util.*;
import java.util.Scanner;

class EuclidAlgo{

  public static int gcd(int a, int b) {
    if (a == 0)
      return b;

    return gcd(b % a, a); // Recursion call
  }

  public static void main(String[] args) {
    int a, b, g;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter First Number: "); 
    a = sc.nextInt(); 
    System.out.println("Enter Second Number: ");
    b = sc.nextInt();
    g = gcd(a, b); // calling gcd function
    System.out.println("GCD(" + a + "," + b
        + ") = " + g);

  }
}
