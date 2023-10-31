// Demonstrate concept of dynamic method dispatch

import java.util.*;
public class Ten {
    public static void main(String[] args){
        A ref;
        ref = new A();
        ref.output();
        ref = new B();
        ref.output();
        ref = new C();
        ref.output();
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
