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
    public partial class addCourse : Form
    {
        public addCourse()
        {
            InitializeComponent();
        }
        
        public DataTable addCourseTable;

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String space = textBox1.Text;
            String deleteSpaceString = space.Trim();
                if(deleteSpaceString.Length==0)
                {
                    MessageBox.Show("       *** 你沒有輸入課程名稱 ***");
                }

                else
                {
                    if (addCourseTable != null)
                    {
                        DataRow[] result = addCourseTable.Select("課程名稱 ='" + textBox1.Text + "'");

                        foreach (DataRow row in result)
                        {
                            MessageBox.Show("       *** 課程名稱重複 ***");
                            return;
                        }
                    }
                    
                    string[] newCourse = { textBox1.Text, textBox2.Text, textBox3.Text, textBox4.Text, textBox5.Text, textBox6.Text };
                    Form1 form1 = (Form1)this.Owner;
                    form1.addNewCourse(newCourse);
                    this.Close();
                }
            
        }
    }
}
