namespace Painter
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.FillButton = new System.Windows.Forms.RadioButton();
            this.size10Button = new System.Windows.Forms.RadioButton();
            this.size5Button = new System.Windows.Forms.RadioButton();
            this.size1Button = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.GreenButton = new System.Windows.Forms.RadioButton();
            this.BlueButton = new System.Windows.Forms.RadioButton();
            this.RedButton = new System.Windows.Forms.RadioButton();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Location = new System.Drawing.Point(225, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(640, 480);
            this.panel1.TabIndex = 0;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            this.panel1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseUp);
            // 
            // checkedListBox1
            // 
            this.checkedListBox1.FormattingEnabled = true;
            this.checkedListBox1.Items.AddRange(new object[] {
            "Line",
            "Circle",
            "Rectangle",
            "Fill"});
            this.checkedListBox1.Location = new System.Drawing.Point(34, 89);
            this.checkedListBox1.Name = "checkedListBox1";
            this.checkedListBox1.Size = new System.Drawing.Size(154, 64);
            this.checkedListBox1.TabIndex = 2;
            this.checkedListBox1.SelectedIndexChanged += new System.EventHandler(this.checkedListBox1_SelectedIndexChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.FillButton);
            this.groupBox1.Location = new System.Drawing.Point(34, 159);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(154, 94);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(23, 62);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(52, 17);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "Brush";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // FillButton
            // 
            this.FillButton.AutoSize = true;
            this.FillButton.Location = new System.Drawing.Point(23, 19);
            this.FillButton.Name = "FillButton";
            this.FillButton.Size = new System.Drawing.Size(44, 17);
            this.FillButton.TabIndex = 0;
            this.FillButton.TabStop = true;
            this.FillButton.Text = "Pen";
            this.FillButton.UseVisualStyleBackColor = true;
            this.FillButton.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // size10Button
            // 
            this.size10Button.AutoSize = true;
            this.size10Button.Location = new System.Drawing.Point(95, 33);
            this.size10Button.Name = "size10Button";
            this.size10Button.Size = new System.Drawing.Size(37, 17);
            this.size10Button.TabIndex = 4;
            this.size10Button.TabStop = true;
            this.size10Button.Text = "10";
            this.size10Button.UseVisualStyleBackColor = true;
            this.size10Button.CheckedChanged += new System.EventHandler(this.size10Button_CheckedChanged);
            // 
            // size5Button
            // 
            this.size5Button.AutoSize = true;
            this.size5Button.Location = new System.Drawing.Point(46, 33);
            this.size5Button.Name = "size5Button";
            this.size5Button.Size = new System.Drawing.Size(31, 17);
            this.size5Button.TabIndex = 3;
            this.size5Button.TabStop = true;
            this.size5Button.Text = "5";
            this.size5Button.UseVisualStyleBackColor = true;
            this.size5Button.CheckedChanged += new System.EventHandler(this.size5Button_CheckedChanged);
            // 
            // size1Button
            // 
            this.size1Button.AutoSize = true;
            this.size1Button.Location = new System.Drawing.Point(6, 33);
            this.size1Button.Name = "size1Button";
            this.size1Button.Size = new System.Drawing.Size(31, 17);
            this.size1Button.TabIndex = 2;
            this.size1Button.TabStop = true;
            this.size1Button.Text = "1";
            this.size1Button.UseVisualStyleBackColor = true;
            this.size1Button.CheckedChanged += new System.EventHandler(this.size1Button_CheckedChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.GreenButton);
            this.groupBox2.Controls.Add(this.BlueButton);
            this.groupBox2.Controls.Add(this.RedButton);
            this.groupBox2.Location = new System.Drawing.Point(34, 343);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(154, 97);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            // 
            // GreenButton
            // 
            this.GreenButton.AutoSize = true;
            this.GreenButton.Location = new System.Drawing.Point(23, 68);
            this.GreenButton.Name = "GreenButton";
            this.GreenButton.Size = new System.Drawing.Size(54, 17);
            this.GreenButton.TabIndex = 2;
            this.GreenButton.TabStop = true;
            this.GreenButton.Text = "Green";
            this.GreenButton.UseVisualStyleBackColor = true;
            this.GreenButton.CheckedChanged += new System.EventHandler(this.GreenButton_CheckedChanged);
            // 
            // BlueButton
            // 
            this.BlueButton.AutoSize = true;
            this.BlueButton.Location = new System.Drawing.Point(23, 44);
            this.BlueButton.Name = "BlueButton";
            this.BlueButton.Size = new System.Drawing.Size(46, 17);
            this.BlueButton.TabIndex = 1;
            this.BlueButton.TabStop = true;
            this.BlueButton.Text = "Blue";
            this.BlueButton.UseVisualStyleBackColor = true;
            this.BlueButton.CheckedChanged += new System.EventHandler(this.BlueButton_CheckedChanged);
            // 
            // RedButton
            // 
            this.RedButton.AutoSize = true;
            this.RedButton.Location = new System.Drawing.Point(23, 20);
            this.RedButton.Name = "RedButton";
            this.RedButton.Size = new System.Drawing.Size(45, 17);
            this.RedButton.TabIndex = 0;
            this.RedButton.TabStop = true;
            this.RedButton.Text = "Red";
            this.RedButton.UseVisualStyleBackColor = true;
            this.RedButton.CheckedChanged += new System.EventHandler(this.RedButton_CheckedChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.size10Button);
            this.groupBox3.Controls.Add(this.size1Button);
            this.groupBox3.Controls.Add(this.size5Button);
            this.groupBox3.Location = new System.Drawing.Point(34, 260);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(154, 77);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(866, 480);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.checkedListBox1);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Lets Paint!";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.CheckedListBox checkedListBox1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton size10Button;
        private System.Windows.Forms.RadioButton size5Button;
        private System.Windows.Forms.RadioButton size1Button;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton FillButton;
        private System.Windows.Forms.RadioButton GreenButton;
        private System.Windows.Forms.RadioButton BlueButton;
        private System.Windows.Forms.RadioButton RedButton;
        private System.Windows.Forms.GroupBox groupBox3;
    }
}

