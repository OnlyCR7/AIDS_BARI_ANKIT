import java.util.Vector;

public class vector {
    public static void main(String[] args) {
        StringBuffer stringBuffer = new StringBuffer("Hello, ");
        stringBuffer.append("Java");
        stringBuffer.insert(5, "awesome ");
        stringBuffer.replace(0, 5, "Hi, ");
        String resultString = stringBuffer.toString();

        System.out.println("Manipulated String: " + resultString);

        Vector<String> namesVector = new Vector<>();

        namesVector.add("Alice");
        namesVector.add("Bob");
        namesVector.add("Charlie");

        System.out.println("Names in the vector:");
        for (String name : namesVector) {
            System.out.println(name);
        }
    }
}
