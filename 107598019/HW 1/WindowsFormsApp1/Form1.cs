using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            loading();
        }
        string path = System.Environment.CurrentDirectory + "\\" +"course.xml";

        private DataTable courseTable = new DataTable("course");

        private DataTable createTable()
        {
            courseTable.Columns.Add("課程名稱", typeof(System.String));
            courseTable.PrimaryKey = new DataColumn[] { courseTable.Columns["課程名稱"] };

            courseTable.Columns.Add("課程說明", typeof(System.String));
            courseTable.Columns.Add("適合對象", typeof(System.String));
            courseTable.Columns.Add("定價", typeof(System.String));
            courseTable.Columns.Add("注意事項", typeof(System.String));
            courseTable.Columns.Add("備註", typeof(System.String));
  
            return courseTable;
        } 

        public void addNewCourse(string[] course)
        {
            DataSet ds = new DataSet("Project");
            int xmlIsNotEmpty = ds.Tables.Count;
            if (xmlIsNotEmpty == 0)
            {
                courseTable.Rows.Add(course);
                ds.Tables.Add(courseTable.Copy());
                ds.WriteXml(@path);
                dataGridView1.DataSource = courseTable;  
                
                button2.Enabled = true;
                button3.Enabled = true;
            }

            else
            {
                courseTable.Reset();

                ds.ReadXml(@path);  

                courseTable = ds.Tables[0];    
                courseTable.Rows.Add(course);    

                dataGridView1.DataSource = courseTable;  

                ds.WriteXml(@path); 
            }           
        }

        private void loading()
        {
            DataSet ds = new DataSet("Project");
            ds.ReadXml(@path); 
            int courseInXml = ds.Tables.Count;

            if (courseInXml == 0 )
            {
                createTable();
                button2.Enabled = false;
                button3.Enabled = false;
            }

            else
            {
                courseTable = ds.Tables[0];    
                dataGridView1.DataSource = courseTable;  
            }
            
        }

        public void refresh(DataTable dt)
        {
            if (dt.Rows.Count == 0)
            {
                button2.Enabled = false;
                button3.Enabled = false;
            }
        }
        

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            string value = dataGridView1.Rows[e.RowIndex].Cells[e.ColumnIndex].Value.ToString();
            MessageBox.Show(value);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            addCourse addCourse = new addCourse();
            addCourse.addCourseTable = courseTable;
            addCourse.Visible = true;
            addCourse.Owner = this;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            editCourse editCourse = new editCourse();
            editCourse.editCourseTable = courseTable;
            editCourse.Visible = true;

            editCourse.setValue();
        }
            
        private void button3_Click(object sender, EventArgs e)
        {
            deleteCourse deleteCourse = new deleteCourse();
            deleteCourse.deleteCourseTable = courseTable;
            deleteCourse.Visible = true;
            deleteCourse.Owner = this;
            deleteCourse.setValue();
        }
    }
}
