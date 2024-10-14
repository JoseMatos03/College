import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

class Agreement {
    private final int totalThreads;  // Number of threads to wait for
    private int waitingThreads = 0;  // Count of threads that have proposed
    private int maxProposal = Integer.MIN_VALUE;  // Store the maximum proposed value
    private int phase = 0;  // Track different phases (for reuse)

    private final ReentrantLock lock = new ReentrantLock();
    private final Condition allThreadsReached = lock.newCondition();

    public Agreement(int N) {
        this.totalThreads = N;
    }

    public int propose(int choice) throws InterruptedException {
        lock.lock();
        try {
            int currentPhase = phase;
            waitingThreads++;

            // Update the maximum proposal value
            if (choice > maxProposal) {
                maxProposal = choice;
            }

            if (waitingThreads < totalThreads) {
                // If not all threads have proposed, wait for others
                while (currentPhase == phase) {
                    allThreadsReached.await();
                }
            } else {
                // All threads have proposed, move to the next phase
                phase++;
                waitingThreads = 0;  // Reset counter for the next agreement round
                allThreadsReached.signalAll();  // Wake all threads
            }

            // Return the maximum proposed value
            return maxProposal;
        } finally {
            if (waitingThreads == 0) {
                // Reset maxProposal for the next phase after the last thread has returned
                maxProposal = Integer.MIN_VALUE;
            }
            lock.unlock();
        }
    }
}
