using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
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

namespace Drawing
{
    public partial class MainWindow : Window
    {
        private double Dimension { get; set; }
        private bool LineState { get; set; }
        private double[] Anchor { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            Dimension = 12;
            LineState = false;
            Anchor = null;
        }
        
        private void canvasDrawHere_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            var canvas = sender as Canvas;
            var where = e.GetPosition(canvas);
            var ball = new Ellipse();

            ball.Height = ball.Width = Dimension;
            ball.Margin = new Thickness(where.X - Dimension/2, where.Y - Dimension/2, 0, 0);
            ball.Fill = Brushes.Cyan;
            canvas.Children.Add(ball);
        }

        private void canvasDrawHere_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            var canvas = sender as Canvas;
            var where = e.GetPosition(canvas);
            var ball = new Ellipse();

            ball.Height = ball.Width = Dimension;
            ball.Margin = new Thickness(where.X - Dimension / 2, where.Y - Dimension / 2, 0, 0);
            ball.Fill = new SolidColorBrush(Color.FromRgb(120, 20, 20));
            canvas.Children.Add(ball);
        }

        private async void canvasLineHere_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            var canvas = sender as Canvas;
            var where = e.GetPosition(canvas);

            if (LineState)
            {
                canvas.Children.RemoveAt(canvas.Children.Count - 1);
                canvas.Children.Add(CreateLine(Anchor[0], Anchor[1], where.X, where.Y));
                Anchor = null;
                LineState = false;
            }
            else
            {
                Anchor = new double[] { where.X, where.Y };
                canvas.Children.Add(CreateLine(where.X, where.Y, where.X, where.Y));
                LineState = true;
                await MouseMoving();
            }
        }

        private async Task<bool> MouseMoving()
        {
            var canvas = this.canvasLineHere;
            var where = Mouse.GetPosition(canvas);

            while (LineState)
            {
                where = Mouse.GetPosition(canvas);
                canvas.Children.RemoveAt(canvas.Children.Count - 1);
                canvas.Children.Add(CreateLine(Anchor[0], Anchor[1], where.X, where.Y));
                await Task.Delay(10);
            }

            return false;
        }

        private Line CreateLine(double x1, double y1, double x2, double y2)
        {
            var line = new Line();
            line.Stroke = Brushes.Chartreuse;
            line.Margin = new Thickness(0, 0, 0, 0);
            line.X1 = x1;
            line.Y1 = y1;
            line.X2 = x2;
            line.Y2 = y2;
            line.StrokeThickness = Dimension;
            return line;
        }
    }
}
