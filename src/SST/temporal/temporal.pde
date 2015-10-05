final int HEIGHT = 1000;
final int WIDTH = 128*4;
final color BLUE = color(0, 90, 146); // PANTONE's Imperial blue, 19-4245 TPX
final color RED = color(208, 28, 31); // PANTONE's Fiery red, 18-1664 TPX
final color GREEN = color(126, 200, 69); // PANTONE's Jasmine Green
int[] time;
String[] procedure;

void setup() {
	size(WIDTH, HEIGHT);
	noLoop();
}

void draw() {
	Stopwatch stopwatch = new Stopwatch("sst.csv");
	times = stopwatch.getTimes();
	processes = stopwatch.getProcedures();

	smooth();
	noFill();
	background(WHITE);

	for (int i = 0; i < 128; ++i)
	{
		/* decide color */

		/* write lines */
		if (procedure[i].compareTo("PressProc") == 0) {
			/* show RT */
		}
		else if (procedure[i].compareTo("NotPressProc") == 0) {
			/* show SSD */
		}
	}

	// save("graph.jpg");
	exit();
}
