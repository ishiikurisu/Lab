final int WEIGHT = 8;
final int HEIGHT = 500;
final int WIDTH = 128*WEIGHT;
final color WHITE = color(254, 254, 254);
final color BLACK = color(0, 0, 0);
final color BLUE = color(0, 90, 146); // PANTONE's Imperial blue, 19-4245 TPX
final color RED = color(208, 28, 31); // PANTONE's Fiery red, 18-1664 TPX
final color GREEN = color(126, 200, 69); // PANTONE's Jasmine Green
final color YELLOW = color(255, 158, 33); // PANTONE's Radiant yellow, 15-1058 TPX

void setup() {
  size(WIDTH, HEIGHT);
  noLoop();
}

void draw() {
  BufferedReader reader = createReader("sst.data");
  String[] rawData;
  String procedure;
  boolean answer;
  int time;
  int x;

  smooth();
  noFill();
  background(WHITE);
  strokeWeight(WEIGHT);

  for (int i = 0; i < 128; ++i)
  {
    try { rawData = reader.readLine().split("\\s+"); }
    catch (IOException ioe) { break; }
    procedure = rawData[0];
    answer = (rawData[1].trim().compareTo("1") == 0)? true : false;
    time = Integer.parseInt(rawData[2]);

    x = WEIGHT/2 + i*WEIGHT;
    if (procedure.compareTo("PressProc") == 0) {
      stroke((answer == true)? GREEN : RED);
      line(x, height, x, height - time/2);
    }
    else if (procedure.compareTo("NotPressProc") == 0) {
      if (answer == false) {
      stroke(YELLOW);
        line(x, height, x, height - time/2);
      }
      else {
        stroke(BLUE);
        line(x, height/4, x, 3*height/4);
      }
    }
  }

  save("graph.jpg");
  // exit();
}

