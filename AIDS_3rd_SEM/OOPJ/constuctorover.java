class Student {
    String name;
    int age;

    Student() {
        name = "Unknown";
        age = 0;
    }

    Student(String n) {
        name = n;
        age = 0;
    }

    Student(String n, int a) {
        name = n;
        age = a;
    }

    void display() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class constuctorover {
    public static void main(String[] args) {
        Student student1 = new Student();
        Student student2 = new Student("Alice");
        Student student3 = new Student("Bob", 22);

        student1.display();
        student2.display();
        student3.display();
    }
}
