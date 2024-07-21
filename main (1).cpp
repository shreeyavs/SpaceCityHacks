/*
This app is designed to educate people about mental health, 
and also allow them to improve their mental health through various
quizzes and activities
@author Shreeya Sarurkar
*/
#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;
// Boolean used to check if the user wants to end the application
bool done = false;
// Variable used to store the amount of points the user has accumulated
int points;
// Vector used to store the user's goals
vector <string> goals;

// Function prototypes
void goalsFunc();
void quizFunc();
void gameFunc();
void stressAssessment();
void sleepAssessment();
void randomActivityGenerator();
void mindfulBreathing();

int main() {
  // While loop to keep the application running until the user wants to end it
  while (!done) {
    string menuChoice = "";
    int menuNum = 0;
    // Introduces the app menu, and allows the user to choose which option they want to go to first
    cout << "Goals       Quiz       Games\n";
    cout << "================================\n";
    cout << "Enter 'end' at any point to end the app\nSelect one of the above options to start\n";
    cin >> menuChoice;
    for (int i = 0; i < menuChoice.length(); i++) {
      menuChoice[i] = toupper(menuChoice[i]);
    }
    if (menuChoice == "GOALS") {
      menuNum = 1;
    } else if (menuChoice == "QUIZ") {
      menuNum = 2;
    } else if (menuChoice == "GAMES") {
      menuNum = 3;
    } else if (menuChoice == "END") {
      cout << "Thanks for using the app!";
      done = true;
      return 0;
      // Input validation to ensure the user enters a valid option
    } else {
      cout << "Invalid input. Please try again.";
    }
    if (menuNum == 1) {
      goalsFunc();
    } else if (menuNum == 2) {
      quizFunc();
    } else if (menuNum == 3) {
      gameFunc();
    } else {
      // Input validation to ensure the user enters a valid option
      cout << "Invalid input. Please try again.";
    }
  }
}

/*
Function which allows the user to set their goals, as well as complete any goals for points
*/
void goalsFunc() {
  string goal = "";
  string userInput = "";
  int index = 0;
  cout << "Here you can set any relevant goals for yourself, in order to reference at a later time.\nSetting goals and completing them can also earn you points!\nWould you like to set a goal or complete one? (Enter 'set' to set a goal or 'complete' to complete one)\n";
  cin >> userInput;
  for (int i = 0; i < userInput.length(); i++) {
    userInput[i] = toupper(userInput[i]);
  }
  if (userInput == "SET") {
    cin.ignore();
    cout << "Enter your goal: ";
    getline(cin, goal);
    goals.push_back(goal);
    goal = "";
    userInput = "";
    cout << "Your goal has been saved!";
    cout << "Your current goals are: \n";
    for (int i = 0; i < goals.size(); i++) {
      cout << i + 1 << ". " << goals[i] << "\n";
    }
    cout << "\nWould you like to go back to the menu? (Enter yes/no)\n"; 
    cin >> userInput;
    for (int i = 0; i < userInput.length(); i++) {
      userInput[i] = toupper(userInput[i]);
    } if (userInput == "YES") {
      main();
    } else {
      cout << "Thank you for using this app!";
      done = true;
    }
  } else if (userInput == "COMPLETE") {
    cout << "Here is your list of goals: \n";
    for (int i = 0; i < goals.size(); i++) {
      cout << i + 1 << ". " << goals[i] << "\n";
    }
    cout << "Enter the number of the goal you would like to complete: ";
    cin.ignore();
    cin >> index;
    index--;
    cout << index;
    cout << "You have completed the goal: " << goals[index] << " and have earned 1 points\nGreat job!\n";
    goals.erase(goals.begin() + index);
    points++;
    cout << "Your current goals list is: \n";
    for (int i = 0; i < goals.size(); i++) {
      cout << i + 1 << ". " << goals[i] << "\n";
    }
  }
}

/*
Function which allows the user to complete 1 of 2 quizzes, which will let them get a better understanding of their stress and sleep levels.
They can also earn points for completing these quizzes.
*/

void quizFunc() {
  string userInput = "";
  string stress = "STRESS LEVEL ASSESSMENT";
  string sleep = "SLEEP ASSESSMENT";
  cout << "Welcome to the quiz dashboard! Which quiz would you like to "
          "take?\nStress level assessment\nSleep assessment\n";
  cin >> userInput;
  for (int i = 0; i < userInput.length(); i++) {
    userInput[i] = toupper(userInput[i]);
  }
  // User doesn't have to enter the full name of the quiz; instead, the program will make sure the quiz name contains the input
  bool isFound = stress.find(userInput) != string::npos;
  bool isFound2 = sleep.find(userInput) != string::npos;
  if (isFound) {
    cout << "Welcome to the stress level assessment!\n";
    stressAssessment();
    points++;
  } else if (isFound2) {
    cout << "Welcome to the sleep assessment!\n";
    sleepAssessment();
    points++;
  } else if (userInput == "END") {
    cout << "Thanks for using the app!";
    done = true;
  } else {
    cout << "\nThat isn't a valid quiz. Please enter something else to start!\n";
  }
}

