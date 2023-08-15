// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <algorithm>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
    std::cout<<song<<std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    std::cout<<std::endl;
    for (const auto &song:playlist){
        std::cout<<song<<std::endl;
    }

    std::cout<<"\nCurrent song:"<<"\n"<<current_song<<std::endl;
}

void clear_cin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    // Your program logic goes here
    char user_input;

    display_playlist(playlist, *current_song);
    display_menu();
    std::cin>>user_input;
    user_input = std::toupper(user_input);
    while (user_input != 'Q') {

        switch (user_input) {
        case 'F':
            std::cout<<"Playing first song"<<std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
            break;
        case 'N':
            std::cout<<"Playing next song"<<std::endl;
            std::advance(current_song, 1); // it++
            if (current_song == playlist.end()) {
                current_song = playlist.begin();
            }
            play_current_song(*current_song);
            break;
        case 'P':
            std::cout<<"Playing previous song"<<std::endl;
            if (current_song == playlist.begin()) {
                current_song = playlist.end();
            }
            std::advance(current_song, -1);
            play_current_song(*current_song);
            break;
        case 'A':
            std::cout<<"Adding and playing new song"<<std::endl;
            {
                std::string song_name, artist;
                int rate;
                clear_cin();
                std::cout<<"Enter song name:"<<std::endl;
                std::getline(std::cin, song_name);
                std::cout<<"Enter song artist:"<<std::endl;
                std::getline(std::cin, artist);
                std::cout<<"Enter song rate:"<<std::endl;
                std::cin>>rate;
                playlist.emplace_back(song_name, artist, rate);
            }
            // std::advance(current_song, playlist.size()-1);
            current_song = --playlist.end();
            play_current_song(*current_song);
            break;
        case 'L':
            display_playlist(playlist, *current_song);
            break;
        default:
            std::cout<<"Illegal choice, try again..."<<std::endl;
            break;
        }

        display_menu();
        std::cin>>user_input;
        user_input = std::toupper(user_input);
    }

    return 0;
}