import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.*;

public class Transformation {
    static BufferedReader BR;
    static InputStreamReader ISR;

    public static void main(String[] args) throws IOException {
        ISR = new InputStreamReader(System.in);
        BR = new BufferedReader(ISR);
        String line = BR.readLine();

        while (line != null) {
            System.out.println(line.replaceAll("\\[\\d+\\]", "\\\\item "));
            line = BR.readLine();
        }

        BR.close();
        ISR.close();
    }
}