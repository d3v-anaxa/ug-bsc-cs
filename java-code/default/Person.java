import java.util.Scanner;

public class Person {
    String name;
    char gender;
    int age;

    public void read(){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter name : ");
        this.name = in.next();
        System.out.print("Enter gender [m/f] : ");
        this.gender = in.next().charAt(0);
        System.out.print("Enter age : ");
        this.age = in.nextInt();
    }

    public void display(){
        System.out.println("Name   : " + this.name);
        System.out.println("Gender : " + this.gender);
        System.out.println( "Age   : " + this.age);
    }

}
class Student extends Person {
    int roll;
    @Override
    public void read() {
        super.read();
        Scanner in = new Scanner(System.in);
        System.out.print("Enter roll number : ");
        this.roll = in.nextInt();
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Roll. no. " + this.roll);
    }

    public static void main(String[] args) {
        Student xyz = new Student();
        xyz.read();
        xyz.display();
    }
}