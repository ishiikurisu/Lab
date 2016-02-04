import br.eng.crisjr.*;

public class boxing {
	public static void main(String[] args) {
		Cube joe = new Cube();

		for (String arg: args) {
			System.out.println(joe.evaluate(Integer.parseInt(arg)));
		}
	}
}