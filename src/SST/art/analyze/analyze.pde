final color blue = color(138, 186, 211); // PANTONE PQ-14-4318TCX Sky Blue
final color yellow = color(252, 232, 131); // CRAYOLA Yellow

void setup() {
  size(500, 500);
  noLoop();
}

void draw() {
  background(blue);
  fill(yellow);
  textSize(height/2);
  textAlign(CENTER, CENTER);
  text("SST", 0, 0, width, height);
  save("icon.png");
}
