class Increment implements Runnable {
    private final long I;

    public Increment(long I) {
        this.I = I;
    }

    public void run() {
        for (long i = 0; i < I; i++)
            System.out.println(i);
    }
}
