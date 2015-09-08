int NUMBER_TRIALS = 8;
int RUN_DURATION = 3500;
int FIX_DURATION = 500;
int TRIAL_DURATION = RUN_DURATION + FIX_DURATION;
int SSD_STEP = 50;

int TEST_STEP = 0;
int STOP_SIGNAL_DELAY = 250;

boolean MUST_PRESS = true;
String INSTRUCTIONS_TEXT = new String();
int DIRECTION = 0;
StringDict ALLOWED_KEYS;
StringList COMMANDS_HISTORY;
int PAST;
int FUTURE;


/***********************
*   SETUP FUNCTIONS    *
***********************/

int getTestMoment()
{
    return minute() + hour() * 60;
}

void loadText()
{
    BufferedReader BR = createReader("instructions.txt");

    try {
        String line = BR.readLine();
        println(line);

        while (line != null)
        {
          INSTRUCTIONS_TEXT += line + "\n";
          line = BR.readLine();
          println(line);
        }
    }
    catch (Exception any) {
    }

}

void loadKeys()
{
    BufferedReader BR = createReader("keys.txt");
    ALLOWED_KEYS = new StringDict();
    COMMANDS_HISTORY = new StringList();

    try {
        String line = BR.readLine();
        println(line);

        while (line != null)
        {
            String[] data = line.split(":");
            String key = data[0];
            String value = data[1];

            ALLOWED_KEYS.set(key, value);
            line = BR.readLine();
            println(line);
        }
    }
    catch (Exception any) {
    }

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
            DIRECTION = 1;
        break;

        default:
            DIRECTION = -1;
    }
}

void instructions()
{
    background(0);
    text(INSTRUCTIONS_TEXT, 10, 10, width - 10, height - 10);
}

void feedback()
{
    background(0);
    text("this is a feedback image", 10, 10, width - 10, height - 10);
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
    if (TEST_STEP > 2 * NUMBER_TRIALS) {
        exit();
    }
    else if (TEST_STEP % 2 == 0) {
        if (COMMANDS_HISTORY.size() > 0)
            TEST_STEP++;
    }
    else {
        exit();
    }

    COMMANDS_HISTORY.clear();
}

void writeData()
{
    if (TEST_STEP == 0) {
        instructions();
    }
    else if (TEST_STEP % 2 == 0) {
        feedback();
    }
    else {

    }

}


void setup()
{
    size(500, 500);
    background(0);
    textSize(16);
    textAlign(CENTER, CENTER);
    randomSeed(getTestMoment());

    println("NOW LOADING...");
    loadText();
    loadKeys();
    println("LOADED!");

    TEST_STEP = 0;
}

void draw()
{
    readData();
    processData();
    writeData();
}









