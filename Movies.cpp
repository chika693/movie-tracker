#include "Movies.h"

Movies::Movies()
{ }

Movies::Movies(const Movies& source)
{
    m_movie_container = source.m_movie_container;
    m_list_size = source.m_list_size;
}

size_t* Movies::begin(){ return 0; }

size_t* Movies::end() 
{ 
    size_t* end_of_vector_ptr = &this->m_list_size;
    return end_of_vector_ptr; 
}

void Movies::add(std::string movie_name, std::string movie_rating, size_t watched_count)
{
    if (Movies::check_if_movie_title_in_tracker(movie_name))
    {
        std::cout << "You already have a movie with the title \"" << movie_name << "\" in your tracker." << std::endl;
    } else 
    {
        m_movie_container.push_back(Movie(movie_name, movie_rating, watched_count));
        ++m_list_size;
    }
}

void Movies::display() const
{
    std::cout << "There are " << m_list_size << " movies in your tracker." << std::endl;
    std::cout << std::endl;
    for (auto e: m_movie_container) e.display(); 
}

size_t Movies::get_size()
{
    return m_list_size;
}

bool Movies::check_if_movie_title_in_tracker(std::string movie_title)
{
    bool movie_title_in_tracker = false;
    for (auto e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            movie_title_in_tracker = true;
        }
    }

    return movie_title_in_tracker;
}

void Movies::change_movie_watch_count(std::string movie_title, size_t new_movie_watch_count)
{
    for (auto& e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            e.set_number_of_times_watched(new_movie_watch_count);
        }
    }
}

void Movies::increment_movie_watch_count(std::string movie_title)
{
    for (auto& e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            e.increment_number_of_times_watched();
        }
    }
}

void Movies::decrement_movie_watch_count(std::string movie_title)
{
    for (auto& e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            e.decrement_number_of_times_watched();
        }
    }
}

void Movies::remove_movie_from_container(std::string movie_title)
{
    size_t position {};
    for (auto& e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            std::cout << "Successfully removed \"" << movie_title << "\" from your tracker." << std::endl;
            m_movie_container.erase(m_movie_container.begin() + position);
            --m_list_size;
        }
        ++position;
    }
}

void Movies::change_movie_title(std::string movie_title, std::string new_title)
{
    for (auto& e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            e.set_movie_name(new_title);
        }
    }
}

void Movies::change_movie_rating(std::string movie_title, std::string new_movie_rating)
{
    for (auto& e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            if (e.get_movie_rating() == new_movie_rating)
            {
                std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                std::cout << "There was no new data inputed for this field. No change was made." << std::endl;
            }
            else
                e.set_movie_rating(new_movie_rating);
        }
    }
}

std::string Movies::get_specific_movie_rating(std::string movie_title) 
{
    for (auto& e : m_movie_container)
    {
        if (e.get_movie_name() == movie_title)
        {
            return e.get_movie_rating();
        }
    }
    return NULL;
}

Movies::~Movies()
{ }
