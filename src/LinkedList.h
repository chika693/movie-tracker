#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Node.h"
// this will be the one creating the new nodes and deleting the node in the destructor.

class LinkedList {
private:
    Node* m_list_head;
public:
    LinkedList();
    LinkedList(std::string movie_title, std::string movie_rating, size_t movie_watch_count);
    LinkedList(const LinkedList& source);
    size_t get_size(); 

    void append(std::string movie_title, std::string movie_rating, size_t movie_watch_count);
    void remove_movie_from_container(std::string movie_title);
    void display();
    void change_movie_title(std::string movie_title, std::string new_title);
    void change_movie_rating(std::string movie_title, std::string new_movie_rating);
    void change_movie_watch_count(std::string movie_title, size_t new_watch_count);
    void increment_movie_watch_count(std::string movie_title);
    void decrement_movie_watch_count(std::string movie_title);
    
    
    std::string get_specific_movie_rating(std::string movie_title);
    bool check_if_movie_title_in_tracker(std::string movie_title);

    ~LinkedList();
};

#endif // !_LINKEDLIST_H_
