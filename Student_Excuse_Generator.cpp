/**
 * excuse_generator_enhanced.cpp
 * 
 * ENHANCED VERSION - Colorful Homework Excuse Generator
 * 
 * Features:
 * - 20+ creative, tech-themed excuse templates
 * - Colorful terminal output using ANSI escape codes
 * - Beautiful ASCII art headers
 * - Input validation
 * - Multiple excuses support
 * - No repetition (tracks used excuses)
 * - Run again functionality
 * 
 * Author: Excuse Generator Team
 * Version: 2.0 - Ultra Edition
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <limits>

using namespace std;

// ANSI Color Codes for terminal colors
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string LIGHT_RED = "\033[91m";
const string LIGHT_GREEN = "\033[92m";
const string LIGHT_YELLOW = "\033[93m";
const string LIGHT_BLUE = "\033[94m";
const string LIGHT_MAGENTA = "\033[95m";
const string LIGHT_CYAN = "\033[96m";
const string WHITE = "\033[37m";
const string LIGHT_WHITE = "\033[97m";

/**
 * Clear the terminal screen
 */
void clearScreen() {
    cout << "\033[2J\033[1;1H";  // ANSI escape to clear and go to top
}

/**
 * Print an ASCII art header
 */
void printHeader() {
    cout << RESET << endl;
    cout << LIGHT_YELLOW << "Welcome to the Ultimate Homework Excuse Generator!" << RESET << endl;
    cout << LIGHT_CYAN << "Get ready for some CREATIVE excuses!" << RESET << endl;
    cout << endl;
}

/**
 * Print a separator line
 */
void printSeparator(const string& pattern = "-", int width = 50) {
    cout << LIGHT_BLUE;
    for (int i = 0; i < width; i++) {
        cout << pattern;
    }
    cout << RESET << endl;
}

/**
 * Print a decorative border
 */
void printBorder(const string& text, const string& color = LIGHT_CYAN) {
    int len = text.length();
    int padding = (50 - len) / 2;
    cout << color << "║" << RESET;
    for (int i = 0; i < padding; i++) cout << " ";
    cout << BOLD << LIGHT_YELLOW << text << RESET;
    for (int i = 0; i < 50 - len - padding; i++) cout << " ";
    cout << color << "║" << RESET << endl;
}

/**
 * Print an excuse with dramatic presentation
 */
void printExcuseDramatic(const string& excuse, int currentNum, int total) {
    // Excuse number display
    cout << endl;
    cout << LIGHT_BLUE << "EXCUSE #" << currentNum << " OF " << total << RESET << endl;
    printSeparator("=", 50);
    
    // The excuse with creative flair
    cout << LIGHT_YELLOW << BOLD << "YOUR EXCUSE:" << RESET << " " << LIGHT_WHITE << excuse << RESET << endl;
    
    printSeparator("-", 50);
}

/**
 * Get user's name with validation (letters only, no numbers)
 */
string getUserName() {
    string name;
    
    while (true) {
        cout << endl;
        cout << LIGHT_CYAN << "Enter your name, student: " << RESET;
        
        // Use getline to properly read the input
        getline(cin, name);
        
        // Validate - check not empty
        if (name.length() == 0) {
            cout << LIGHT_RED << "Hey! You can't enter nothing! Try again!" << RESET << endl;
            continue;
        }
        
        // Check minimum length
        if (name.length() < 3) {
            cout << LIGHT_RED << "Name must be at least 3 characters long!" << RESET << endl;
            continue;
        }
        
        // Check for valid characters - ONLY letters and spaces allowed (no numbers)
        bool valid = true;
        for (size_t i = 0; i < name.length(); i++) {
            if (!isalpha(name[i]) && name[i] != ' ') {
                valid = false;
                break;
            }
        }
        
        if (!valid) {
            cout << LIGHT_RED << "Invalid name! Use letters only (no numbers or special characters)!" << RESET << endl;
            continue;
        }
        
        // Make it look cool - capitalise first letter
        name[0] = toupper(name[0]);
        break;
    }
    
    return name;
}

/**
 * Get number of excuses to generate
 */
int getExcuseCount() {
    string input;
    int count = 0;
    
    while (true) {
        cout << LIGHT_MAGENTA << "How many excuses do you want? (1-5): " << RESET;
        cin >> input;
        
        stringstream ss(input);
        if (ss >> count && count >= 1 && count <= 5) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return count;
        } else {
            cout << LIGHT_RED << "Please enter a number between 1 and 5!" << RESET << endl;
        }
    }
}

/**
 * Generate a random unique excuse (no repetition)
 */
string generateUniqueExcuse(const string& name, const vector<string>& excuses, vector<int>& usedIndices) {
    // If we've used all excuses, reset
    if (static_cast<int>(usedIndices.size()) >= static_cast<int>(excuses.size())) {
        usedIndices.clear();
    }

    int index;
    bool isUnique = false;

    // Keep generating until we find an unused index
    do {
        index = rand() % excuses.size();
        if (find(usedIndices.begin(), usedIndices.end(), index) == usedIndices.end()) {
            isUnique = true;
            usedIndices.push_back(index);
        }
    } while (!isUnique);

    // Get the selected excuse template
    string excuse = excuses[index];
    
    // Replace {name} placeholder with actual name
    size_t position = excuse.find("{name}");
    while (position != string::npos) {
        excuse.replace(position, 6, name);
        position = excuse.find("{name}", position + name.length());
    }
    
    return excuse;
}

