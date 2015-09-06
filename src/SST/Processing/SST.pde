final int NUMBER_TRIALS = 8;
final int RUN_DURATION = 3500;
final int SSD_STEP = 50;
int STOP_SIGNAL_DELAY = 250;
boolean MUST_PRESS = true;

PImage INSTRUCTIONS_IMAGE;
String INSTRUCTIONS_TEXT;
PImage LEFT_ARROW;
PImage RIGHT_ARROW;
PImage EMPTY_IMAGE;
PFont TEST_FONT;


/***********************
*   SETUP FUNCTIONS    *
***********************/

int getTestMoment()
{
  return minute() + hour() * 60;
}

void loadImages()
{
  LEFT_ARROW = loadImage("esquerda.png");
  RIGHT_ARROW = loadImage("direita.png");
  NO_ARROW = loadImage("fix.png");
}

void loadText()
{
  BufferedReader BR = createReader("instructions.txt");

  while (true)
  {
    try {
      INSTRUCTIONS_TEXT += BR.readLine();
    }
    catch (Exception any) {
      break;
    }
  }

  return;
}

void loadFonts()
{
  
}

/*
*   DRAW FUNCTIONS
*/

void decideIfMustPress()
{
  int dice = int(random(0, 5));

  switch (dice)
  {
    case 0:
    case 1:
    case 2:
      MUST_PRESS = true;
    break;

    default:
     MUST_PRESS = false;
  }
}
void instructions()
{
}

/*
*   SCREEN FUNCTIONS
*/

/*
*   MAIN FUNCTIONS
*/

void run()
{


  if (MUST_PRESS) {
  }


}

void setup()
{
  size(500, 500);
  randomSeed(getTestMoment());

  loadImages();
  loadText();
  loadFonts();
}

void draw()
{
  instructions();

  for (int i = 0; i < NUMBER_TRIALS; ++i)
  {
    decideIfMustPress();
    run();
  }

  ending();
  exit();
}
