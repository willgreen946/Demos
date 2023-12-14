
namespace RGB
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.RedSlider = new System.Windows.Forms.VScrollBar();
            this.GreenSlider = new System.Windows.Forms.VScrollBar();
            this.BlueSlider = new System.Windows.Forms.VScrollBar();
            this.WinXPButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // RedSlider
            // 
            this.RedSlider.Location = new System.Drawing.Point(9, 87);
            this.RedSlider.Maximum = 255;
            this.RedSlider.Name = "RedSlider";
            this.RedSlider.Size = new System.Drawing.Size(17, 354);
            this.RedSlider.TabIndex = 1;
            this.RedSlider.Scroll += new System.Windows.Forms.ScrollEventHandler(this.RedSlider_Scroll);
            // 
            // GreenSlider
            // 
            this.GreenSlider.Location = new System.Drawing.Point(59, 87);
            this.GreenSlider.Maximum = 255;
            this.GreenSlider.Name = "GreenSlider";
            this.GreenSlider.Size = new System.Drawing.Size(17, 354);
            this.GreenSlider.TabIndex = 2;
            this.GreenSlider.Scroll += new System.Windows.Forms.ScrollEventHandler(this.GreenSlider_Scroll);
            // 
            // BlueSlider
            // 
            this.BlueSlider.Location = new System.Drawing.Point(111, 87);
            this.BlueSlider.Maximum = 255;
            this.BlueSlider.Name = "BlueSlider";
            this.BlueSlider.Size = new System.Drawing.Size(17, 354);
            this.BlueSlider.TabIndex = 3;
            this.BlueSlider.Scroll += new System.Windows.Forms.ScrollEventHandler(this.BlueSlider_Scroll);
            // 
            // WinXPButton
            // 
            this.WinXPButton.Location = new System.Drawing.Point(29, 12);
            this.WinXPButton.Name = "WinXPButton";
            this.WinXPButton.Size = new System.Drawing.Size(75, 23);
            this.WinXPButton.TabIndex = 4;
            this.WinXPButton.Text = "Reset";
            this.WinXPButton.UseVisualStyleBackColor = true;
            this.WinXPButton.Click += new System.EventHandler(this.WinXPButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.WinXPButton);
            this.Controls.Add(this.BlueSlider);
            this.Controls.Add(this.GreenSlider);
            this.Controls.Add(this.RedSlider);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.VScrollBar RedSlider;
        private System.Windows.Forms.VScrollBar GreenSlider;
        private System.Windows.Forms.VScrollBar BlueSlider;
        private System.Windows.Forms.Button WinXPButton;
    }
}

