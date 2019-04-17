/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jack
 * Copyright Jack Budow 2019
 * Created on April 3, 2019, 11:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printResultInHtml(std::string result) {
    std::cout << "Content-type: text/html\r\n\r\n";
    std::cout << "<!DOCTYPE html>\n<html>\n<body>\n";
    std::cout << "<p>" << result << "</p>\n";
    std::cout << "</body>\n</html>\n";
}

void createAccountSave(std::string const caUserV, const std::string caPassV,
    const std::string caEmailV) {
    std::ofstream usersFile("Users.txt",
            std::ios_base::out | std::ios_base::app);
    usersFile << caUserV << " " << caPassV << " " << caEmailV << std::endl;
    usersFile.close();
    printResultInHtml("Success, account created");
}

void createAccountValidate(const std::string caUserV, const std::string caPassV,
    const std::string caEmailV) {
    std::string line;
    bool pass = true;
    std::ifstream usersFile("Users.txt");
    while (!usersFile.eof()) {
        std::getline(usersFile, line);
        if (line.find(caUserV) != std::string::npos) {
            printResultInHtml("Failure, account already exists");
            pass = false;
            break;
        }
        if (line.find(caEmailV) != std::string::npos) {
            printResultInHtml("Failure, account already exists");
            pass = false;
            break;
        }
    }
    usersFile.close();
    if (pass)
        createAccountSave(caUserV, caPassV, caEmailV);
}

void createAccountProcess(std::string postData) {
    size_t posUserV = postData.find("=");
    size_t posPassV = postData.find("=", posUserV + 1);
    size_t posEmailV = postData.find("=", posPassV + 1);
    const std::string caUserV = 
    postData.substr(posUserV + 1, posPassV - 5 - posUserV);
    const std::string caPassV = 
    postData.substr(posPassV + 1, posEmailV - 5 - posPassV);
    const std::string caEmailV = postData.substr(posEmailV + 1);
    createAccountValidate(caUserV, caPassV, caEmailV);
}

void loginValidate(const std::string loginUserV, const std::string loginPassV) {
    std::string line;
    bool pass = false;
    std::ifstream usersFile("Users.txt");
    while (!usersFile.eof()) {
        std::getline(usersFile, line);
        if (line.find(loginUserV) != std::string::npos && 
                line.find(loginPassV) != std::string::npos) {
            std::string str = "Success! Welcome back ";
            str.append(loginUserV);
            printResultInHtml(str);
            pass = true;
            break;
        }
    }
    usersFile.close();
    if (!pass)
        printResultInHtml("Failure, credentials were not valid");
}

void loginProcess(std::string postData) {
    size_t posUserV = postData.find("=");
    size_t posPassV = postData.find("=", posUserV + 1);
    const std::string loginUserV = 
    postData.substr(posUserV + 1, posPassV - 8 - posUserV);
    const std::string loginPassV = postData.substr(posPassV + 1);
    loginValidate(loginUserV, loginPassV);
}

int main() {
    const char QS[] = "QUERY_STRING";

    std::string queryStr = getenv(QS) != NULL ? getenv(QS) : "";
    std::string postData;
    std::getline(std::cin, postData);
    // Echo/print the inputs this program got in HTML format
    
    if (queryStr == "CA")
        createAccountProcess(postData);
    if (queryStr == "Login")
        loginProcess(postData);
    return 0;
}
