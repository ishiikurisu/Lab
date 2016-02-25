namespace Stroop
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
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonSelect = new System.Windows.Forms.Button();
            this.buttonStart = new System.Windows.Forms.Button();
            this.comboType = new System.Windows.Forms.ComboBox();
            this.textHowLong = new System.Windows.Forms.TextBox();
            this.textWhere = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 40F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 30F));
            this.tableLayoutPanel1.Controls.Add(this.label1, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.label2, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.buttonSelect, 2, 2);
            this.tableLayoutPanel1.Controls.Add(this.buttonStart, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.comboType, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.textHowLong, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.textWhere, 1, 2);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(12, 12);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(258, 135);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(109, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Stroop";
            // 
            // label2
            // 
            this.label2.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 43);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(31, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Type";
            // 
            // buttonSelect
            // 
            this.buttonSelect.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.buttonSelect.Enabled = false;
            this.buttonSelect.Location = new System.Drawing.Point(183, 71);
            this.buttonSelect.Name = "buttonSelect";
            this.buttonSelect.Size = new System.Drawing.Size(72, 23);
            this.buttonSelect.TabIndex = 2;
            this.buttonSelect.Text = "Select";
            this.buttonSelect.UseVisualStyleBackColor = true;
            // 
            // buttonStart
            // 
            this.buttonStart.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.buttonStart.Location = new System.Drawing.Point(91, 105);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(75, 23);
            this.buttonStart.TabIndex = 3;
            this.buttonStart.Text = "Start";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // comboType
            // 
            this.comboType.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.comboType.FormattingEnabled = true;
            this.comboType.Items.AddRange(new object[] {
            "Random",
            "From file"});
            this.comboType.Location = new System.Drawing.Point(80, 39);
            this.comboType.Name = "comboType";
            this.comboType.Size = new System.Drawing.Size(97, 21);
            this.comboType.TabIndex = 4;
            this.comboType.Text = "Random";
            this.comboType.SelectedIndexChanged += new System.EventHandler(this.comboType_SelectedIndexChanged);
            // 
            // textHowLong
            // 
            this.textHowLong.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.textHowLong.Location = new System.Drawing.Point(183, 39);
            this.textHowLong.Name = "textHowLong";
            this.textHowLong.Size = new System.Drawing.Size(72, 20);
            this.textHowLong.TabIndex = 5;
            this.textHowLong.Text = "1min";
            // 
            // textWhere
            // 
            this.textWhere.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.textWhere.Enabled = false;
            this.textWhere.Location = new System.Drawing.Point(80, 72);
            this.textWhere.Name = "textWhere";
            this.textWhere.Size = new System.Drawing.Size(97, 20);
            this.textWhere.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(282, 159);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "Form1";
            this.Text = "Stroop";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonSelect;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.ComboBox comboType;
        private System.Windows.Forms.TextBox textHowLong;
        private System.Windows.Forms.TextBox textWhere;
    }
}

