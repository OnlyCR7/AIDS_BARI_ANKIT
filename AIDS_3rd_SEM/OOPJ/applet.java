import java.applet.Applet;
import java.awt.*;

public class HelloWorldApplet extends Applet {
    @Override
    public void init() {
        // Initialization code (if needed)
    }

    @Override
    public void paint(Graphics g) {
        g.drawString("Hello, Applet!", 50, 50);
    }
}

/* 
<!DOCTYPE html>
<html>
<head>
    <title>Hello World Applet</title>
</head>
<body>
    <applet code="HelloWorldApplet.class" width="400" height="200"></applet>
</body>
</html>
*/