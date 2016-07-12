using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Board
{
    public partial class MainWindow : Window
    {
        private Brush BrushColor { get; set; }
        private double BrushSize { get; set; }
        private List<Ellipse> Painting { get; set; }
        private bool IsDrawing { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            BrushColor = Brushes.Black;
            Painting = new List<Ellipse>();
            BrushSize = 5;
            IsDrawing = false;
        }

        private async void canvasBoard_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            var canvas = sender as Canvas;
            var where = e.GetPosition(canvas);
            var paint = CreatePaint(where);

            Painting.Add(paint);
            canvas.Children.Add(paint);
            IsDrawing = true;

            await StopDrawing();
        }

        private void canvasBoard_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            IsDrawing = false;
        }

        private async Task<bool> StopDrawing()
        {
            while (IsDrawing)
            {
                var where = Mouse.GetPosition(this.canvasBoard);
                var paint = CreatePaint(where);
                var lastPaint = Painting.ElementAt(Painting.Count-1);
                var line = CreateLine(where, 
                                      new Point(lastPaint.Margin.Left + BrushSize/2,
                                                lastPaint.Margin.Top + BrushSize/2));

                canvasBoard.Children.Add(line);
                canvasBoard.Children.Add(paint);
                Painting.Add(paint);

                await Task.Delay(1);
            }

            return IsDrawing;
        }

        private void buttonBlack_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            BrushColor = Brushes.Black;
        }

        private void buttonRed_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            BrushColor = Brushes.Red;
        }

        private void buttonBlue_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            BrushColor = Brushes.Blue;
        }

        private void buttonGreen_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            BrushColor = Brushes.Green;
        }

        private void buttonWhite_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            BrushColor = Brushes.White;
        }

        private Ellipse CreatePaint(Point where)
        {
            var paint = new Ellipse();

            paint.Fill = BrushColor;
            paint.Width = paint.Height = BrushSize;
            paint.Margin = new Thickness(where.X - BrushSize / 2, where.Y - BrushSize / 2, 0, 0);

            return paint;
        }

        private Line CreateLine(Point beginning, Point ending)
        {
            var line = new Line();

            line.Stroke = BrushColor;
            line.X1 = beginning.X;
            line.Y1 = beginning.Y;
            line.X2 = ending.X;
            line.Y2 = ending.Y;
            line.StrokeThickness = BrushSize;
            line.Margin = new Thickness(0, 0, 0, 0);

            return line;
        }

        private void canvasBoard_MouseLeave(object sender, MouseEventArgs e)
        {
            IsDrawing = false;
        }
    }
}
