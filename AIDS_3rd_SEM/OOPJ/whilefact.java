import java.util.Scanner;

public class whilefact {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a number: ");
        int num = input.nextInt();
        
        int factorial = 1;
        int i = 1;
        
        while (i <= num) {
            factorial *= i;
            i++;
        }
        
        System.out.println("Factorial of " + num + " is " + factorial);
        
        input.close();
    }
}
