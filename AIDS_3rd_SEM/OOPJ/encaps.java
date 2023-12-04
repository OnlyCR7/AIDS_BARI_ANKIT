class Person {
    private String name;
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String n) {
        name = n;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int a) {
        if (a >= 0) {
            age = a;
        }
    }
}

public class encaps {
    public static void main(String[] args) {
        Person person = new Person();
        
        person.setName("Alice");
        person.setAge(25);
        
        System.out.println("Name: " + person.getName());
        System.out.println("Age: " + person.getAge());
    }
}
