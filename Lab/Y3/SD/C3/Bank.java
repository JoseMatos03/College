import java.util.concurrent.locks.ReentrantLock;
import java.util.*;

class Bank {

    // Usar ReentrantLock para controlar o acesso ao saldo das contas
    private final ReentrantLock lock = new ReentrantLock();

    private static class Account {
        private int balance;
        private final ReentrantLock accountLock = new ReentrantLock();

        Account(int balance) {
            this.balance = balance;
        }

        // Operação de obter saldo com lock
        int balance() {
            accountLock.lock();
            try {
                return balance;
            } finally {
                accountLock.unlock();
            }
        }

        // Operação de depósito com lock
        boolean deposit(int value) {
            accountLock.lock();
            try {
                balance += value;
                return true;
            } finally {
                accountLock.unlock();
            }
        }

        // Operação de saque com lock
        boolean withdraw(int value) {
            accountLock.lock();
            try {
                if (balance >= value) {
                    balance -= value;
                    return true;
                }
                return false;
            } finally {
                accountLock.unlock();
            }
        }
    }

    // Banco com um conjunto de contas
    private final Map<Integer, Account> accounts = new HashMap<>();
    private int nextId = 0;

    // Criar uma nova conta
    int createAccount(int balance) {
        lock.lock();
        try {
            int id = nextId++;
            accounts.put(id, new Account(balance));
            return id;
        } finally {
            lock.unlock();
        }
    }

    // Fechar uma conta
    int closeAccount(int id) {
        lock.lock();
        try {
            Account acc = accounts.remove(id);
            return acc != null ? acc.balance() : 0;
        } finally {
            lock.unlock();
        }
    }

    // Consultar saldo da conta
    int balance(int id) {
        lock.lock();
        try {
            Account acc = accounts.get(id);
            return acc != null ? acc.balance() : 0;
        } finally {
            lock.unlock();
        }
    }

    // Depositar valor na conta
    boolean deposit(int id, int value) {
        lock.lock();
        try {
            Account acc = accounts.get(id);
            return acc != null && acc.deposit(value);
        } finally {
            lock.unlock();
        }
    }

    // Retirar valor da conta
    boolean withdraw(int id, int value) {
        lock.lock();
        try {
            Account acc = accounts.get(id);
            return acc != null && acc.withdraw(value);
        } finally {
            lock.unlock();
        }
    }

    // Transferir valor entre contas
    boolean transfer(int from, int to, int value) {
        lock.lock();
        try {
            Account fromAcc = accounts.get(from);
            Account toAcc = accounts.get(to);
            if (fromAcc != null && toAcc != null && fromAcc.withdraw(value)) {
                toAcc.deposit(value);
                return true;
            }
            return false;
        } finally {
            lock.unlock();
        }
    }

    // Total dos saldos de um conjunto de contas
    int totalBalance(int[] ids) {
        lock.lock();
        try {
            int total = 0;
            for (int id : ids) {
                Account acc = accounts.get(id);
                if (acc != null) {
                    total += acc.balance();
                }
            }
            return total;
        } finally {
            lock.unlock();
        }
    }
}
