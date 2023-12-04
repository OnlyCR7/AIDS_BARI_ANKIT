interface InterfaceA {
    void methodA();
}

interface InterfaceB {
    void methodB();
}

class MultipleInheritanceClass implements InterfaceA, InterfaceB {
    public void methodA() {
        System.out.println("Method A from InterfaceA");
    }

    public void methodB() {
        System.out.println("Method B from InterfaceB");
    }
}

public class multipleinheri {
    public static void main(String[] args) {
        MultipleInheritanceClass obj = new MultipleInheritanceClass();

        obj.methodA();
        obj.methodB();
    }
}
