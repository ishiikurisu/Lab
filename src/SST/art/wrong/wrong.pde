final color WHITE = color(254, 254, 254);
final color BLACK = color(2, 2, 2);
final color RED = color(208, 28, 31); /* PANTONE's Fiery red, 18-1664 TPX */
final float PHI = (1 + sqrt(5))/2.0;
final float ANGLE = atan(PHI);

void setup() {
  size(500, 500);
  smooth();
  noLoop();
}

void draw() {
  float h = height/2;
  float w = width/2;
  float g = 9.0;
  float p = (w*tan(ANGLE) - h/2) / tan(ANGLE);

  translate(height/2, width/2);
  background(WHITE);
  fill(RED);
  noStroke();

  quad(
    w, h/2.0,
    w - 2*g, h/2.0,
    p - 2*g, h,
    p, h);
  quad(
    p, h/2.0,
    p -2*g, h/2.0,
    w -2*g, h,
    w, h);
  save("wrong.jpg");
}
