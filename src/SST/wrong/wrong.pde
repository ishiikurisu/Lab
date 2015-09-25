final color WHITE = color(254, 254, 254);
final color BLACK = color(2, 2, 2);
final color RED = color(208, 28, 31); /* PANTONE's Fiery red, 18-1664 TPX */
final float PHI = (1 + sqrt(5))/2.0;
final float ANGLE = atan(PHI);

void setup() {
  size(250, 250);
  smooth();
  noLoop();
}

void draw() {
  float g = 12.0;
  float p = (width*tan(ANGLE) - height/2) / tan(ANGLE);

  background(WHITE);
  fill(RED);
  noStroke();

  quad(
    width, height/2.0,
    width - 2*g, height/2.0,
    p - 2*g, height,
    p, height);
  quad(
    p, height/2.0,
    p -2*g, height/2.0,
    width -2*g, height,
    width, height);
  save("wrong.jpg");
}

