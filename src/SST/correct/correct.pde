final int WHITE = 254;
final int BLACK = 2;
final color GREEN = color(126, 200, 69); // PANTONE's Jasmine Green
final float PHI = (1 + sqrt(5))/2;

void setup() {
  size(250, 250);
  smooth();
  noLoop();
}

void draw() {
  float w = width;
  float h = height;
  float g = 12.0;
  float e = 0.5;

  background(WHITE);
  fill(GREEN);
  noStroke();

  quad(w, h/2,
       w - 2*g, h/2,
       h/PHI - g, h,
       h/PHI + g, h);
  quad(h/PHI + g, h,
       h/PHI - g, h,
       h*e/PHI - g, h - h*e/2,
       h*e/PHI + g, h - h*e/2);
}