/**
 * Ask if user wants to run again
 */
bool runAgain() {
    string input;
    
    cout << LIGHT_CYAN << "Generate more excuses? (y/n): " << RESET;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Convert to lowercase
    for (size_t i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    
    return (input == "y" || input == "yes");
}

/**
 * Print goodbye message
 */
void printGoodbye() {
    cout << LIGHT_BLUE << R"(
    ============================= 
    |         Thank You!        |  
    ============================= 
    )" << RESET << endl;
    cout << LIGHT_CYAN << BOLD << "Remember:" << RESET << endl;
    cout << LIGHT_YELLOW << "Don't overuse these excuses. " << RESET << endl;
    cout << LIGHT_YELLOW << "Actually do your homework sometimes!" << RESET << endl;
    cout << LIGHT_MAGENTA << "Every student needs a good excuse occasionally." << RESET << endl;
    cout << LIGHT_GREEN << "But ultimately, doing the work is the best strategy!" << RESET << endl;
    
    // Print footer art
    cout << LIGHT_BLUE << R"(
    =================================================
    |    Keep calm and may the excuse be with you!  |  
    =================================================
    )" << RESET;
}

/**
 * Main function - Program entry point
 */
int main() {
    // Seed random number generator once at program start
    srand(static_cast<unsigned int>(time(0)));
    
    // 20+ CREATIVE, TECH-THEMED EXCUSES
    // Each one is unique, funny, and relatable
    vector<string> excuses = {
        // Power/Technical issues
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly... right in the middle of the last sentence!",
        "{name} had a power outage that wiped out all the work. The lights came back, but the file didn't.",
        "{name}'s system started updating automatically - because apparently 3 AM is the perfect time for Windows to restart!",
        
        // Internet issues
        "{name} tried finishing the homework, but the internet decided to take a vacation at the worst possible moment.",
        "{name} had to reset the router which took way longer than expected. 47 minutes of staring at blinking lights!",
        
        // File/Software issues
        "{name} was ready to submit the assignment when the file mysteriously vanished into the digital void.",
        "{name} accidentally deleted the assignment while trying to organize files... productivity strikes again!",
        "{name} was working on the document when the laptop decided to freeze and show the spinning wheel of doom.",
        "{name} saved the file to a folder that got accidentally archived into the shadow realm of lost directories.",
        "{name} was uploading the assignment when the browser crashed - because nothing says 'reliability' like Chrome!",
        "{name} accidentally saved over the homework with a different file. The tragedy of Ctrl+S on the wrong document!",
        
        // Creative tech excuses
        "{name} found out the file was corrupted - turns out cosmic rays can corrupt files. Science!",
        "{name} had a brilliant idea at 2 AM, opened the laptop, and the document was blank. The ghost of homework past strikes!",
        "{name} was doing research when the laptop made a strange noise and shut down... suspiciously like homework avoidance!",
        "{name} accidentally submitted the wrong file - the one with the shopping list instead of the assignment.",
        
        // Family/Pet distractions
        "{name}'s older sibling needed the laptop for an emergency thesis crisis. Family comes first, right?",
        "{name} was in the middle of a perfect paragraph when the cat walked across the keyboard and deleted everything.",
        
        // Procrastination excuses
        "{name} was debugging code for 6 straight hours and completely forgot about the assignment deadline.",
        "{name}'s code was so broken, fixing it took all night. The irony isn't lost on anyone!",
        "{name} had 47 browser tabs open, got distracted by a documentary, and time just... vanished.",
        "{name} was about to start working when the great pizza debate of 2024 happened and had to be resolved."
    };
    
    // Welcome header
    printHeader();
    printSeparator("~", 50);
    
    // Main program loop
    do {
        // Clear screen for cleaner look
        clearScreen();
        
        // Show welcome again for subsequent runs
        cout << LIGHT_BLUE << "================================================\n|    ULTIMATE HOMEWORK EXCUSE GENERATOR!       |\n================================================" << RESET << endl;
        
        // Track used excuses to avoid repetition
        vector<int> usedIndices;
        
        // Get user input
        string userName = getUserName();
        
        // Get excuse count
        int excuseCount = getExcuseCount();
        
        // Show what's coming
        cout << endl;
        cout << LIGHT_GREEN << "Generating " << excuseCount << " EXCUSES for " << userName << RESET << endl;
        
        // Generate and display excuses
        for (int i = 0; i < excuseCount; i++) {
            string excuse = generateUniqueExcuse(userName, excuses, usedIndices);
            printExcuseDramatic(excuse, i + 1, excuseCount);
            
            // Small delay for dramatic effect between excuses
            if (i < excuseCount - 1) {
                cout << LIGHT_CYAN << "  (Preparing next excuse...)" << RESET << endl;
            }
        }
        
        // Ask to run again
        cout << endl;
        
    } while (runAgain());
    
    // Goodbye
    printGoodbye();
    
    return 0;
}