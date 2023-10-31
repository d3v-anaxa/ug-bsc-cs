// WAP to demonstrate priorities among multiple threads
public class Nine{
	public static void main(String[] args){
        E t1 = new E();
        E t2 = new E();
        E t3 = new E();
        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.NORM_PRIORITY);
        t3.setPriority(Thread.MAX_PRIORITY);
        t1.start();
        t2.start();
        t3.start();
	}
}

class E extends Thread {
    public void run(){
        System.out.println("Thread " + Thread.currentThread().getId() + " has started" + " [Priority : " + Thread.currentThread().getPriority() + "]");
        for(int i = 1; i <= 5; i++){
            System.out.println("Thread " + Thread.currentThread().getId() + " -> " + i);
        }
        System.out.println("Thread " + Thread.currentThread().getId() + " has stopped");
    }
}

// Output
// Thread 16 has started [Priority : 10]
// Thread 14 has started [Priority : 1]
// Thread 15 has started [Priority : 5]
// Thread 14 -> 1
// Thread 16 -> 1
// Thread 15 -> 1
// Thread 16 -> 2
// Thread 14 -> 2
// Thread 16 -> 3
// Thread 15 -> 2
// Thread 16 -> 4
// Thread 14 -> 3
// Thread 16 -> 5
// Thread 15 -> 3
// Thread 14 -> 4
// Thread 15 -> 4
// Thread 14 -> 5
// Thread 15 -> 5
// Thread 16 has stopped
// Thread 14 has stopped
// Thread 15 has stopped
