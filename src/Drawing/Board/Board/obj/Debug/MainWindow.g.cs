﻿#pragma checksum "..\..\MainWindow.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "E9600804144CEADD3B8DB5C97E555910"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using Board;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace Board {
    
    
    /// <summary>
    /// MainWindow
    /// </summary>
    public partial class MainWindow : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 20 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Ellipse buttonBlack;
        
        #line default
        #line hidden
        
        
        #line 25 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Ellipse buttonRed;
        
        #line default
        #line hidden
        
        
        #line 30 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Ellipse buttonBlue;
        
        #line default
        #line hidden
        
        
        #line 35 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Ellipse buttonGreen;
        
        #line default
        #line hidden
        
        
        #line 40 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Shapes.Ellipse buttonWhite;
        
        #line default
        #line hidden
        
        
        #line 47 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Canvas canvasBoard;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/Board;component/mainwindow.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\MainWindow.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.buttonBlack = ((System.Windows.Shapes.Ellipse)(target));
            
            #line 24 "..\..\MainWindow.xaml"
            this.buttonBlack.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.buttonBlack_MouseLeftButtonDown);
            
            #line default
            #line hidden
            return;
            case 2:
            this.buttonRed = ((System.Windows.Shapes.Ellipse)(target));
            
            #line 29 "..\..\MainWindow.xaml"
            this.buttonRed.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.buttonRed_MouseLeftButtonDown);
            
            #line default
            #line hidden
            return;
            case 3:
            this.buttonBlue = ((System.Windows.Shapes.Ellipse)(target));
            
            #line 34 "..\..\MainWindow.xaml"
            this.buttonBlue.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.buttonBlue_MouseLeftButtonDown);
            
            #line default
            #line hidden
            return;
            case 4:
            this.buttonGreen = ((System.Windows.Shapes.Ellipse)(target));
            
            #line 39 "..\..\MainWindow.xaml"
            this.buttonGreen.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.buttonGreen_MouseLeftButtonDown);
            
            #line default
            #line hidden
            return;
            case 5:
            this.buttonWhite = ((System.Windows.Shapes.Ellipse)(target));
            
            #line 44 "..\..\MainWindow.xaml"
            this.buttonWhite.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.buttonWhite_MouseLeftButtonDown);
            
            #line default
            #line hidden
            return;
            case 6:
            this.canvasBoard = ((System.Windows.Controls.Canvas)(target));
            
            #line 50 "..\..\MainWindow.xaml"
            this.canvasBoard.MouseLeftButtonDown += new System.Windows.Input.MouseButtonEventHandler(this.canvasBoard_MouseLeftButtonDown);
            
            #line default
            #line hidden
            
            #line 51 "..\..\MainWindow.xaml"
            this.canvasBoard.MouseLeftButtonUp += new System.Windows.Input.MouseButtonEventHandler(this.canvasBoard_MouseLeftButtonUp);
            
            #line default
            #line hidden
            
            #line 52 "..\..\MainWindow.xaml"
            this.canvasBoard.MouseLeave += new System.Windows.Input.MouseEventHandler(this.canvasBoard_MouseLeave);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}

