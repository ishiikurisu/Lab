import java.awt.Container;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class QuitButtonEx extends JFrame 
{

    public QuitButtonEx() 
    {
        initUI();
    }

    private void initUI() 
    {
        JButton quitButton = new JButton("Quit");

        quitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
                System.exit(0);
            }
        });

        createLayout(quitButton);
        setTitle("Quit button");
        setSize(300, 200);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void createLayout(JComponent... arg) 
    {
        Container pane = getContentPane();
        GroupLayout gl = new GroupLayout(pane);

        pane.setLayout(gl);
        gl.setAutoCreateContainerGaps(true);
        gl.setHorizontalGroup(gl.createSequentialGroup().addComponent(arg[0]));
        gl.setVerticalGroup(gl.createSequentialGroup().addComponent(arg[0]));
    }

    public static void main(String[] args) 
    {
        try {
            // Set System L&F
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } 
        catch (UnsupportedLookAndFeelException e) {
           // handle exception
        }
        catch (ClassNotFoundException e) {
           // handle exception
        }
        catch (InstantiationException e) {
           // handle exception
        }
        catch (IllegalAccessException e) {
           // handle exception
        }

        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                QuitButtonEx ex = new QuitButtonEx();
                ex.setVisible(true);
            }
        });
    }
}