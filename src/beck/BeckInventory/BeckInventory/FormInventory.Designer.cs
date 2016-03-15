using System;
using System.Windows.Forms;

namespace BeckInventory
{
    partial class FormInventory
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;
        private RadioButton[] Radios { get; set; }
        private Label[] Labels { get; set; }

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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormInventory));
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.labelQuestion = new System.Windows.Forms.Label();
            this.buttonContinue = new System.Windows.Forms.Button();
            this.flowLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 10F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 90F));
            this.tableLayoutPanel1.Location = new System.Drawing.Point(3, 23);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.Size = new System.Drawing.Size(368, 177);
            this.tableLayoutPanel1.TabIndex = 3;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.labelQuestion);
            this.flowLayoutPanel1.Controls.Add(this.tableLayoutPanel1);
            this.flowLayoutPanel1.Controls.Add(this.buttonContinue);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(12, 12);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(371, 244);
            this.flowLayoutPanel1.TabIndex = 1;
            // 
            // labelQuestion
            // 
            this.labelQuestion.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.labelQuestion.AutoSize = true;
            this.labelQuestion.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelQuestion.Location = new System.Drawing.Point(3, 0);
            this.labelQuestion.Name = "labelQuestion";
            this.labelQuestion.Size = new System.Drawing.Size(73, 20);
            this.labelQuestion.TabIndex = 2;
            this.labelQuestion.Text = "Question";
            this.labelQuestion.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // buttonContinue
            // 
            this.buttonContinue.Location = new System.Drawing.Point(3, 206);
            this.buttonContinue.Name = "buttonContinue";
            this.buttonContinue.Size = new System.Drawing.Size(75, 23);
            this.buttonContinue.TabIndex = 1;
            this.buttonContinue.Text = "Continuar";
            this.buttonContinue.UseVisualStyleBackColor = true;
            this.buttonContinue.Click += new System.EventHandler(this.buttonContinue_Click);
            // 
            // FormInventory
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(401, 277);
            this.Controls.Add(this.flowLayoutPanel1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "FormInventory";
            this.Text = "Escala";
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private string[] Rest(string[] array)
        {
            int limit = array.Length - 1;
            string[] outlet = new string[limit];

            for (int i = 1; i < array.Length; i++)
            {
                outlet[i - 1] = array[i];
            }

            return outlet;
        }

        private void CreateRows()
        {
            tableLayoutPanel1.RowCount = NoQuestions;
            Radios = new RadioButton[NoQuestions];
            Labels = new Label[NoQuestions];

            for (int i = 0; i < NoQuestions; i++)
            {
                RadioButton radio = new RadioButton();
                Label label = new Label();

                radio.Anchor = AnchorStyles.None;
                radio.AutoSize = true;
                radio.UseVisualStyleBackColor = true;
                label.Anchor = AnchorStyles.Left;
                label.AutoSize = true;

                Radios[i] = radio;
                Labels[i] = label;
                tableLayoutPanel1.Controls.Add(Radios[i], 0, i);
                tableLayoutPanel1.Controls.Add(Labels[i], 1, i);
                tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 100F / NoQuestions));
            }

            Radios[0].Checked = true;
        }

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.Button buttonContinue;
        private Label labelQuestion;
    }
}