void stressAssessment() {
  const int ARR_SIZE = 10;
  int answerNum = 0;
  int score = 0;
  // Questions that the program will ask in the quiz
  string questions[10] = {
      "How frequently do you find yourself overwhelmed by stress?",
      "How often do you feel like you are not able to control your emotions?",
      "How often do you experience physical symptoms of stress (such as "
      "headaches)",
      "How often do you find it difficult to concentrate under "
      "pressure/difficult conditions?",
      "How often do you engage in activities designed to unwind and relax from "
      "stress?",
      "How often do you feel like you are not able to focus due to anxiety or "
      "stress?",
      "How often do you experience irritability or mood swings?",
      "How often do you feel a sense of dread or anxiety about making "
      "decisions or upcoming responsiblities?",
      "How often do you find it difficult to make decisions, even about simple "
      "things?",
      "How often do you find it hard to focus in school or at work?"};
  int answers[10];
  cout << "For each question enter: \n0: Never\n1: Sometimes\n2: "
          "Often\n3: Always\n";
  // First, appends each answer into the answers array
  for (int i = 0; i < ARR_SIZE; i++) {
    cout << i + 1 << ". " << questions[i] << endl;
    cin >> answerNum;
    answers[i] = answerNum;
    answerNum = 0;
  }
  // Then, takes the score by adding up all values in the answers array, and displays this score for the user. 
  for (int i = 0; i < ARR_SIZE; i++) {
    score += answers[i];
  }
  cout << "\nThank you for completing this quiz. Here are your results:" << endl;
  cout << "Your score is " << score << endl;
  // Based on the score, the program will display a message to the user, and give them a suggestion on how to improve their stress levels
  if (score >= 24) {
    cout << "You have a high stress level. Consider talking to a therapist or "
            "seeking professional help.";
  } else if (score >= 15) {
    cout << "You have a moderate stress level. Consider actively taking part "
            "in stress relieving activites, such as journalling, meditation, "
            "or yoga.";
  } else {
    cout << "You have a low stress level. Keep it up!";
  }
  main();
}

void sleepAssessment() {
  const int ARR_SIZE = 10;
  int answerNum = 0;
  int score = 0;
  // Questions that the program will ask in the quiz
  string questions[10] = {
      "How often do you get less than 8 hours of sleep for more than 2 nights?",
      "How often do you feel tired in the morning or have difficulty wake up?",
      "How often do you wake up in the middle of the night?",
      "How often do you find it difficult to fall asleep?",
      "How often do you experience vivid dreams or nightmares?",
      "How often do you use medication to try to sleep better?",
      "How often do you feel restless or anxious when trying to sleep?",
      "How often do you use your phone or other electronic devices at least 1 "
      "hour before going to sleep?",
      "How frequently do you take naps during the day?",
      "How often do you feel like your sleep is unrefreshing?"};
  int answers[10];
  cout << "For each question enter: \n0: Never\n1: Sometimes\n2: "
          "Often\n3: Always\n";
  // First, appends each answer into the answers array
  for (int i = 0; i < ARR_SIZE; i++) {
    cout << i + 1 << ". " << questions[i] << endl;
    cin >> answerNum;
    answers[i] = answerNum;
    answerNum = 0;
  }
  // Then, takes the score by adding up all values in the answers array, and displays this score for the user.
  for (int i = 0; i < ARR_SIZE; i++) {
    score += answers[i];
  }
  cout << "Thank you for completing this quiz. Here are your results:\n"
       << endl;
  cout << "Your sleep score was " << score << endl;
  // Based on the score, the program will display a message to the user, and give them a suggestion on how to improve their sleep levels.
  if (score >= 24) {
    cout << "Your sleep patterns seems to be quite unhealthy. Consider talking "
            "to a therapist or seeking professional help.";
  } else if (score >= 15) {
    cout << "Your sleep patterns are moderately healthy. To improve your sleep "
            "even further, consider\n1. Maintaining a consistent sleep "
            "schedule\n2. Limit electronic usage at least 1-2 hours before "
            "bedtime\n3. Avoid caffeine and large meals, especially close to "
            "bedtime.";
  } else {
    cout << "You have a very healthy sleep schedule. Keep it up!";
  }
  main();
}

/*
Function which allows the user to choose 1 of two relaxing activies, which can further help to manage their stress levels. 
*/

