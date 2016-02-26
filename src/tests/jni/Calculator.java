public class Calculator
{
	public static void main(String[] args) {
		Summer summer = new Summer();
		int x = Integer.parseInt(args[0]);
		int y = Integer.parseInt(args[1]);
		int result = summer.sum(x, y);
		System.out.println("> " + result);
	}
}