import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;

class Query extends Thread {
	private final String warning = "/!\\ SOME SHIT HAPPENNED";
	private String inlet;

	public Query(String inlet) {
		this.inlet = inlet;
	}

	public void run() {
		try {
			BufferedReader BR = new BufferedReader(
				                new InputStreamReader(
				                new FileInputStream(this.inlet)));
			Thread.sleep(5000);	
			String line = queryNextLine(BR);
			while (line.length() > 0) {
				System.out.println("- " + line);	
				line = queryNextLine(BR);
			}
		} 
		catch (IOException ioe) {
			System.out.println(this.warning);
		}
		catch (InterruptedException ioe) {
			System.out.println(this.warning);
		}
	}

	private String queryNextLine(BufferedReader br) throws IOException {
		String outlet = "";
		String temp = "";

		try {
			do {
				temp = br.readLine();
			} while (temp.length() <= 1);
			outlet = temp;
		}
		catch (NullPointerException ioe) {
			outlet = "";
		}

		return outlet;
	}
}