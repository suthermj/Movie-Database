
/* 
 * File:   index.cpp
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
#include "Movie.h"

const std::string HTMLHeader = 
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE html>\n"
    "<html>\n"
    "<head>\n"
    "<link type='text/css' rel='stylesheet' href='index.css'/>\n"
    "</head>\n"
    "<body>\n";

const std::string HTMLFooter = "</body>\n</html>";

void getMovies(mysqlpp::StoreQueryResult result) { 
    for (const auto& row : result) {
        Movie movie(row[0].c_str() , row[1] , row[2].c_str() , row[3] 
        , row[4] , row[5], row[6].c_str(), row[7].c_str(), row[8].c_str(),
                row[9], row[10]);
        movie.printAsHtml(std::cout);
    }
}

mysqlpp::StoreQueryResult connectToDBSearch(std::string search) {
    mysqlpp::Connection myDB("cse278", "192.155.95.213", "cse278",
            "zLATBsMFQhwXdNbr");
    mysqlpp::Query searchQuery = myDB.query();
    searchQuery << "SELECT * FROM movie WHERE title LIKE '%%%0%%'";
    searchQuery.parse();
    mysqlpp::StoreQueryResult result = searchQuery.store(search);
    return result;
}

void processSearch(std::string postData) {
    size_t s1 = postData.find('=');
    std::string search = postData.substr(s1 + 1);
    mysqlpp::StoreQueryResult result = connectToDBSearch(search);
    std::cout << HTMLHeader;
    getMovies(result);
    std::cout << HTMLFooter;
}

mysqlpp::StoreQueryResult connectToDB() {
    mysqlpp::Connection myDB("cse278", "192.155.95.213", "cse278",
            "zLATBsMFQhwXdNbr");
    mysqlpp::Query query = myDB.query();
    query << "SELECT * FROM movie";
    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    return result;
}

void loadMovies() {
    mysqlpp::StoreQueryResult result = connectToDB();
    /* Prints HTML including heading, movie data, and footer*/
    std::cout << HTMLHeader;
    getMovies(result);
    std::cout << HTMLFooter;
}

int main() {
    const char QS[] = "QUERY_STRING";
    std::string queryStr = getenv(QS) != NULL ? getenv(QS) : "";
    if (queryStr == "load") {
        loadMovies();
    } else {
        std::string postData;
        std::getline(std::cin, postData);
        if (queryStr == "search") {
            processSearch(postData);
        }
    }
    return 0;
}

