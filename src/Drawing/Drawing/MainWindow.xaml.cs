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

namespace Drawing
{
    public partial class MainWindow : Window
    {
        private double Dimension { get; set; }

        public MainWindow()
        {
            InitializeComponent();
            Dimension = 12;
        }
        
        private void canvasDrawHere_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            var canvas = sender as Canvas;
            var where = e.GetPosition(canvas);
            var ball = new Ellipse();

            ball.Height = ball.Width = Dimension;
            ball.Margin = new Thickness(where.X - Dimension/2, where.Y - Dimension/2, 0, 0);
            ball.Fill = new SolidColorBrush(Color.FromRgb(120, 20, 20));
            canvas.Children.Add(ball);
        }
    }
}
