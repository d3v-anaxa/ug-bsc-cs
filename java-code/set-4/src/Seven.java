// Demonstrate multilevel inheritance

import java.util.*;
public class Seven {
    public static void main(String[] args){
        new A().output();
        new B().output();
        new C().output();
    }
}

class A {
    void output(){
        System.out.println("Method of class " + this.getClass().getSimpleName() + " has been called.");
    }
}
class B extends A {}
class C extends B {}

// CHART
// A --> B --> C

//Output
// Method of class A has been called.
// Method of class B has been called.
// Method of class C has been called.
