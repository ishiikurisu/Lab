package kun;

import javax.swing.JOptionPane;

public class Domo
{

    public static void main(String[] args)
    {
	   String inputValue = JOptionPane.showInputDialog("Say hello to Domo!");
	   JOptionPane.showMessageDialog(null, "Domo says \"" + inputValue + "\" too!");
	}

}
