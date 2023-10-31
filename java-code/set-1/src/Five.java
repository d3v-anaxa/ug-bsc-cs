// WAP in with two classes extends Thread class and runs concurrently
class A extends Thread {
	public void run(){
		for (int i = 0; i < 10; i++)
		System.out.println("Thread " + Thread.currentThread().getId() + " has started -> count : " + i);
		System.out.println("Exited Thread [A]");
	}
}

class B extends Thread {
	public void run(){
		for (int i = 0; i < 10; i++)
		System.out.println("Thread " + Thread.currentThread().getId() + " has started -> count : " + i);
		System.out.println("Exited Thread [B]");
	}	
}

public class Five {
	public static void main(String[] args){
		new A().start();
		new B().start();	
	}
}

// Output
// Thread 14 has started -> count : 0
// Thread 15 has started -> count : 0
// Thread 14 has started -> count : 1
// Thread 15 has started -> count : 1
// Thread 14 has started -> count : 2
// Thread 15 has started -> count : 2
// Thread 14 has started -> count : 3
// Thread 15 has started -> count : 3
// Thread 14 has started -> count : 4
// Thread 15 has started -> count : 4
// Thread 15 has started -> count : 5
// Thread 14 has started -> count : 5
// Thread 15 has started -> count : 6
// Thread 14 has started -> count : 6
// Thread 15 has started -> count : 7
// Thread 14 has started -> count : 7
// Thread 15 has started -> count : 8
// Thread 14 has started -> count : 8
// Thread 15 has started -> count : 9
// Thread 14 has started -> count : 9
// Exited Thread [A]
// Exited Thread [B]