void gameFunc() {
  string userInput = "";
  string story = "RANDOM ACTIVITY GENERATOR";
  string breathe = "MINDFUL BREATHING";
  cout << "Welcome to the game dashboard! Which game would you like to "
          "play?\nRandom Activity Generator\nMindful Breathing\n";
  cin >> userInput;
  for (int i = 0; i < userInput.length(); i++) {
    userInput[i] = toupper(userInput[i]);
  }
  // User doesn't have to enter the full name of the game; instead, the program will make sure the game name contains the input
  bool isFound = story.find(userInput) != string::npos;
  bool isFound2 = breathe.find(userInput) != string::npos;
  if (isFound) {
    cout << "Welcome to the random activity generator!\n";
    randomActivityGenerator();
    points++;
  } else if (isFound2) {
    cout << "Welcome to the mindful breathing game!\n";
    mindfulBreathing();
    points++;
  } else if (userInput == "END") {
    cout << "Thanks for using the app!";
    done = true;
  } else {
    cout << "That isn't a valid game. Please enter something else to start!\n";
  }
}

/*
Function which allows the user to generate any number (of their choosing) of random activities, which can help to lower stress levels and have been pre-set in the program. 
*/

void randomActivityGenerator() {
  string userInput = "";
  int recNum = 0;
  // Array of activities that the program will randomly select from
  string activities[50] = {"Practice deep breathing exercises", "Meditate for 10-15 minutes", "Do a yoga session", "Take a walk", "Read a book", "Listen to music", "Do a puzzle", "Journal", "Bake cookies or another treat", "Watch your favorite movie or TV show", "Learn a new language", "Write a short story", "Organize a room or space", "Practice drawing or sketching", "Learn a new skill, like painting or crocheting", "Do a home workout", "Plant succulents or small indoor plants", "Cook your favorite meal", "Create a scrapbook", "Have a virtual game night", "Have a karaoke night with friends", "Watch an interesting documentary", "Virtually explore exciting landmarks", "Do a DIY project", "Create a daily gratitude jar", "Watch a sunrise or sunset", "Explore AR/VR experiences", "Create a photo album", "Try aromatherapy", "Listen to a relaxing podcast", "Create a DIY mini indoor garden", "Try laughter therapy", "Take part in community service", "Plan a dream vacation", "Practice a digital detox", "Research a new culture", "Try a virtual scavenger hunt", "Create a playlist of favorite childhood songs", "Create a gratitude collage", "Try a new form of exercise", "Create a bucket list", "Experiment with skincare/makeup", "Try a new food recipe", "Have a picnic with friends/family", "Research something that interests you", "Have a virtual storytelling session with family/friends", "Organize a group discussion/debate about something that interests you", "Organize a community service day with an organization of your choice", "Write a thank you letter", "Create a reading nook with pillows and blankets to read your favorite book"};
  // User can enter how many recommendations they want to generate
  cout << "How many recommendations would you like?\n";
  cin >> recNum;
  for (int i = 0; i < recNum; i++) {
    cout << activities[rand() % 50] << "\n" << endl;
  }
  // User can choose to go back to the menu or generate more recommendations
  cout << "\nWould you like more recommendations, or go back to the menu?\nEnter 'more' for more recommendations and 'menu' to go back to the menu\n";
  cin >> userInput;
  for (int i = 0; i < userInput.length(); i++) {
    userInput[i] = toupper(userInput[i]);
  }
  if (userInput == "MORE") {
    randomActivityGenerator();
  } else {
    main();
  }
}

/*
Function which allows the user to complete a mindful breathing exercise, which can also be used to lower stress levels
*/
void mindfulBreathing() {
  string userInput = "";
  cout << "Press enter to start";
  // Waits for the user to press enter before starting the timer
  cin.ignore();
  cin.get();
  cout << "Ok let's start!\n";
  for (int i = 0; i < 5; i++) {
    sleep(1);
    cout << "\nInhale\n";
    sleep(1);
    cout << "1...";
    sleep(1);
    cout << "2...";
    sleep(1);
    cout << "3\n";
    cout << "Now hold for a couple seconds\n";
    sleep(1);
    cout << "1...";
    sleep(1);
    cout << "2...";
    sleep(1);
    cout << "3\n";
    cout << "Exhale\n";
    sleep(1);
    cout << "1...";
    sleep(1);
    cout << "2...";
    sleep(1);
    cout << "3\n";
    sleep(1);
  }
  cout << "Great job, you have completed this breathing exercise!";
  cout << " Would you like to go back to the menu? (Yes/No)\n";
  cin >> userInput;
  for (int i = 0; i < userInput.length(); i++) {
    userInput[i] = toupper(userInput[i]);
  }
  if (userInput == "YES") {
    main();
  } else {
    cout << "Ok, thanks for using this app!";
  }
}
