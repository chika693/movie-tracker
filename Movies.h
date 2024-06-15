#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <vector>

class Movies {
private:
    std::vector<Movie> m_movie_container;
    size_t m_list_size {};
public:
    Movies();
    Movies(const Movies& source);
/*     Movies(Movies&& source); */
    // No need for a move constructor since I am not working with raw pointers.
    size_t* begin();    // made this because enhanced for loop said it needed it
    size_t* end();      // same here, referenced this reddit thread: https://www.reddit.com/r/learnprogramming/comments/pdyukg/range_loop_on_array_not_working_within_a_function/
    void add(std::string movie_name, std::string movie_rating, size_t watched_count);
    void display() const;
    size_t get_size();
    bool check_if_movie_title_in_tracker(std::string movie_title);
    void change_movie_watch_count(std::string movie_title, size_t new_movie_watch_count);
    void increment_movie_watch_count(std::string movie_title);
    void decrement_movie_watch_count(std::string movie_title);
    void remove_movie_from_container(std::string movie_title);
    void change_movie_title(std::string movie_title, std::string new_title);
    void change_movie_rating(std::string movie_title, std::string new_movie_rating);
    std::string get_specific_movie_rating(std::string movie_title);
    ~Movies();
};

#endif // !_MOVIES_H_
