#include "Node.h"

Node::Node()
: m_data{}, m_next{nullptr}
{ }

Node::Node(std::string movie_title, std::string movie_rating, size_t movie_watch_count)
: m_data{movie_title, movie_rating, movie_watch_count}, m_next{nullptr}
{ }

Node* Node::get_next_node()
{
    return m_next;
}

std::string Node::get_node_data_movie_title()
{
    return m_data.get_movie_name();
}

std::string Node::get_node_data_movie_rating()
{
    return m_data.get_movie_rating();
}

size_t Node::get_node_data_movie_watch_count()
{
    return m_data.get_number_of_times_watched();
}

void Node::set_node_data_movie_title(std::string new_movie_title)
{
    m_data.set_movie_name(new_movie_title);
}

void Node::set_node_data_movie_rating(std::string new_movie_rating)\
{
    m_data.set_movie_rating(new_movie_rating);
}

void Node::set_node_data_movie_watch_count(size_t new_movie_watch_count)
{
    m_data.set_number_of_times_watched(new_movie_watch_count);
}

void Node::set_next_node(Node* next_node)
{
    m_next = next_node;
}

void Node::display_movie_data()
{
    m_data.display();
}

void Node::increment_movie_watch_count()
{
    m_data.increment_number_of_times_watched(); 
}

void Node::decrement_movie_watch_count()
{
    m_data.decrement_number_of_times_watched();
}

Node::~Node()
{ }
