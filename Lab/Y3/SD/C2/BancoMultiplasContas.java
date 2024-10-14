public class BancoMultiplasContas {

    private static class Account {
        private int balance;
        Account (int balance) { this.balance = balance; }
        int balance () { return balance; }
        boolean deposit (int value) {
            balance += value;
            return true;
        }
        boolean withdraw (int value) {
            if (value > balance)
                return false;
            balance -= value;
            return true;
        }
    }

    // Bank slots and vector of accounts
    private final int slots;
    private Account[] av;
    private int totalBalance;

    public BancoMultiplasContas (int n) {
        slots=n;
        av=new Account[slots];
        totalBalance = 0;
        for (int i=0; i<slots; i++)
            av[i]=new Account(0);
    }


    // Account balance
    public int balance (int id) {
        if (id < 0 || id >= slots)
            return 0;
        return av[id].balance();
    }

    // Deposit
    public boolean deposit (int id, int value) {
        if (id < 0 || id >= slots)
            return false;
        return av[id].deposit(value);
    }

    // Withdraw; fails if no such account or insufficient balance
    public boolean withdraw (int id, int value) {
        if (id < 0 || id >= slots)
            return false;
        return av[id].withdraw(value);
    }

    // Transfer
    public boolean transfer (int from, int to, int value) {
        if (from < 0 || from >= slots)
            return false;
        if (to < 0 || to >= slots)
            return false;
        av[from].withdraw(value);
        av[to].deposit(value);
        return true;
    }

    // TotalBalance
    public int totalBalance () {
        totalBalance = 0;
        for (int i = 0; i < slots; i++) {
            totalBalance += av[i].balance();
        }
        return totalBalance;
    }
}
