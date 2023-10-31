public class MultithreadCommunicationDemo {
    public static void main(String[] args) {
        Message message = new Message();
        Thread producerThread = new Thread(new Producer(message));
        Thread consumerThread = new Thread(new Consumer(message));
        producerThread.start();
        consumerThread.start();
    }
    // Shared message object between producer and consumer threads
    static class Message {
        private String content;
        private boolean available = false;
        public synchronized void put(String message) {
            // Wait until the message is consumed by the consumer
            while (available) {
                try { wait();
                } catch (InterruptedException e) { e.printStackTrace(); }
            }
            // Put the message
            content = message;
            available = true;
            // Notify the consumer thread that the message is available
            notify();
        }
        public synchronized String take() {
            // Wait until there is a message available from the producer
            while (!available) {
                try { wait();
                } catch (InterruptedException e) {e.printStackTrace();}
            }
            // Take the message
            String message = content;
            available = false;
            // Notify the producer thread that the message has been consumed
            notify();
            return message;
        }
    }
    // Producer thread
    static class Producer implements Runnable {
        private final Message message;
        public Producer(Message message) { this.message = message; }
        @Override
        public void run() {
            String[] messages = {"Message 1", "Message 2", "Message 3"};
            for (String msg : messages) {
                message.put(msg);
                System.out.println("Produced: " + msg);
                try {
                    Thread.sleep(1000); // Simulate some processing time
                } catch (InterruptedException e) { e.printStackTrace(); }
            }
        }
    }
    // Consumer thread
    static class Consumer implements Runnable {
        private final Message message;
        public Consumer(Message message) { this.message = message; }
        @Override
        public void run() {
            for (int i = 0; i < 3; i++) {
                String receivedMessage = message.take();
                System.out.println("Consumed: " + receivedMessage);
                try {
                    Thread.sleep(1000); // Simulate some processing time
                } catch (InterruptedException e) { e.printStackTrace(); }
            }
        }
    }
}
