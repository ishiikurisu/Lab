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
  float w = width/2;
  float h = height/2;
  float g = 9.0;
  float e = 1/PHI;

  background(WHITE);
  fill(GREEN);
  noStroke();
  translate(width/2, height/2);

  quad(w, h/2,
    w - 2*g, h/2,
    h/PHI - g, h,
    h/PHI + g, h);
  quad(h/PHI + g, h,
    h/PHI - g, h,
    h*e/PHI - g, h - h*e/2,
    h*e/PHI + g, h - h*e/2);
  save("correct.jpg");
}
