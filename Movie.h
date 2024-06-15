#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <iostream>
#include <string>

class Movie {
private:
    static size_t number_of_movie_objects;
    std::string m_movie_name;
    std::string m_movie_rating;
    size_t m_number_of_times_watched;
public:
    Movie(std::string name, std::string rating, size_t watch_count);
    Movie(const Movie& source);
    const void display();
    size_t get_number_of_movie_objects() const;
    std::string get_movie_name() const;
    std::string get_movie_rating() const;
    size_t get_number_of_times_watched() const;
    void set_movie_name(std::string new_movie_title);
    void set_movie_rating(std::string new_movie_rating);
    void set_number_of_times_watched(size_t new_watch_count);
    void increment_number_of_times_watched();
    void decrement_number_of_times_watched();
    ~Movie();
};
#endif // !_MOVIE_H_
