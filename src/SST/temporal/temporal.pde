final int HEIGHT = 1000;
final int WIDTH = 128*4;
final color BLUE;
final color RED;
final color GREEN;
int[] time;
String[] procedure;

void setup() {
	size(WIDTH, HEIGHT, P2D);
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
