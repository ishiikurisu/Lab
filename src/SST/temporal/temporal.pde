final int HEIGHT = 1000;
final int WIDTH = 128*4;
final color WHITE = color(254, 254, 254);
final color BLACK = color(0, 0, 0);
final color BLUE = color(0, 90, 146); // PANTONE's Imperial blue, 19-4245 TPX
final color RED = color(208, 28, 31); // PANTONE's Fiery red, 18-1664 TPX
final color GREEN = color(126, 200, 69); // PANTONE's Jasmine Green
int[] times;
String[] procedures;
boolean[] answers;

void setup() {
	size(HEIGHT, WIDTH);
	noLoop();
}

void draw() {
	Stopwatch stopwatch = new Stopwatch("sst.txt");
	times = stopwatch.getTimes();
	procedures = stopwatch.getProcedures();
	answers = stopwatch.getAnswers();

	smooth();
	noFill();
	background(WHITE);
	strokeWeight(4);

	for (int i = 0; i < 128; ++i)
	{
		/* write lines */
		if (procedures[i].compareTo("PressProc") == 0) {
			stroke((answers[i] == true)? GREEN : RED);
			line(2 + 4*i, 0, 2 + 4*i, times[i]);
		}
		else if (procedures[i].compareTo("NotPressProc") == 0) {
			stroke(BLUE);
			if (answers[i] == false) {
				line(2 + 4*i, height, 2 + 4*i, height - times[i]);
			}
			else {
				line(2 + 4*i, height/4, 2 + 4*i, 3*height/4);
			}
		}

	}

	// save("graph.jpg");
	exit();
}
