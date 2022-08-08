#ifndef _MOVIES_CLASS_H_
#define _MOVIES_CLASS_H_
#include <string>
#include <vector>
#include "Movie.h"


class Movies {
    std::vector<Movie> movies;
    // std::string movie_name;
    // std::string movie_rating;
    // int movie_watch_count;
public:
    /* Both 'Constructor' and 'Destructor' will be automatically addressed by compiler when they do nothing, like the example below.
       I'm declaring them here for the sake of example */
    // Constructor
    Movies();
    // Destructor
    ~Movies();

    bool add_movie(std::string name, std::string rating, int watch_count);
    bool increment_watched(std::string name);
    void display();

};

#endif // _MOVIES_CLASS_H_