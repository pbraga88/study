#include <iostream>
#include <string>
#include "Movie.h"

Movie::Movie(std::string name, std::string rate, int watch_counter) : 
             movie_name(name), movie_rate(rate), movie_watch_counter(watch_counter) {
}
Movie::Movie(const Movie &source) : 
             Movie(source.movie_name, source.movie_rate, source.movie_watch_counter) {    
}

std::string Movie::get_movie_name() const{
    return movie_name;
}

std::string Movie::get_movie_rate() const{
    return movie_rate;
}
int Movie::get_watch_counter() const{
    return movie_watch_counter;
}

void Movie::increment_watch_counter() {
    movie_watch_counter += 1;
}