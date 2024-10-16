import java.util.concurrent.locks.ReentrantLock;

class Bank {
  private static class Account {
    private int balance;
    private ReentrantLock lock = new ReentrantLock();

    Account(int balance) {
      this.balance = balance;
    }

    int balance() {
      lock.lock();
      try {
        return balance;
      } finally {
        lock.unlock();
      }
    }

    boolean deposit(int value) {
      lock.lock();
      try {
        balance += value;
        return true;
      } finally {
        lock.unlock();
      }
    }
  }

  // Our single account, for now
  private Account savings = new Account(0);

  // Account balance
  public int balance() {
    return savings.balance();
  }

  // Deposit
  boolean deposit(int value) {
    return savings.deposit(value);
  }
}
