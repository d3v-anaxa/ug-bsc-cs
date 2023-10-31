// WAP in which class Student inplements ClassTest interface 
// and use necessary methods to show name and obtained marks
import java.util.*;
public class Four {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int count;
        try {
            do {
                System.out.print("ENTRIES -> ");
                count = in.nextInt();

                if (count == 0) {
                    System.out.println("[PROGRAM EXITED]");
                    return;
                } else if (count < 0) {
                    System.out.println("(INVALID COUNT)");
                    continue;
                } else break;
            } while(true);

            // Create array
            Student[] arr = new Student[count];

            // Array Entries
            for( int i = 0; i < arr.length; i++)
                arr[i] = new Student(in);
            
            // Print Entries
            for (Student student : arr)
                student.display();
            
        } catch (Exception e){
            System.out.println("Exception occured!");
        } finally {
            in.close();
        }
    }
}

interface ClassTest {
    void display();
}

class Student implements ClassTest {
    String name;
    int marks;
    Student (Scanner in){
        in.nextLine();
        System.out.print("Enter name of student : ");
        this.name = in.nextLine();
        System.out.print("Enter obtained marks : ");
        this.marks = in.nextInt();
    }

    @Override
    public void display(){
        System.out.println(name + " | " + marks);
    }
}
// Output
// ENTRIES -> 3
// Enter name of student : Sam
// Enter obtained marks : 80
// Enter name of student : Molly
// Enter obtained marks : 50
// Enter name of student : George
// Enter obtained marks : 70
// Sam | 80
// Molly | 50

// Output
// ENTRIES -> 5
// Enter name of student : Luffy
// Enter obtained marks : 45
// Enter name of student : Naruto
// Enter obtained marks : 25
// Enter name of student : Light
// Enter obtained marks : 99
// Enter name of student : LeLouge
// Enter obtained marks : 99
// Enter name of student : Marin         
// Enter obtained marks : 50
// Luffy | 45
// Naruto | 25
// Light | 99
// LeLouge | 99
// Marin | 50

// Output
// ENTRIES -> 15
// Enter name of student : Nobita
// Enter obtained marks : fail
// Exception occured!
