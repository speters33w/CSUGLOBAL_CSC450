public class Scope {
    public static void main(String[] args) {
        ScopeExample scopeExample = new ScopeExample(1);
        // The following line will not work because the variable n is private:
        // System.out.println(scopeExample.n);
        // The following line will not work because the method PrintN() is private:
        // scopeExample.printN();
        int newN = scopeExample.incrementN();
        System.out.printf("The value of newN is: %d", newN);
    }
}
