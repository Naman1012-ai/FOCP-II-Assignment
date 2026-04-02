/**
 * roast_generator_v2.cpp
 * 
 * ENHANCED VERSION - More Creative & Colorful Roast Generator
 * 
 * Features:
 * - 20+ creative, nerdy, tech-themed roast templates
 * - Colorful terminal output using ANSI escape codes
 * - Beautiful ASCII art headers
 * - Input validation
 * - Multiple roasts support
 * 
 * Author: Roast Generator Team
 * Version: 2.0 - Ultra Edition
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <cctype>

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
const string BG_BLACK = "\033[40m";
const string BG_RED = "\033[41m";
const string BG_YELLOW = "\033[43m";
const string BG_CYAN = "\033[46m";

/**
 * Clear the terminal screen
 */
void clearScreen() {
    // Try different clear methods for compatibility
    cout << "\033[2J\033[1;1H";  // ANSI escape to clear and go to top
}

/**
 * Print an ASCII art header
 */
void printHeader() {
    cout << RESET << endl;
    cout << LIGHT_YELLOW << "Welcome to the Ultimate Roast Generator 3000!" << RESET << endl;
    cout << LIGHT_CYAN << "Get ready for some DELICIOUSLY humiliating roasts!" << RESET << endl;
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
 * Print a roast with dramatic presentation
 */
void printRoastDramatic(const string& roast, int currentNum, int total) {
    // Roast number display
    cout << endl;
    cout << LIGHT_BLUE << "ROAST #" << currentNum << " OF " << total <<  RESET << endl;
    printSeparator("=", 50);
    
    // The roast with dramatic flair
    cout << LIGHT_YELLOW << BOLD << "YOUR ROAST:" << RESET << " " << LIGHT_WHITE << roast << RESET << endl;
    
    printSeparator("-", 50);
}

/**
 * Get user's name with validation
 */
string getUserName() {
    string name;
    
    while (true) {
        cout << endl;
        cout << LIGHT_CYAN << "Enter your name, victim: " << RESET;
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
        
        // Check for valid characters - ONLY letters allowed (no numbers)
        bool valid = true;
        for (size_t i = 0; i < name.length(); i++) {
            if (!isalpha(name[i])) {
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
 * Get number of roasts to generate
 */
int getRoastCount() {
    string input;
    int count = 0;
    
    while (true) {
        cout << LIGHT_MAGENTA << "How many roasts do you want? (1-5): " << RESET;
        cin >> input;
        
        stringstream ss(input);
        if (ss >> count && count >= 1 && count <= 5) {
            return count;
        } else {
            cout << LIGHT_RED << "Please enter a number between 1 and 5!" << RESET << endl;
        }
    }
}

/**
 * Generate a random roast
 */
string generateRoast(const string& name) {
    // 20+ CREATIVE, NERDY, TECH-THEMED ROASTS
    // Each one is unique, funny, and light-hearted
    vector<string> roasts = {
        // Code quality roasts
        "{name}'s code is so deprecated, even the warranty has expired.",
        "When {name} commits code, even the compiler sighs in disappointment.",
        "{name}'s code has more debt than a credit card company.",
        
        // Stack Overflow roasts
        "{name}'s career progression: Ctrl+C -> Ctrl+V -> Stack Overflow -> Repeat.",
        "{name}'s Git history: 'fixed it' -> 'it broke' -> 'try this' -> 'oops'.",
        "{name}'s IDE has more red squiggles than a bad novel.",
        
        // Performance roasts
        "{name}'s code is so slow, it compiles overnight for a snack break.",
        "If {name}'s code were a song, it'd be the extended remix of nothingness.",
        "{name} writes code so inefficient, even the turtles are taking notes.",
        
        // Productivity roasts
        "{name}'s todo list: 'fix bug' -> 'create bug' -> 'deny everything'.",
        "{name} procrastinates so hard, they're practically time travelers.",
        "When {name} says 'I'll do it in 5 minutes', the universe laughs.",
        
        // Funny insults
        "{name}'s code has more holes than Swiss cheese during a mouse convention.",
        "If ignorance was brilliance, {name} would've won the Nobel by now.",
        "The only thing standing between {name} and success is better judgment.",
        
        // Final boss roasts
        "When {name} presents their code, even the docs beg for mercy.",
        "If {name} were a variable, they'd be undefined. Always.",
        "The bug that keeps on giving: It's called {name}'s entire codebase."
    };
    
    // Generate random index
    int randomIndex = rand() % roasts.size();
    
    // Get the selected roast template
    string roast = roasts[randomIndex];
    
    // Replace {name} placeholder with actual name
    size_t position = roast.find("{name}");
    while (position != string::npos) {
        roast.replace(position, 6, name);
        position = roast.find("{name}", position + name.length());
    }
    
    return roast;
}

/**
 * Ask if user wants to run again
 */
bool runAgain() {
    string input;
    
    cout << LIGHT_CYAN << "Generate more roasts? (y/n): " << RESET;
    cin >> input;
    
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
    cout << LIGHT_YELLOW << "Don't take the roasts personally. " << RESET << endl;
    cout << LIGHT_YELLOW << "They're all in good fun! Laugh it off!" << RESET << endl;
    cout << LIGHT_MAGENTA << "Every great coder was once a terrible one." << RESET << endl;
    cout << LIGHT_GREEN << "Keep coding, keep failing, keep growing!" << RESET << endl;
    
    // Print footer art
    cout << LIGHT_BLUE << R"(
    =================================================
    |    Keep calm and may the roast be with you!   |  
    =================================================
    )" << RESET;
}

/**
 * Main function - Program entry point
 */
int main() {
    // Seed random number generator once at program start
    srand(static_cast<unsigned int>(time(0)));
    
    // Welcome header
    printHeader();
    printSeparator("~", 50);
    
    // Main program loop
    do {
        // Clear screen for cleaner look
        clearScreen();
        
        // Show welcome again for subsequent runs
        cout << LIGHT_BLUE << "================================================\n|       ULTIMATE ROAST GENERATOR 3000!         |\n================================================" << RESET << endl;
        
        // Get user input
        string userName = getUserName();
        
        // Get roast count
        int roastCount = getRoastCount();
        
        // Show what's coming
        cout << endl;
        cout << LIGHT_GREEN << "Generating " << roastCount << " ROASTS for " << userName << RESET << endl;
        
        // Generate and display roasts
        for (int i = 0; i < roastCount; i++) {
            string roast = generateRoast(userName);
            printRoastDramatic(roast, i + 1, roastCount);
            
            // Small delay for dramatic effect between roasts
            if (i < roastCount - 1) {
                cout << LIGHT_CYAN << "  (Preparing next roast...)" << RESET << endl;
            }
        }
        
        // Ask to run again
        cout << endl;
        
    } while (runAgain());
    
    // Goodbye
    printGoodbye();
    
    return 0;
}