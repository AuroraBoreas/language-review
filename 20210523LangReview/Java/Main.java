/*
 * Java, meta review
 * 
 * @ZL, 20210530
 * 
 * */

import java.util.Scanner;
import javax.swing.JOptionPane;
import java.util.Random;
import java.util.ArrayList;
import cnmJava.A;
import cnmJava.B;
import cnmInterface.*;

public class Main {
	
	public static boolean isLeapYear(int year) {
		return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
	}
	
	public static boolean setDate(int y, int m, int d) {
		if(y < 0) { return false; }
		if(m < 0 || m > 12) { return false; }
		if(d < 0 || d > 31) { return false; }
		switch(m) {
		case 2: 
			if(isLeapYear(y)) {
				if(d > 29) { return false; }
			} else {
				if(d > 28) { return false; }
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(d > 30) { return false; }
			break;
		default:
			System.out.println("nothing biggy");
			break;
		}
		return true;
	}
	
	static int fibonacci(int n) {
		return n < 2 ? 1 : fibonacci(n-1) + fibonacci(n-2);
	}
	
	static int factorial(int n) {
		return n < 2 ? 1 : n * factorial(n-1);
	}
	
	public static void main(String[] args) {
		System.out.println("\n=== Get Started ===");
		System.out.println("hello TS");
		System.out.println("hello SCY");

		System.out.println("\n=== Variable ===");
		/*
		 * [ variable ]
		 * ===
		 * primitive types(meta data): CSIL FD BBD
		 * ===
		 */
		int x0; x0 = 69;
		String rv = String.format("x0 = %s", x0);
		System.out.println(rv);
		
		String x = "TS";
		String y = "ZL";
		System.out.println(String.format("before swap, x = %s, y = %s", x, y));
		String tmp = x;
		x = y;
		y = tmp;
		System.out.println(String.format("after swap,  x = %s, y = %s", x, y));
		
		/*
		 * [ iostream ]
		 */
		Scanner scanner = new Scanner(System.in);
		System.out.println("What is your name?");
		// String name = scanner.nextLine();
		// System.out.println(String.format("hello %s", name));
		scanner.close();
		
		System.out.println("\n=== Variable ===");
		/*
		 * [ statement ]
		 * ===
		 * A
		 * R
		 * L
		 * A
		 * B
		 * A
		 * C
		 * O
		 * O
		 * ===
		 * */
		int x1 = 69, y1 = 42;
		System.out.println(String.format("x=%s, y=%s; x+y : %s", x1, y1, x1 + y1));
		System.out.println(String.format("x=%s, y=%s; x-y : %s", x1, y1, x1 - y1));
		System.out.println(String.format("x=%s, y=%s; x*y : %s", x1, y1, x1 * y1));
		System.out.println(String.format("x=%s, y=%s; x/y : %s", x1, y1, x1 / y1));
		System.out.println(String.format("x=%s, y=%s; x%%y : %s", x1, y1, x1 % y1));
		
		System.out.println("\n=== GUI ===");
		/*
		 * [ GUI ]
		 * ===
		 * using javax.swing.JOptionPane
		 * ===
		 * */
		String name = JOptionPane.showInputDialog("Enter your name: ");
		JOptionPane.showMessageDialog(null, "hello " + name);
		
		double a, b;
		a = Double.parseDouble(JOptionPane.showInputDialog("Enter a: "));
		b = Double.parseDouble(JOptionPane.showInputDialog("Enter b: "));
		JOptionPane.showMessageDialog(null, "hypotenus: " + Math.sqrt(a * a + b * b));
		
		System.out.println("\n=== Random ===");
		Random rnd = new Random();
		int x2 = rnd.nextInt(6);
		double y2 = rnd.nextDouble();
		boolean z3 = rnd.nextBoolean();
		System.out.println(String.format("random x = %s, random y = %s, random bool z = %s", x2, y2, z3));
		
		System.out.println("\n=== ControlFlow ===");
		/*
		 * [ control flow ]
		 * ===
		 * if...else if...else
		 * switch...case...default
		 * try...catch...finally
		 * ===
		 * */
		
		int smh = rnd.nextInt(10);
		if(smh % 2 == 0) {
			System.out.println(String.format("smh = %s, it is even", smh));
		} else {
			System.out.println(String.format("smh = %s, it is odd", smh));
		}
		boolean legalDate = setDate(2021, 2, 31);
		System.out.println(String.format("setDate(2021, 2, 31) : %s", legalDate));
		
		System.out.println("\n=== Loop ===");
		/*
		 * [ loop ]
		 * ===
		 * while
		 * do while
		 * for
		 * ===
		 * */
		int[] numbers = { 1, 2, 3, 4 };
		for(int i=0; i<numbers.length; ++i) {
			System.out.println(String.format("%s, %s", i, numbers[i]));
		}
		System.out.println();
		
		int i = 0;
		while(i < numbers.length) {
			System.out.println(String.format("%s, %s", i, numbers[i]));
			i++;
		}
		System.out.println();
		
		i = numbers.length - 1;
		do {
			System.out.println(String.format("%s, %s", i, numbers[i]));
			--i;
		} while (i >= 0);
		System.out.println();
		
		for(int elem : numbers) {
			System.out.print(elem + " ");
		}
		System.out.println();
		
		System.out.println("\n=== Wrapper Class ===");
		/*
		 * [ wrapper class ]
		 * ===
		 * provides a way to user primitive data types as reference data types
		 * 
		 * | primitive		| wrapper
		 * ==========================
		 * | char			| Character
		 * | int			| Integer
		 * | double			| Double
		 * | boolean		| Boolean
		 * 
		 * # same concept in C#
		 * 
		 * (C I D B)
		 * ===
		 * */
		
		Character a1 = 'c';
		Integer a2 = 69;
		Boolean a3 = true;
		Double a4 = 3.14;
		String a5;
		a5 = a3 ? "true" : "false";
		System.out.println(a5);
		
		System.out.println("\n=== Class ===");
		Wife myWife = new Wife();
		System.out.println(myWife.toString());
		Wife myWife2 = new Wife("SCY", 35);
		System.out.println(myWife2.toString());
		
		// B b1 = new B(1); // error out
		// System.out.println(b1.toString());
		// interface
		Fish fish = new Fish();
		fish.hunt();
		fish.flee();

		System.out.println("\n=== Datastructure ===");
		ArrayList<String> wives = new ArrayList<String>();
		wives.add("TS");
		wives.add("SCY");
		for(int j=0; j<wives.size(); ++j) {
			System.out.print(wives.get(j) + " ");
		}
		System.out.println();
		System.out.println(wives);
		
		wives.stream().forEach((elem)->{
			System.out.print(elem + " ");
		});
		System.out.println();
		
		System.out.println("\n=== Algorithm ===");
	}

}
