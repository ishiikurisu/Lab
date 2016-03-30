final float MOO = 0.1;
final int WIDTH = 600;
final int HEIGHT = 600;
final color PANTONE_4545CP = #E1D7AE;
final color BLACK = #000000;
int NO_SQUARES = 1;

void setup() {
  size(WIDTH, HEIGHT);
  noStroke();
}

void draw() {
  float g = (NO_SQUARES == 1)? 0 : (HEIGHT * MOO * (1-MOO)) / (NO_SQUARES-1);
  float h = (HEIGHT * pow(1-MOO, 2)) / NO_SQUARES;
  float w = WIDTH * (1-MOO);
  float x = WIDTH * MOO / 2.0;

  background(PANTONE_4545CP);
  fill(BLACK);
  for (int i = 0; i < NO_SQUARES; ++i) {
    rect(x, // x coordinate
         HEIGHT*MOO/2 + i*(h+g), // y coordinate
         w, // width
         h); // height
  }
}

void keyPressed() {
  switch (key) {
    case '+':
      NO_SQUARES++;
    break;

    case '-':
      NO_SQUARES--;
    break;
  }
}


