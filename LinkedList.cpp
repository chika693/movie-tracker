#include "LinkedList.h"

LinkedList::LinkedList()
: m_list_head {nullptr}
{ }

LinkedList::LinkedList(std::string movie_title, std::string movie_rating, size_t movie_watch_count)
{
    Node* head = new Node(movie_title, movie_rating, movie_watch_count);
    m_list_head = head;
}

LinkedList::LinkedList(const LinkedList& source)
{
    // what I'm doing, copying head node from source list, to new list and the subsequent nodes
    // things i need: 
    //      access to source's node data, and next_node - ultimately creating a duplicate of entire llist
    //      keep in mind the source's head node being copied will be the rvalue for new node lvalue using copy constructor
    //      
    //      steps:
    //          m_list_head = source.m_list_head; 
    //          Node* source_curr_ptr = source.m_list_head;
    //          while source_curr_ptr not nullptr
    //
    //              
    //
}

size_t LinkedList::get_size()
{
    Node* curr = m_list_head;
    size_t count {}; 

    while (curr != nullptr) 
    { 
        ++count;
        curr = (*curr).get_next_node();
    }
    
    return count;
}

void LinkedList::append(std::string movie_title, std::string movie_rating, size_t movie_watch_count)
{
    if (m_list_head == nullptr)
    {
        m_list_head = new Node(movie_title, movie_rating, movie_watch_count);
    } else {
        Node* node_to_add = new Node(movie_title, movie_rating, movie_watch_count);
        Node* curr = m_list_head;
        while (curr->get_next_node() != nullptr)
        {
            curr = curr->get_next_node();
        }
        curr->set_next_node(node_to_add);
    }
}

void LinkedList::remove_movie_from_container(std::string movie_title)
{
    Node* curr = m_list_head;
    Node* prev = m_list_head;
    size_t count {};
    while (curr != nullptr)
    {
        if ((*curr).get_node_data_movie_title() == movie_title && count == 0)
        {
            m_list_head = (*m_list_head).get_next_node();
            std::cout << "Movie titled: \"" << movie_title << "\" successfully removed." << std::endl;
        } else if ((*curr).get_node_data_movie_title() == movie_title && count > 0)
        {
            (*prev).set_next_node((*curr).get_next_node());
            std::cout << "Movie titled: " << movie_title << " successfully removed." << std::endl;
        }

        prev = curr;
        curr = (*curr).get_next_node();
        ++count;
    }
}

void LinkedList::display()
{
    Node* curr = m_list_head;
    while (curr != nullptr)
    {
        (*curr).display_movie_data();
        curr = (*curr).get_next_node();
    }
}

void LinkedList::change_movie_title(std::string movie_title, std::string new_title)
{
    Node* curr = m_list_head;
    while (curr != nullptr)
    {
        if (curr->get_node_data_movie_title() == movie_title)
        {
            curr->set_node_data_movie_title(new_title);
            break;
        } else curr = curr->get_next_node();
    }
}

void LinkedList::change_movie_rating(std::string movie_title, std::string new_movie_rating)
{
    Node* curr = m_list_head;
    while (curr != nullptr)
    {
        if (curr->get_node_data_movie_title() == movie_title)
        {
            curr->set_node_data_movie_rating(new_movie_rating);
            break;
        } else curr = curr->get_next_node();
    }
}

void LinkedList::change_movie_watch_count(std::string movie_title, size_t new_watch_count)
{
    Node* curr = m_list_head;
    while (curr != nullptr)
    {
        if (curr->get_node_data_movie_title() == movie_title)
        {
            curr->set_node_data_movie_watch_count(new_watch_count);
            break;
        } else curr = curr->get_next_node();
    }
}

void LinkedList::increment_movie_watch_count(std::string movie_title)
{
    Node* curr = m_list_head;
    while (curr != nullptr)
    {
        if (curr->get_node_data_movie_title() == movie_title)
        {
            curr->increment_movie_watch_count();
            break;
        } else curr = curr->get_next_node();
    }
}

void LinkedList::decrement_movie_watch_count(std::string movie_title)
{
    Node* curr = m_list_head;
    while (curr != nullptr)
    {
        if (curr->get_node_data_movie_title() == movie_title)
        {
            curr->decrement_movie_watch_count();
            break;
        } else curr = curr->get_next_node();
    }
}

std::string LinkedList::get_specific_movie_rating(std::string movie_title)
{
    Node* curr = m_list_head;
    while (curr != nullptr)
    {
        if (curr->get_node_data_movie_title() == movie_title)
        {
            return curr->get_node_data_movie_rating();
        } else curr = curr->get_next_node();
    }
    return NULL;
}

bool LinkedList::check_if_movie_title_in_tracker(std::string movie_title)
{
    Node* curr = m_list_head;
    bool movie_in_tracker = false;
    while (curr != nullptr)
    {
        if (curr->get_node_data_movie_title() == movie_title)
        {
            movie_in_tracker = true;
            return movie_in_tracker;
        } else curr = curr->get_next_node();
    }
    return movie_in_tracker;
}

LinkedList::~LinkedList() 
{
    delete m_list_head;
}
