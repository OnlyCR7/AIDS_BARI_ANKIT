class Vehicle {
    String type;

    Vehicle(String type) {
        this.type = type;
    }

    void start() {
        System.out.println("Starting the " + type);
    }
}

class Car extends Vehicle {
    String model;

    Car(String type, String model) {
        super(type); 
        this.model = model;
    }

    @Override
    void start() {
        super.start(); 
        System.out.println("Car model: " + model);
    }
}

final class FinalClass {
    void display() {
        System.out.println("This is a final class.");
    }
}


public class superfinal {
    public static void main(String[] args) {
        Car myCar = new Car("Sedan", "Toyota Camry");

        myCar.start();

        FinalClass finalObj = new FinalClass();
        finalObj.display();
    }
}
