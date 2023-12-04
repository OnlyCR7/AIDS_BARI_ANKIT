class Parent {
    void displayParent() {
        System.out.println("This is the parent class.");
    }
}

class Child extends Parent {
    void displayChild() {
        System.out.println("This is the child class.");
    }
}

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

class Grandparent {
    void displayGrandparent() {
        System.out.println("This is the grandparent class.");
    }
}

class Parent2 extends Grandparent {
    void displayParent2() {
        System.out.println("This is the parent2 class.");
    }
}

class Child2 extends Parent2 {
    void displayChild2() {
        System.out.println("This is the child2 class.");
    }
}

public class inheritance {
    public static void main(String[] args) {
        Child child = new Child();
        child.displayParent();
        child.displayChild();

        MultipleInheritanceClass multipleInheritanceObj = new MultipleInheritanceClass();
        multipleInheritanceObj.methodA();
        multipleInheritanceObj.methodB();

        Child2 child2 = new Child2();
        child2.displayGrandparent();
        child2.displayParent2();
        child2.displayChild2();
    }
}
