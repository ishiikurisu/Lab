void setup() {
  size(250, 250);
  noLoop();
  background(254);
  smooth();
}

void draw() {
  float PHI = (1.0 + sqrt(5)) / 2.0;
  float r = width / (2.0*PHI);
  float w = r / PHI;
  float a = w / PHI; 
  float h = (a * r) / w;
  float g = 6.0;
  
  /* outside */
  translate(height/2, width/2);
  stroke(2);
  strokeWeight(12);
  noFill();
  ellipse(0, 0, 2*r, 2*r);
  /* inner line */
  noStroke();
  fill(2);
  quad(-w, -g, w*0.9, -g, w*0.9, g, -w, g);
  
  /* LEFT ARROW */
  quad(-w-g, 0, -w+a-g, (w-a)*PHI, -w+a+g, (w-a)*PHI, -w+g, 0);
  quad(-w-g, 0, -w+a-g, (a-w)*PHI, -w+a+g, (a-w)*PHI, -w+g, 0);
  /* */
  
  /* RIGHT ARROW
  quad(w+g, 0, w-a+g, (w-a)*PHI, w-a-g, (w-a)*PHI, w-g, 0);
  quad(w+g, 0, w-a+g, (a-w)*PHI, w-a-g, (a-w)*PHI, w-g, 0);
  /* */
}





