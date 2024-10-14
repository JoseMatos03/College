import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

class Barrier {
    private final int totalThreads; // Number of threads to wait for
    private int waitingThreads = 0; // Count of threads that reached the barrier

    private final ReentrantLock lock = new ReentrantLock();
    private final Condition allThreadsReached = lock.newCondition();

    public Barrier(int N) {
        this.totalThreads = N;
    }

    public void await() throws InterruptedException {
        lock.lock(); // Lock to ensure mutual exclusion
        try {
            waitingThreads++;

            if (waitingThreads < totalThreads) {
                // If not all threads have reached, the current thread will wait
                allThreadsReached.await();
            } else {
                // Last thread to reach the barrier signals all others
                allThreadsReached.signalAll();
            }
        } finally {
            lock.unlock(); // Unlock to allow other threads to proceed
        }
    }
}

class ReusableBarrier {
    private final int totalThreads;
    private int waitingThreads = 0;
    private int phase = 0; // Track different phases of synchronization

    private final ReentrantLock lock = new ReentrantLock();
    private final Condition allThreadsReached = lock.newCondition();

    public ReusableBarrier(int N) {
        this.totalThreads = N;
    }

    public void await() throws InterruptedException {
        lock.lock();
        try {
            int currentPhase = phase; // Capture the current phase

            waitingThreads++;

            if (waitingThreads < totalThreads) {
                // If not all threads are here yet, wait for this phase to complete
                while (currentPhase == phase) {
                    allThreadsReached.await();
                }
            } else {
                // All threads have arrived, move to the next phase
                phase++;
                waitingThreads = 0; // Reset the counter for the next phase
                allThreadsReached.signalAll(); // Wake up all threads
            }
        } finally {
            lock.unlock();
        }
    }
}
