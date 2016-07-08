PACI
====

This is an implementation of the PACI. It was made to be ran on Microsoft Windows XP onwards. Even though the documentation is in English, it was written in Portuguese. Really nice of me.


For Psychologists
-----------------

`TODO: WRITE THIS PART`

For Engineers
-------------

This application is a sequence of Windows Forms that will run on loop until the first form is closed. These forms are:

1. `Form1.cs` (I did not change its name, I know)
2. `FormArea.cs`
3. `FormRank.cs`
4. `FormGoal.cs`
5. `FormThanks.cs`

The first form contains the main screen. It is just a box asking for the subject's name and a button to begin the test. The application can only end here. Any time the user presses the quit button (that red `X` on the top of the screen), the application will return to this state. Before proceeding to the next form, the application will instruct the user with the text inside the `instructions1.txt` and `instructions2.txt` files.

The second form is the template for that part asking for the subject's life areas. This window will retrieve the lines from a file called `Matters.txt` from the `Assets` folder and, for each matter, will ask for 3 life goals.

The third form is the ranking window. It will take the user's ranking and sort the life areas according to it. If the user opts it out, then the application will leave the life areas order as they were given.

The fourth form is where the subject will spend most their time in this inventory.Before the user actually answer the questionnaire, this form will instruct the user with the text available in the `QuestionnaireText.txt` file. This form will save every question as described in the `AnswerSheetQuestions.txt` file, and for each life goal, it will ask those questions and save them by the end of its execution in the `Results` folder.

The final form is a "Thank You!" window. Its callback makes the application restart its loop.

There also is a peculiar form called `FormText.cs` used to display messages without any special side-effect on the program. To use this form, it is necessary to configure it by setting it like this:

``` C#
/* this code is running inside some form */
FormText instructions;

void test()
{
	Instructions = new FormText();
	Instructions.Text = "Some text";
	Instructions.HowToProceed(this.goOn);
	Instructions.Show();
}

void goOn(object sender, EventArgs e)
{
	// this will close the window when
	// the user press the window's button
	instructions.Close();
}
```
