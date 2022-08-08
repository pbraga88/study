#ifndef _MOVIE_CLASS_H_
#define _MOVIE_CLASS_H_
#include <iostream>
#include <string>

class Movie {
    std::string movie_name;
    std::string movie_rate;
    int movie_watch_counter;
public:
    /* Constructor */
    Movie(std::string name, std::string rate, int watch_counter);
    /* Copy constructor */
    Movie(const Movie &source);

    std::string get_movie_name() const;
    std::string get_movie_rate() const;
    int get_watch_counter () const;
    void increment_watch_counter();
};
#endif // _MOVIE_CLASS_H_