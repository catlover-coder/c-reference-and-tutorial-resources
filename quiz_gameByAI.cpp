#include <iostream>
#include <vector>
#include <string>
#include <limits>

// Struct to represent a single question
struct Question {
    std::string questionText;
    std::vector<std::string> options;
    int correctOption; // 1, 2, 3, or 4
};

// Struct to represent a complete Quiz
struct Quiz {
    std::string title;
    std::vector<Question> questions;
};

// Helper function to safely clear the input buffer
void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to create a new quiz
void createQuiz(std::vector<Quiz>& quizList) {
    Quiz newQuiz;
    
    std::cout << "\n--- CREATE A NEW QUIZ ---\n";
    std::cout << "Enter the title of your quiz: ";
    std::getline(std::cin, newQuiz.title);

    char addMore = 'y';
    int questionNumber = 1;

    while (addMore == 'y' || addMore == 'Y') {
        Question q;
        std::cout << "\nQuestion " << questionNumber << ": ";
        std::getline(std::cin, q.questionText);

        // Get 4 options
        for (int i = 1; i <= 4; ++i) {
            std::string option;
            std::cout << "  Option " << i << ": ";
            std::getline(std::cin, option);
            q.options.push_back(option);
        }

        // Get the correct answer index
        while (true) {
            std::cout << "Which option is correct? (1-4): ";
            if (std::cin >> q.correctOption && q.correctOption >= 1 && q.correctOption <= 4) {
                clearBuffer();
                break;
            } else {
                std::cout << "Invalid choice! Please enter a number between 1 and 4.\n";
                clearBuffer();
            }
        }

        newQuiz.questions.push_back(q);
        questionNumber++;

        std::cout << "Do you want to add another question to this quiz? (y/n): ";
        std::cin >> addMore;
        clearBuffer();
    }

    quizList.push_back(newQuiz);
    std::cout << "\nSuccess! Quiz \"" << newQuiz.title << "\" has been created.\n";
}

// Function to play an existing quiz
void playQuiz(const std::vector<Quiz>& quizList) {
    if (quizList.empty()) {
        std::cout << "\nNo quizzes available to play yet! Create one first.\n";
        return;
    }

    std::cout << "\n--- CHOOSE A QUIZ TO PLAY ---\n";
    for (size_t i = 0; i < quizList.size(); ++i) {
        std::cout << i + 1 << ". " << quizList[i].title << " (" << quizList[i].questions.size() << " questions)\n";
    }

    int choice;
    std::cout << "Enter the number of the quiz: ";
    if (!(std::cin >> choice) || choice < 1 || choice > static_cast<int>(quizList.size())) {
        std::cout << "Invalid quiz selection.\n";
        clearBuffer();
        return;
    }
    clearBuffer();

    const Quiz& selectedQuiz = quizList[choice - 1];
    int score = 0;

    std::cout << "\nStarting Quiz: " << selectedQuiz.title << "\n";
    std::cout << "=================================\n";

    for (size_t i = 0; i < selectedQuiz.questions.size(); ++i) {
        const Question& q = selectedQuiz.questions[i];
        std::cout << "\nQ" << i + 1 << ": " << q.questionText << "\n";
        
        for (int j = 0; j < 4; ++j) {
            std::cout << "  " << j + 1 << ") " << q.options[j] << "\n";
        }

        int playerAnswer;
        while (true) {
            std::cout << "Your answer (1-4): ";
            if (std::cin >> playerAnswer && playerAnswer >= 1 && playerAnswer <= 4) {
                clearBuffer();
                break;
            } else {
                std::cout << "Please select 1, 2, 3, or 4.\n";
                clearBuffer();
            }
        }

        if (playerAnswer == q.correctOption) {
            std::cout << "Correct!\n";
            score++;
        } else {
            std::cout << "Wrong! The correct answer was option " << q.correctOption << ".\n";
        }
    }

    std::cout << "\n=================================\n";
    std::cout << "Quiz Finished! Your Score: " << score << "/" << selectedQuiz.questions.size() << "\n";
}

// Function to display the count and list of created quizzes
void checkQuizzesCount(const std::vector<Quiz>& quizList) {
    std::cout << "\n--- MY QUIZZES STATS ---\n";
    std::cout << "Total Quizzes Created: " << quizList.size() << "\n";
    
    if (!quizList.empty()) {
        std::cout << "\nList of Quizzes:\n";
        for (size_t i = 0; i < quizList.size(); ++i) {
            std::cout << "- " << quizList[i].title << " (" << quizList[i].questions.size() << " Qs)\n";
        }
    }
}

int main() {
    std::vector<Quiz> myQuizzes;
    int choice = 0;

    std::cout << "Welcome to the Custom Quiz Maker!\n";

    while (choice != 4) {
        std::cout << "\n=========================\n";
        std::cout << "       MAIN MENU         \n";
        std::cout << "=========================\n";
        std::cout << "1. Create a New Quiz\n";
        std::cout << "2. Play a Quiz\n";
        std::cout << "3. Check My Quiz Count\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Please enter a valid number.\n";
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                createQuiz(myQuizzes);
                break;
            case 2:
                playQuiz(myQuizzes);
                break;
            case 3:
                checkQuizzesCount(myQuizzes);
                break;
            case 4:
                std::cout << "\nThanks for playing! Goodbye.\n";
                break;
            default:
                std::cout << "Invalid choice! Please choose an option from the menu.\n";
        }
    }

    return 0;
}
