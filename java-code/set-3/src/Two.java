// WAP in with Circle and Rectangle extends abstract class Shape
// and overrides abstract method area

import java.util.*;

public class Two {
	public static void main (String[] args){
		Scanner in = new Scanner(System.in);
		System.out.println("1. Create Circle.");
		System.out.println("2. Create Rectangle.");
		System.out.println("3. Exit.\n");
		System.out.print("Enter choice -> ");
		try {
			switch (in.nextInt()){
				case 1:
					new Circle().area();
					break;
				case 2:
					new Rectangle().area();;
					break;
				case 3:
					System.out.println("[PROGRAM EXITED]");
					in.close();
					return;
				default:
					System.out.println("[INVALID CHOICE]");
					break;
			}
		} catch (Exception e){ 
			System.out.println("Exception Caught");
			System.out.println(e);
		} finally {
			in.close();
		}
	}
}

abstract class Shape {
	final double PI = 3.1415;
	abstract double area();
}

class Circle extends Shape {
	double radius;
	double area;
	Circle (){
		Scanner in = new Scanner(System.in);
		System.out.print("Enter radius -> ");
		radius = in.nextDouble();
		area = PI * radius * radius;
		in.close();
	}

	@Override
	double area(){
		System.out.println("Area of " + this.getClass().getSimpleName() + " -> " + area);	
		return area;
	}
}

class Rectangle extends Shape {
	double l, b, area;
	Rectangle (){
		Scanner in = new Scanner(System.in);
		System.out.print("Enter length -> ");
		l = in.nextDouble();
		System.out.print("Enter breadth -> ");
		b = in.nextDouble();
		area = l * b;
		in.close();
	}

	@Override
	double area(){
		System.out.println("Area of " + this.getClass().getSimpleName() + " -> " + area);	
		return area;
	}
}

// Output
// 1. Create Circle.
// 2. Create Rectangle.
// 3. Exit.
// 
// Enter choice -> 1
// Enter radius -> 7
// Area of Circle -> 153.9335

// Output
// 1. Create Circle.
// 2. Create Rectangle.
// 3. Exit.
// 
// Enter choice -> 2
// Enter length -> 10
// Enter breadth -> 15
// Area of Rectangle -> 150.0


// Output
// 1. Create Circle.
// 2. Create Rectangle.
// 3. Exit.
// 
// Enter choice -> 3
// [PROGRAM EXITED]

// Output 
// 1. Create Circle.
// 2. Create Rectangle.
// 3. Exit.
// 
// Enter choice -> 15
// [INVALID CHOICE]
