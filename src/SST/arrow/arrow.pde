void setup() {
  size(500, 500);
  noLoop();
  background(0);
  stroke(255);
  strokeWeight(12);
  noFill();
  smooth();
}

void draw() {
  float PHI = (1.0 + sqrt(5)) / 2.0;
  float r = width / (2.0*PHI);
  float w = r / PHI;
  float a = w / PHI; 
  float h = (a * r) / w;
  
  translate(height/2, width/2);
  ellipse(0, 0, 2*r, 2*r);
  line(-w, 0, w, 0);
  
  /* LEFT ARROW */
  line(-w, 0, a-w, h);
  line(-w, 0, a-w, -h);
  /* */
  
  /* RIGHT ARROW
  line(w, 0, w-a, h);
  line(w, 0, w-a, -h);
  /* */
}
