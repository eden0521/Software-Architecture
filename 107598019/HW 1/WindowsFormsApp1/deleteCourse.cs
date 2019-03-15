using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class deleteCourse : Form
    {
        public deleteCourse()
        {
            InitializeComponent();
        }

        public DataTable deleteCourseTable;
        string path = System.Environment.CurrentDirectory + "\\" + "course.xml";
        public void setValue()
        {
            int lengthOfItem = deleteCourseTable.Rows.Count;
            for (int i = 0; i < lengthOfItem; i++)
            {
                checkedListBox1.Items.Add(deleteCourseTable.Rows[i][0]);
            }
            checkedListBox1.SelectedIndex = 0;
        }

        private void deleteCourse_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int numberOfItems = checkedListBox1.Items.Count;
            
            for (int i = 0; i < numberOfItems; i++)
            {

                if (checkedListBox1.GetItemChecked(i))
                {
                    string deleteItem = checkedListBox1.Items[i].ToString();
                    DataRow[] result = deleteCourseTable.Select("課程名稱 ='" + deleteItem + "'");

                    foreach (DataRow row in result)
                    {
                        row.Delete();
                    }
                }
            }

            DataSet ds = new DataSet("Project");
            DataTable dt = deleteCourseTable;
            ds.Tables.Add(dt.Copy());
            ds.WriteXml(@path);
            
            Form1 form1 = (Form1)this.Owner;
            form1.refresh(dt.Copy());

            this.Close();
        }
    }
}
