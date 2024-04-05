public class ScopeMethod{

    private int globalVariable = 8;

    public void manipulateGlobalVariable() {
        globalVariable += 4;
        System.out.println("Manipulated globalVariable: " + globalVariable);
    }

    public int performOperation() {
        int localVariable = 16;

        System.out.println("Local variable: " + localVariable);

        localVariable *= 2;
        System.out.println("Modified localVariable: " + localVariable);
        return localVariable;
    }

    public static void main(String[] args) {
        ScopeMethod example = new ScopeMethod();

        example.manipulateGlobalVariable();
        int localVariable = example.performOperation();
        System.out.println("Access localVariable outside its scope: " + localVariable);
    }
}