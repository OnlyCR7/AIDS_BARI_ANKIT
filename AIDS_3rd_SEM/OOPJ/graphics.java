import javax.swing.*;
import java.awt.*;

class MyCanvas extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        g.setColor(Color.RED);
        g.drawRect(50, 50, 200, 100);

        g.setColor(Color.BLUE);
        g.drawOval(300, 50, 100, 100);

        g.setColor(Color.GREEN);
        g.drawLine(50, 200, 350, 200);

        g.setColor(Color.BLACK);
        g.setFont(new Font("Arial", Font.BOLD, 20));
        g.drawString("Hello, Graphics!", 100, 300);
    }
}

public class graphics {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Graphics Demo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);

        MyCanvas canvas = new MyCanvas();
        frame.add(canvas);

        frame.setVisible(true);
    }
}
