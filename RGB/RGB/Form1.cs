using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RGB
{
    public partial class Form1 : Form
    {
        int redValue = 0;
        int blueValue = 0;
        int greenValue = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        /*
         * Changes the window color 
         */
        private void ChangeColor(int r, int g, int b)
        {
            Color myrgbColor = new Color();
            myrgbColor = Color.FromArgb(r, g, b);
            this.BackColor = myrgbColor;
        }

        private void BlueSlider_Scroll(object sender, ScrollEventArgs e)
        {
            blueValue = BlueSlider.Value;
            ChangeColor(redValue, greenValue, blueValue);
        }

        private void GreenSlider_Scroll(object sender, ScrollEventArgs e)
        {
            greenValue = GreenSlider.Value;
            ChangeColor(redValue, greenValue, blueValue);
        }

        private void RedSlider_Scroll(object sender, ScrollEventArgs e)
        {
            redValue = RedSlider.Value;
            ChangeColor(redValue, greenValue, blueValue);
        }

        private void WinXPButton_Click(object sender, EventArgs e)
        {
            RedSlider.Value = 0;
            GreenSlider.Value = 0;
            BlueSlider.Value = 0;

            ChangeColor(0, 0, 0);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ChangeColor(0, 0, 0);
        }
    }
}
