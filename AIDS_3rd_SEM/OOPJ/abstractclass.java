abstract class Shape {
    abstract double calculateArea();
    
    abstract double calculatePerimeter();
    
    void display() {
        System.out.println("This is a shape.");
    }
}

class Circle extends Shape {
    private double radius;
    
    Circle(double r) {
        radius = r;
    }
    
    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }
    
    @Override
    double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;
    
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    
    @Override
    double calculateArea() {
        return length * width;
    }
    
    @Override
    double calculatePerimeter() {
        return 2 * (length + width);
    }
}

public class abstractclass {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        Rectangle rectangle = new Rectangle(4, 6);
        
        circle.display();
        System.out.println("Circle Area: " + circle.calculateArea());
        System.out.println("Circle Perimeter: " + circle.calculatePerimeter());
        
        System.out.println();
        
        rectangle.display();
        System.out.println("Rectangle Area: " + rectangle.calculateArea());
        System.out.println("Rectangle Perimeter: " + rectangle.calculatePerimeter());
    }
}
