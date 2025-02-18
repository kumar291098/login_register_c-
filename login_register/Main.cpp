#include <iostream>
#include <fstream>
#include <string>

struct User {
    std::string username;
    std::string password;
};

void registerUser() {
    User newUser;
    std::cout << "Enter a username: ";
    std::cin >> newUser.username;

    std::ifstream readFile("users.txt");
    std::string username, password;
    bool usernameExists = false;

    while (readFile >> username >> password) {
        if (username == newUser.username) {
            usernameExists = true;
            break;
        }
    }
    readFile.close();

    if (usernameExists) {
        std::cout << "Username already exists. Please choose another username.\n";
        return;
    }

    std::cout << "Enter a password: ";
    std::cin >> newUser.password;

    std::ofstream writeFile("users.txt", std::ios::app);
    writeFile << newUser.username << " " << newUser.password << "\n";
    writeFile.close();

    std::cout << "Registration successful!\n";
}

void loginUser() {
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    std::ifstream readFile("users.txt");
    std::string storedUsername, storedPassword;
    bool loginSuccess = false;

    while (readFile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            loginSuccess = true;
            break;
        }
    }
    readFile.close();

    if (loginSuccess) {
        std::cout << "Login successful! Welcome, " << username << ".\n";
    }
    else {
        std::cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;
    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            std::cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}