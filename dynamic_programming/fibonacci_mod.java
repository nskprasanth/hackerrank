/**
  * https://www.hackerrank.com/challenges/fibonacci-modified
  * Prasanth Kalapatapu
  * Sep 7, 2015
  */

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int b = in.nextInt();
    int n = in.nextInt();
    BigInteger[] fib = new BigInteger[n];
    fib[0] = BigInteger.valueOf(a);
    fib[1] = BigInteger.valueOf(b);
    for (int i=2;i<n;++i) {
      fib[i] = fib[i-1].multiply(fib[i-1]).add(fib[i-2]);
    }
    System.out.println(fib[n-1]);
  }
}
