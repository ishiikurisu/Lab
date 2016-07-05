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
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
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
            var canvas = this.canvasBoard;
            var where = Mouse.GetPosition(canvas);

            while (IsDrawing)
            {
                where = Mouse.GetPosition(canvas);
                var paint = CreatePaint(where);
                canvas.Children.Add(paint);
                await Task.Delay(5);
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
            paint.Margin = new Thickness(where.X, where.Y, 0, 0);
            paint.Width = paint.Height = BrushSize;

            return paint;
        }
    }
}
