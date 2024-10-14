import java.lang.Thread;

class DepositTask implements Runnable {
    private Bank bank;
    private int value;
    private int iterations;

    public DepositTask(Bank bank, int value, int iterations) {
        this.bank = bank;
        this.value = value;
        this.iterations = iterations;
    }

    @Override
    public void run() {
        for (int i = 0; i < iterations; i++) {
            bank.deposit(value);
        }
    }
}

public class Ex2 {
    public static void run() {
        final int N = 10;
        final int I = 1000;
        final int V = 100;

        Bank bank = new Bank();
        Thread[] threads = new Thread[N];

        // Create and initialize the threads
        for (int i = 0; i < N; i++) {
            threads[i] = new Thread(new DepositTask(bank, V, I));
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

        System.out.println("Final balance: " + bank.balance());
    }
}
