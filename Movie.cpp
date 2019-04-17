#ifndef MOVIE_CPP
#define MOVIE_CPP

/** This file contains the implementation for various methods in the 
 * movie class.
 * 
 * Copyright (C) 2019 raodm@miamioh.edu
 * Copyright(C) <Abby Danger> [2019]
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Movie.h"

// The default (and only) constructor for this class.
Movie::Movie(const std::string& title, const int year, 
        const std::string& genres, const int imdbId, const float rating, const int numRaters,
        const std::string& img_src, const std::string& description, const std::string& director,
        const int isDelete, const int isPending) :
    title(title), year(year), genres(genres), imdbId(imdbId), 
        rating(rating), numRaters(numRaters), img_src(img_src),
        description(description),director(director),isDelete(isDelete),
        isPending(isPending){
}

 //The destructor
Movie::~Movie() {
    // Currently, the destructor does not have any special tasks to do.
}

// Stream-extraction operator.
std::istream& operator>>(std::istream& is, Movie& m) {
    // Read the values from an entry in the stream/file in the correct order.
    is >> std::quoted(m.title) >> m.year >> std::quoted(m.genres)
       >> m.imdbId  >> m.rating >> m.numRaters >> std::quoted(m.img_src) >> std::quoted(m.description)
            >> std::quoted(m.director) >> m.isDelete >> m.isPending;
    // Return the stream as per the API requirement.
    return is;
}

// The stream insertion operator.
std::ostream& operator<<(std::ostream& os, const Movie& m) {
    // Read the values from an entry in the stream/file in the correct order.
    os << std::quoted(m.title) << " " << m.year   << " " 
       << std::quoted(m.genres) << " " << m.imdbId << " " << m.rating << " "
       << m.numRaters << " " << std::quoted(m.img_src) << " " 
       << std::quoted(m.description) << " " << std::quoted(m.director)
       << " " << m.isDelete << " " << m.isPending;
    // Return the stream as per the API requirement.
    return os;    
}

// A simple to-string method.
std::string to_string(const Movie& m) {
    std::ostringstream os;
    os << m;
    return os.str();
}

// Return value for a given column
std::string
Movie::getCol(const std::string& col) const {
     if (col == "title") {
        return title;
    } else if (col == "year") {
        return std::to_string(year);
    } else if (col == "genres") {
        return genres;
    } else if (col == "imdbid") {
        return std::to_string(imdbId);
    } else if (col == "rating") {
        return std::to_string(rating);
    } else if (col == "raters") {
        return std::to_string(numRaters);
    }
    else if(col == "img_src"){
        return img_src;
    }
    else if(col == "description"){
        return description;
    }
    else if(col == "director"){
        return director;
    }
    else if(col == "isDelete"){
        return std::to_string(isDelete);
    }
    else if(col == "isPending"){
        return std::to_string(isPending);
    }
    // Unknown column name.
    return "";
}

// Generates data in HTML format
void 
Movie::printAsHtml(std::ostream& os) const {
    os << "<div class='movie'>\n";
    os << "  <p><span class='title'>" << title << "</span> (" << year << ").";
    os << "  Genres: "  << genres << "</p>\n";
    os << "  <p>Rating: "  << rating << " (from " << numRaters 
       << " ratings).";
    os << " Link to IMDB: <a href='https://www.imdb.com/title/tt"
       << std::setfill('0') << std::setw(7)  // Ensure 7-digit numbers
       << imdbId << "' target='other'>" << imdbId << "</a></p>\n";
    os << "<p>" << img_src << "</p>\n";
    os << "<p>" << description << "</p>\n";
    os << "<p>" << director << "</p>\n";
    os << "<p>" << isDelete << "</p>\n";
    os << "<p>" << isPending << "</p>\n";
    os << "</div>\n";
}

#endif

