// Demonstrate overriding

import java.util.*;
public class Nine {
    public static void main(String[] args){
        new Dog().call();
        new Cat().call();
    }
}

class Dog {
    void call(){
        System.out.println("A dog barks!");
    }
}
class Cat extends Dog {
    @Override
    void call(){
        System.out.println("A cat meows!");
    }
}

// Output
// A dog barks!
// A cat meows!
