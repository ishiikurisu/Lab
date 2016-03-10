public class Main {
	public static void main(String[] args) {
		Thread query = new Query("randomfile.txt");
		query.start();
		System.out.println("---");
	}
}