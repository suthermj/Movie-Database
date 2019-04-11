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
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
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
    std::string qstring; 
    mysqlpp::Connection myDB("cse278", "192.155.95.213", "cse278","zLATBsMFQhwXdNbr");
    mysqlpp::Query query = myDB.query();
    qstring = "INSERT INTO loginDatabase(user,pass,email) VALUES (%0q,%1q,%2q);";
    query << qstring;
    try{
    query.parse();
    mysqlpp::StoreQueryResult result = query.store(caUserV,caPassV,caEmailV);
    printResultInHtml("Success, account created");
    }
    catch(mysqlpp::BadQuery e){
        
    }
}

void createAccountValidate(const std::string caUserV, const std::string caPassV,
    const std::string caEmailV) {
    std::string qstring;
    bool pass = true;
    mysqlpp::Connection myDB("cse278", "192.155.95.213", "cse278","zLATBsMFQhwXdNbr");
    mysqlpp::Query query = myDB.query();
    qstring = "SELECT user,email FROM loginDatabase WHERE user = %0q OR email = %1q;";
    query << qstring;
    try{
    query.parse();
    mysqlpp::StoreQueryResult result = query.store(caUserV,caEmailV);
    
    if(result.size() > 0){
        pass = false;
    }
    if (pass)
        createAccountSave(caUserV, caPassV, caEmailV);
    }
    catch(mysqlpp::BadQuery e){
        
    }
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
    std::string qstring;
    mysqlpp::Connection myDB("cse278", "192.155.95.213", "cse278","zLATBsMFQhwXdNbr");
    mysqlpp::Query query = myDB.query();
    qstring = "SELECT user,pass FROM loginDatabase WHERE user=%0q AND pass=%1q;";
    query << qstring;
    try{
        query.parse();
        mysqlpp::StoreQueryResult result = query.store(loginUserV,loginPassV);
        if(result.size() != 0){
            std::string str = "Success! Welcome back ";
            str.append(loginUserV);
            printResultInHtml(str);
        }
        else{
            printResultInHtml("Failure, credentials were not valid");
        }
    }
    catch(mysqlpp::BadQuery e){
        
    }
    
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
