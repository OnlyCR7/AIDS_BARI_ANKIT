class Car {
    String brand;
    String model;
    int year;

    void start() {
        System.out.println("Starting the " + brand + " " + model);
    }
}

public class classobj {
    public static void main(String[] args) {
        Car myCar = new Car();
        
        myCar.brand = "Toyota";
        myCar.model = "Camry";
        myCar.year = 2021;
        
        myCar.start();
    }
}
