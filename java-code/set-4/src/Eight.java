//WAP to demonstrate constructor overloading
public class Eight {
	public static void main(String[] args){
		new Figure(1).displayArea();
		new Figure(10, 10).displayArea();
		new Figure(15, 10).displayArea();
		new Figure(3, 4, 5).displayArea();
	}
}

class Figure {
	final double PI = 3.1415;
	double area;
	String type;

	// Constructor for circle
	Figure (double r){
		type = "Circle";
		area = PI *r * r;
		System.out.println(type + " created of radius " + r + " unit(s).");
	}
	
	// Constructor for rectangle/square
	Figure (double l, double b){
		type = l == b ? "Square" : "Rectangle";
		area = l * b;
		System.out.println(type + " created of length " + l + " and breadth " + b + " unit(s).");
	}
	
	// Constructor for triangle
	Figure (double s1, double s2, double s3){
		type = "Triangle";
		double s = (s1 + s2 + s3) / 2;
		area = Math.pow((s*(s - s1)*(s - s2)*(s - s3)), 0.5);
		System.out.println(type + " created of sides of length " + s1 + ", " + s2 + ", " + s3 + " unit(s).");
	}

	double displayArea(){
		System.out.println("Area of the " + type + " -> " + area + " sq. unit(s)");
		return area;
	}
}

// Output
// Circle created of radius 1.0 unit(s).
// Area of the Circle -> 3.1415 sq. unit(s)
// Square created of length 10.0 and breadth 10.0 unit(s).
// Area of the Square -> 100.0 sq. unit(s)
// Rectangle created of length 15.0 and breadth 10.0 unit(s).
// Area of the Rectangle -> 150.0 sq. unit(s)
// Triangle created of sides of length 3.0, 4.0, 5.0 unit(s).
// Area of the Triangle -> 6.0 sq. unit(s)
