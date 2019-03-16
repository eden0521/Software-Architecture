import java.awt.BorderLayout;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class Displaydata
{
	Displaydata() throws IOException{
		Vector<Vector> rowData = new Vector<Vector>();
		FileReader reader = new FileReader("1.txt");
		BufferedReader br = new BufferedReader(reader);
		JFrame frame = new JFrame();
	    Vector<String> col = new Vector<String>();
	    col.addElement("ID");
	    col.addElement("課程名稱");
	    col.addElement("課程說明");
	    col.addElement("適合對象");
	    col.addElement("定價");
	    col.addElement("注意事項");
	    col.addElement("備註");
		String eachLine = null;
		while((eachLine = br.readLine()) != null)
		{	
			String[] temp = eachLine.split(",");
			Vector<String> row = new Vector<String>();
			for(int i = 0; i < temp.length; i++)
			{
				row.add(temp[i]);
			}
			rowData.add(row);
		}
		
		JTable table = new JTable(rowData, col);
		JScrollPane scrollPane = new JScrollPane(table);
	    frame.add(scrollPane, BorderLayout.CENTER);
	    frame.setSize(500, 500);
	    frame.setVisible(true);
	
	}

}
