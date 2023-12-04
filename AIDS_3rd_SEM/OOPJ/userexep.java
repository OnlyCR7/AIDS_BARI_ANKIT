class NegativeNumberException extends Exception {
    public NegativeNumberException(String message) {
        super(message);
    }
}

public class userexep {
    public static void main(String[] args) {
        try {
            int age = -5;
            validateAge(age);
            System.out.println("Age: " + age);
        } catch (NegativeNumberException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void validateAge(int age) throws NegativeNumberException {
        if (age < 0) {
            throw new NegativeNumberException("Age cannot be negative");
        }
    }
}
