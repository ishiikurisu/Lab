package br.unb.biologiaanimal.test;

import br.unb.biologiaanimal.edf.EDF;

public class Run {
    public static void main(String[] args) {
        System.out.println("---");
        EDF edf = new EDF("data\\linhadebase.edf");
        System.out.println("File: " + edf.getFile());
        System.out.println("Data: " + edf.getData());
        System.out.println("...");
    }
}
