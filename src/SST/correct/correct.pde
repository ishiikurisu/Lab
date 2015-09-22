final int WHITE = 254;
final int BLACK = 2;
final int GREEN = 125;
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
  fill(126, 200, 69);
  noStroke();

  quad(w, h/2,
       w - 2*g, h/2,
       h/PHI - g, h,
       h/PHI + g, h);
  quad(h/PHI + g, h,
       h/PHI - g, h,
       h*e/PHI/2 - g, h/2 - h*e/2,
       h*e/PHI/2 + g, h/2 - h*e/2);
}

