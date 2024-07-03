#ifndef _NODE_N_
#define _NODE_N_
#include <iostream>
#include <string>
#include "Movie.h"

class Node {
private:
    Node* m_next {nullptr};
    Movie m_data;
public:
    Node();
    Node(std::string movie_title, std::string movie_rating, size_t movie_watch_count);
    Node* get_next_node();
    std::string get_node_data_movie_title();
    std::string get_node_data_movie_rating();
    size_t get_node_data_movie_watch_count();
    void set_node_data_movie_title(std::string new_movie_title);
    void set_node_data_movie_rating(std::string new_movie_rating);
    void set_node_data_movie_watch_count(size_t new_movie_watch_count);
    void set_next_node(Node* next_node);
    void display_movie_data();
    void increment_movie_watch_count();
    void decrement_movie_watch_count();
    ~Node();
};

#endif // !_NODE_N_
