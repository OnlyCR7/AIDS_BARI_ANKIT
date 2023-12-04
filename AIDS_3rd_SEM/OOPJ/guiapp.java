import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class guiapp {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Simple GUI Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        frame.setSize(300, 200); 

        JButton button = new JButton("Click Me!");

        JLabel label = new JLabel("");

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                label.setText("Button Clicked!");
            }
        });

        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout()); 
        panel.add(button); 
        panel.add(label); 

        frame.add(panel);

        frame.setVisible(true);
    }
}
