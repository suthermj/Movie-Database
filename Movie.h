#include <iostream>
/* 
 * File:   Movie.h
 * Author: budowja
 * Copyright budowja 2019
 * Created on April 14, 2019, 11:07 PM
 */

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie {
    friend std::istream& operator>>(std::istream& is, Movie& m);
    friend std::ostream& operator<<(std::ostream&, const Movie& m);

public:
    Movie(const std::string& title = "",
            const int year = 0, const std::string& genres = "",
            const int imdbId = 0, const float rating = 0.0,
            const int numRaters = 0, const std::string& img_src = "",
            const std::string& description = "",
            const std::string& director = "",
            const bool isDelete = 0, const bool isPending = 0);

    virtual ~Movie();

    std::string getCol(const std::string& colName) const;

    void printAsHtml(std::ostream& os) const;

private:
    std::string title;

    int year;

    std::string genres;

    int imdbId;

    float rating;

    int numRaters;
    
    std::string img_src;
    
    std::string description;
    
    std::string director;
    
    bool isDelete;
    
    bool isPending;
};

std::string to_string(const Movie& m);

#endif /* MOVIE_H */
