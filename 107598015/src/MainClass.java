import java.awt.Container;
import java.awt.TextField;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class MainClass {
	private JFrame frame;
	public static void main(String[] args) 
	{
		CourseManageView coursemanageview=new CourseManageView();
		coursemanageview.setSize(450,450);
		coursemanageview.setVisible(true);
	}
}
