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
    public partial class editSelectedCourse : Form
    {
        public DataTable editCourseTable;
        public string selectedCourse;
        string path = System.Environment.CurrentDirectory + "\\" + "course.xml";
        public void setValue()
        {
            DataRow[] result = editCourseTable.Select("課程名稱 ='" + selectedCourse + "'");

            foreach (DataRow row in result)
            {
                textBox1.Text = row["課程名稱"].ToString();
                textBox2.Text = row["課程說明"].ToString();
                textBox3.Text = row["適合對象"].ToString();
                textBox4.Text = row["定價"].ToString();
                textBox5.Text = row["注意事項"].ToString();
                textBox6.Text = row["備註"].ToString();
            }
        }

        public editSelectedCourse()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String space = textBox1.Text;
            String deleteSpaceString = space.Trim();
            if (deleteSpaceString.Length == 0)
            {
                MessageBox.Show("       *** 你沒有輸入課程名稱 ***");
            }
            else
            {
                if (textBox1.Text != selectedCourse)
                {
                    DataRow[] isDuplicate = editCourseTable.Select("課程名稱 ='" + textBox1.Text + "'");

                    foreach (DataRow row in isDuplicate)
                    {
                        MessageBox.Show("       *** 課程名稱重複 ***");
                        return;
                    }
                }
               
                DataRow[] result = editCourseTable.Select("課程名稱 ='" + selectedCourse + "'");

                foreach (DataRow row in result)
                {
                    row["課程名稱"] = textBox1.Text;
                    row["課程說明"] = textBox2.Text;
                    row["適合對象"] = textBox3.Text;
                    row["定價"] = textBox4.Text;
                    row["注意事項"] = textBox5.Text;
                    row["備註"] = textBox6.Text;
                }

                DataSet ds = new DataSet("Project");
                DataTable dt = editCourseTable;
                ds.Tables.Add(dt.Copy());
                ds.WriteXml(@path);
                this.Close();
              
            }
           
        }
    }
}
