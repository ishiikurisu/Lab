package br.unb.biologiaanimal.test;

import br.unb.biologiaanimal.edf.EDF;
import br.unb.biologiaanimal.edf.EDFUtil;

public class Run {
    public static void main(String[] args) {
        System.out.println("--- # Testing utils");
        String randomString = "abc efg hij ";
        String[] chopped = EDFUtil.separateString(randomString, 3);
        System.out.println("Separating string:");
        for (int i = 0; i < 3; ++i)
        {
        	System.out.println("- " + chopped[i]);
        }
        System.out.println("25 celsius to fahrenheit:");        
        System.out.println("  Ans: " + EDFUtil.map(25, 100, 0, 212, 32) + "F");
        System.out.println("--- # Reading EDF file");
        EDF edf = new EDF("data\\linhadebase.edf");
        System.out.println("File: " + edf.getFile());
        System.out.println("Labels:");
        String[] labels = edf.getLabels();
        for (int i = 0; i < labels.length; ++i)
        {
        	System.out.println("- " + labels[i]);
        }
        System.out.println("--- # Let's write something");
        System.out.println("-- " + edf.write());
        System.out.println("-- Writing to ASCII format");
        edf.toAscii("data\\linhadebase.ascii");
        System.out.println("...");
    }
}
