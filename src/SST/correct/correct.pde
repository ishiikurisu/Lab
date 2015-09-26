final int WHITE = 254;
final int BLACK = 2;
final color GREEN = color(126, 200, 69); // PANTONE's Jasmine Green
final float PHI = (1 + sqrt(5))/2;

void setup() {
  size(500, 500);
  smooth();
  noLoop();
}

void draw() {
  float w = width;
  float h = height;
  float g = 12.0;
  float e = 1/PHI;

  background(WHITE);
  fill(GREEN);
  noStroke();

  quad(w, h/4,
    w - 2*g, h/4,
    h/PHI - g, h,
    h/PHI + g, h);
  quad(h/PHI + g, h,
    h/PHI - g, h,
    h*e/PHI - g, h - h*e/4,
    h*e/PHI + g, h - h*e/4);
  save("correct.jpg");
}
