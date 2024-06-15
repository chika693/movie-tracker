#include "Movie.h"

size_t Movie::number_of_movie_objects = 0; 

Movie::Movie(std::string name, std::string rating, size_t watch_count)
: m_movie_name{name}, m_movie_rating{rating}, m_number_of_times_watched{watch_count}
{ 
    ++number_of_movie_objects;
}

Movie::Movie(const Movie& source)
: Movie{source.m_movie_name, source.m_movie_rating, source.m_number_of_times_watched}
{ }

const void Movie::display() 
{
    std::cout << "Movie title: " << m_movie_name << std::endl;
    std::cout << "Movie rating: " << m_movie_rating << std::endl;
    std::cout << "Number of times watched: " << m_number_of_times_watched << std::endl;
    std::cout << std::endl;
}

size_t Movie::get_number_of_movie_objects() const
{
    return number_of_movie_objects;
}

std::string Movie::get_movie_name() const
{
    return m_movie_name;
}

std::string Movie::get_movie_rating() const
{
    return m_movie_rating;
}

size_t Movie::get_number_of_times_watched() const
{
    return m_number_of_times_watched;
}

void Movie::set_movie_name(std::string new_movie_title)
{
    m_movie_name = new_movie_title;
}

void Movie::set_movie_rating(std::string new_movie_rating)
{
    m_movie_rating = new_movie_rating;
}

void Movie::set_number_of_times_watched(size_t new_watch_count)
{
    m_number_of_times_watched = new_watch_count;    
    std::cout << "Watch count has been updated." << std::endl;
}

void Movie::increment_number_of_times_watched()
{
    ++m_number_of_times_watched;
    std::cout << "Successfully incremented." << std::endl;
}

void Movie::decrement_number_of_times_watched()
{
    if (m_number_of_times_watched >= 1)
    {
        --m_number_of_times_watched;
        std::cout << "Successfully decremented." << std::endl;
    }
    else 
        std::cout << "Unable to decrement because number of times watched is already at 0." << std::endl;
}

Movie::~Movie() 
{ 
    --number_of_movie_objects;
}
