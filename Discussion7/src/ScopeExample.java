public class ScopeExample {
    // Private variable accessible only within the class
    private int n;

    public ScopeExample(int number) {
        this.n = number;
    }

    // Private method accessible only within the class
    private void printN() {
        System.out.printf("The value of this ScopeExample.n is: %d\n", this.n);
    }

    // Public method accessible from outside the class
    public int incrementN() {
        this.n++;
        printN();
        return this.n;
    }
}
