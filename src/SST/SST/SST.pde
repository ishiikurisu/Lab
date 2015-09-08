final int NUMBER_TRIALS = 8;
final int RUN_DURATION = 3500;
final int FIX_DURATION = 500;
final int TRIAL_DURATION = RUN_DURATION + FIX_DURATION;
final int SSD_STEP = 50;
final String RIGHT_DIR = "RIGHT";
final String LEFT_DIR = "LEFT";
final int INST_MSG = 1;
final int PRESS_MSG = 2;
final int FEEDBACK_MSG = 4;
final int EXIT_MSG = 8;
final int NOT_PRESS_MSG = 16;

int TEST_STEP = 0;
int STOP_SIGNAL_DELAY = 250;

boolean MUST_PRESS = true;
String INSTRUCTIONS_TEXT = new String();
String DIRECTION;
StringDict ALLOWED_KEYS;
StringList COMMANDS_HISTORY;
IntList TEST_STEPS;
PImage INSTRUCTIONS_IMAGE;
PImage LEFT_ARROW;
PImage RIGHT_ARROW;
PImage NO_ARROW;
PImage EMPTY_IMAGE;
PFont TEST_FONT;
int PAST;
int FUTURE;


/***********************
*   SETUP FUNCTIONS    *
***********************/

int getTestMoment()
{
    return minute() + hour() * 60;
}

void loadImages()
{
    /*
    LEFT_ARROW = loadImage("esquerda.png", "png");
    RIGHT_ARROW = loadImage("direita.png", "png");
    NO_ARROW = loadImage("fix.png", "png");
    */
}

void loadText()
{
    BufferedReader BR = createReader("instructions.txt");

    try {
        String line = BR.readLine();

        while (line != null)
        {
          INSTRUCTIONS_TEXT += line + "\n";
          line = BR.readLine();
        }
    }
    catch (Exception any) {
    }

}

void loadFonts()
{
    /*
    TEST_FONT = loadFont("sstfont  .ttf");
    textFont(TEST_FONT, 15);
    */
}

void loadKeys()
{
    BufferedReader BR = createReader("keys.txt");
    ALLOWED_KEYS = new StringDict();
    COMMANDS_HISTORY = new StringList();

    try {
        String line = BR.readLine();

        while (line != null)
        {
            String[] data = line.split(":");
            String key = data[0];
            String value = data[1];

            ALLOWED_KEYS.set(key, value);

            line = BR.readLine();
        }
    }
    catch (Exception any) {
    }

}

void createTest()
{
    TEST_STEPS = new IntList();

    TEST_STEPS.append(INST_MSG);
    for (int i = 0; i < NUMBER_TRIALS; ++i)
    {
        decideIfMustPress();
        if (MUST_PRESS)
            TEST_STEPS.append(PRESS_MSG);
        else
            TEST_STEPS.append(NOT_PRESS_MSG);
        TEST_STEPS.append(FEEDBACK_MSG);
    }
    TEST_STEPS.append(EXIT_MSG);
    TEST_STEP = 0;

    println(TEST_STEP);
}

/************************
*   DRAW FUNCTIONS      *
*************************/

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

void decideDirection()
{
    int dice = int(random(0, 17));

    switch (dice % 2)
    {
        case 0:
            DIRECTION = RIGHT_DIR;
        break;

        default:
            DIRECTION = LEFT_DIR;
    }
}

void instructions()
{
    text(INSTRUCTIONS_TEXT, 10, 10, width - 10, height - 10);
}

void run()
{
    int moment = millis() - PAST;

    if (moment > 0 && moment < FIX_DURATION) {

    }
    else if (moment > FIX_DURATION && moment < TRIAL_DURATION) {

    }
}

/************************
*   MAIN FUNCTIONS      *
************************/

void readData()
{
    if (keyPressed) {
        COMMANDS_HISTORY.append(str(key));
    }
}

void processData()
{
    /*
    INST_MSG: 1
    PRESS_MSG: 2
    FEEDBACK_MSG: 4
    EXIT_MSG: 8
    NOT_PRESS_MSG: 16
    */

    switch (TEST_STEPS.get(TEST_STEP))
    {
        case INST_MSG:
        case FEEDBACK_MSG:
        if (COMMANDS_HISTORY.size() > 0) {
            TEST_STEP++;
            PAST = millis();
        }
        break;

        case PRESS_MSG:
        case NOT_PRESS_MSG:
        break;

        case EXIT_MSG:
        break;
    }

    COMMANDS_HISTORY.clear();
}

void writeData()
{
    /*
    INST_MSG: 1;
    PRESS_MSG: 2;
    FEEDBACK_MSG: 4;
    EXIT_MSG: 8;
    NOT_PRESS_MSG: 16;
    */

    switch (TEST_STEPS.get(TEST_STEP))
    {
        case INST_MSG:
            instructions();
        break;

        case PRESS_MSG:
        case NOT_PRESS_MSG:
            // run();
        // break;

        case FEEDBACK_MSG:
        // break;

        case EXIT_MSG:
            exit();
        break;
    }

}


void setup()
{
    size(500, 500);
    background(0);
    textSize(16);
    textAlign(CENTER, CENTER);
    randomSeed(getTestMoment());

    loadImages();
    loadText();
    loadFonts();
    loadKeys();

    createTest();
    instructions();
}

void draw()
{
    readData();
    processData();
    writeData();
}
