// WAP in with two classes C and D implements Runnable nterface and overrides run() and runs concurrently
class C implements Runnable {
	@Override
	public void run(){
		for (int i = 0; i < 10; i++)
		System.out.println("Thread " + Thread.currentThread().getId() + " has started -> count : " + i);
		System.out.println("Exited Thread [C]");
	}
}

class D implements Runnable {
	@Override
	public void run(){
		for (int i = 0; i < 10; i++)
		System.out.println("Thread " + Thread.currentThread().getId() + " has started -> count : " + i);
		System.out.println("Exited Thread [D]");
	}	
}

public class Six {
	public static void main(String[] args){
		new Thread(new C()).start();
		new Thread(new D()).start();	
	}
}

// Output
// Thread 15 has started -> count : 0
// Thread 15 has started -> count : 1
// Thread 15 has started -> count : 2
// Thread 15 has started -> count : 3
// Thread 15 has started -> count : 4
// Thread 15 has started -> count : 5
// Thread 15 has started -> count : 6
// Thread 15 has started -> count : 7
// Thread 14 has started -> count : 0
// Thread 15 has started -> count : 8
// Thread 14 has started -> count : 1
// Thread 15 has started -> count : 9
// Exited Thread [D]
// Thread 14 has started -> count : 2
// Thread 14 has started -> count : 3
// Thread 14 has started -> count : 4
// Thread 14 has started -> count : 5
// Thread 14 has started -> count : 6
// Thread 14 has started -> count : 7
// Thread 14 has started -> count : 8
// Thread 14 has started -> count : 9
// Exited Thread [C]
