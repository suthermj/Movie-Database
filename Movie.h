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
    Movie(int movieID = 0, const std::string& title = "",
            const int year = 0, const std::string& genres = "",
            const int imdbId = 0, const float rating = 0.0,
            const int numRaters = 0);

    virtual ~Movie();

    int getID() const {
        return movieID;
    }

    std::string getCol(const std::string& colName) const;

    void printAsHtml(std::ostream& os) const;

private:
    int movieID = -1;

    std::string title;

    int year;

    std::string genres;

    int imdbId;

    float rating;

    int numRaters;
};

std::string to_string(const Movie& m);

#endif /* MOVIE_H */

