import java.lang.Thread;

public class Ex1 {
    public static void run() {
        final int N = 10;
        final long I = 100;

        Thread[] threads = new Thread[N];

        // Create and initialize the threads
        for (int i = 0; i < N; i++) {
            threads[i] = new Thread(new Increment(I));
            threads[i].start();
        }

        // Wait for the threads to finish
        for (int i = 0; i < N; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("All threads finished");
    }
}