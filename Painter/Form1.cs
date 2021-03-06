//Joseph Williamson
//c#
//Painter Program

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Painter
{
    public partial class Form1 : Form
    {
        //variables to control usage
        bool shouldPaint = false;
        Graphics g;
        int size = 1;
        int? initX = null;
        int? initY = null;
        string tool = "pen";
        string myColor = "Black";
        bool drawSquare = false;
        bool drawRectangle = false;
        bool drawCircle = false;
        
        Pen p;
        SolidBrush br;




        public Form1()
        {
            InitializeComponent();
            panel1.BackColor = Color.White; //set background to white
            g = panel1.CreateGraphics();

        }



        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string current = checkedListBox1.SelectedItem.ToString();

            //draw a circle
            if (current == "Circle")
            {
                drawCircle = true;
            }
            //draw a rectangle
            if (current == "Rectangle")
            {
                drawRectangle = true;
            }
            //default to line
            if (current == "Line")
            {
                drawCircle = false;
                drawRectangle = false;
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

            //use pen
            tool = "pen";
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            //use brush
            tool = "brush";
        }

        private void size1Button_CheckedChanged(object sender, EventArgs e)
        {
            size = 1;

        }

        private void size5Button_CheckedChanged(object sender, EventArgs e)
        {
            size = 5;
        }

        private void size10Button_CheckedChanged(object sender, EventArgs e)
        {
            size = 10;
        }

        private void RedButton_CheckedChanged(object sender, EventArgs e)
        {
            //set color to red
            myColor = "Red";


        }

        private void BlueButton_CheckedChanged(object sender, EventArgs e)
        {
            //set color to blue
            myColor = "Blue";

        }

        private void GreenButton_CheckedChanged(object sender, EventArgs e)
        {
            //set color to green
            myColor = "Green";
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            //Are you over the Panel?
            if (shouldPaint)
            {
                //sets the color
                if (myColor == "Black")
                {
                    p = new Pen(Color.Black, size);
                }
                else if (myColor == "Blue")
                {
                    p = new Pen(Color.Blue, size);
                }
                else if (myColor == "Red")
                {
                    p = new Pen(Color.Red, size);
                }
                else p = new Pen(Color.Green, size);

                //Draws the lines
                g.DrawLine(p, new Point(initX ?? e.X, initY ?? e.Y), new Point(e.X, e.Y));
                initX = e.X;
                initY = e.Y;
            
            }
            



        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            //if over the panel and clicked
            shouldPaint = true;

            //draw a rectangle where clicked
            if (drawRectangle)
            {
                
                shouldPaint = false;
                drawSquare = false;
            }

            //draw a circle where clicked
            if (drawCircle)
            {
                
                shouldPaint = false;
                drawCircle = false;
            }


        }

        //when mouse is released
        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            shouldPaint = false;
            initX = null;
            initY = null;
        }
    }
}
