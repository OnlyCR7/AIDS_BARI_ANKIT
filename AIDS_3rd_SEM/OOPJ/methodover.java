class Calculator {
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double add(double a, double b) {
        return a + b;
    }
}

public class methodover {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();

        int sum1 = calculator.add(10, 20);
        int sum2 = calculator.add(10, 20, 30);
        double sum3 = calculator.add(2.5, 3.5);

        System.out.println("Sum of two integers: " + sum1);
        System.out.println("Sum of three integers: " + sum2);
        System.out.println("Sum of two doubles: " + sum3);
    }
}
