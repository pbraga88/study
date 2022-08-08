#include <iostream>
#include "Movies.h"

Movies::Movies() {
}
Movies::~Movies() {
}

bool Movies::add_movie(std::string name, std::string rating, int watch_count) {
    for (auto &mv: movies) {
        if (mv.get_movie_name() == name) {
            return false;// movie already exists
        }
    }
    Movie new_movie(name, rating, watch_count);
    movies.push_back(new_movie);
    return true;
}

bool Movies::increment_watched(std::string name) {
    for (auto &mv: movies) {
        if (mv.get_movie_name() == name) {
            mv.increment_watch_counter();
            return true;
        }
    }
    return false; // movie not found
}

void Movies::display() {
    if(movies.empty()) {
        std::cout<<"Sorry, no movies to display\n"<<std::endl;
    }
    else {
        std::cout << "\n===================================" << std::endl;
        for(auto &mv: movies) {
            std::cout<<mv.get_movie_name()<<", "<<mv.get_movie_rate()<<", "<<
                    mv.get_watch_counter()<<std::endl;
        }
        std::cout << "\n===================================" << std::endl;
    }
}