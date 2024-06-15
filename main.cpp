#include <iostream>
#include <limits>
#include <string>
#include "Movies.h"

void check_if_user_watch_count_input_is_valid(size_t& watched_count);
void get_movie_title_from_user_and_store_in_memory(std::string& movie_title);
void check_if_user_movie_rating_input_is_valid(std::string& movie_rating);

int main(int argc, char* argv[])
{
    char option;
    std::cout << "Welcome to your movie database!" << std::endl;
    do
    {


        std::cout << "-------------------------- MAIN MENU ----------------------------" << std::endl;
        std::cout << "To select a function, press the corresponding letter" << std::endl;
        std::cout << std::endl;

        std::cout << "Add a movie: A" << std::endl;
        std::cout << "Remove a movie: R" << std::endl;
        std::cout << "Get the number of movies added into your tracker: G" << std::endl;
        std::cout << "View your movies: V" << std::endl;
        std::cout << "Increase movie watch count: E" << std::endl;
        std::cout << "Quit: Q" << std::endl;
        std::cout << std::endl; 
        std::cout << "What would you like to do? " << std::endl;
        std::cin >> option;

        static Movies movie_container_obj = Movies();
    
        switch(option)
        {
            case 'a':
            case 'A':
            {
                std::cout << "-------------------------- ADDING A MOVIE ----------------------------" << std::endl;
                std::string movie_name;
                get_movie_title_from_user_and_store_in_memory(movie_name);
                if (movie_container_obj.check_if_movie_title_in_tracker(movie_name))
                {
                    std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                    std::cout << "This movie already exists in your tracker." << std::endl;
                    std::cout << std::endl;
                    break;
                }


                std::string movie_rating;
                check_if_user_movie_rating_input_is_valid(movie_rating);

                size_t watched_count;
                bool valid_input = false;
                std::cout << "Enter number of times (an integer -> yourInput >= 0) you've watched the movie: ";
                
                check_if_user_watch_count_input_is_valid(watched_count);

                size_t previous_size_of_tracker = movie_container_obj.get_size();
                movie_container_obj.add(movie_name, movie_rating, watched_count);

                std::cout << std::endl;
                std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                movie_container_obj.get_size() > previous_size_of_tracker ? std::cout << "ADDED " << "\"" << movie_name << "\"" << " TO THE TRACKER." << std::endl : std::cout << "MOVIE WAS NOT ADDED." << std::endl;
                std::cout << std::endl;
            }
                break;

            case 'r':
            case 'R':
            {
                std::string movie_title;
                get_movie_title_from_user_and_store_in_memory(movie_title);
                if (movie_container_obj.check_if_movie_title_in_tracker(movie_title))
                {
                    std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                    movie_container_obj.remove_movie_from_container(movie_title);
                } else {
                    std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                    std::cout << "The movie titled: \"" << movie_title << "\" does not exist in your tracker." << std::endl;
                }
                std::cout << std::endl;
                break;
            }

            case 'v':
            case 'V':
            {
                std::cout << "-------------------------- VIEWING THE MOVIES IN YOUR TRACKER ----------------------------" << std::endl;
                if (movie_container_obj.get_size() == 0) 
                    {
                        std::cout << "You have no movies in your tracker." << std::endl; 
                        std::cout << std::endl;
                    }
                else 
                        movie_container_obj.display();
            }
                break;

            case 'e':
            case 'E':
            {
                std::string movie_title;
                get_movie_title_from_user_and_store_in_memory(movie_title);

                char edit_mode_option;
                if (movie_container_obj.check_if_movie_title_in_tracker(movie_title))
                {
                    do {
                            std::cout << "-------------------------- EDIT MOVIE ATTRIBUTES... ----------------------------" << std::endl;
                            std::cout << "What would you like to change about this movie? To select a function, press the corresponding letter." << std::endl;
                            std::cout << std::endl;
                            std::cout << "Change movie title: T" << std::endl; 
                            std::cout << "Change movie rating: R" << std::endl; 
                            std::cout << "Change movie watch count: W" << std::endl;
                            std::cout << "Exit: E" << std::endl;

                            std::cout << "What would you like to do? ";
                            std::cin >> edit_mode_option;
                            std::cout << std::endl;

                            switch (edit_mode_option)
                            {
                                case 't':
                                case 'T':
                                {
                                    std::string new_title;
                                    get_movie_title_from_user_and_store_in_memory(new_title);
                                    if (new_title == movie_title)
                                    {
                                        std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                                        std::cout << "There was no change to the title. No change was made." << std::endl;   
                                    } else 
                                    {
                                        movie_container_obj.change_movie_title(movie_title, new_title);
                                        std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                                        std::cout << "Movie originally titled: \"" << movie_title << "\" was sucessfully changed to \"" << new_title << "\"" << std::endl;
                                        movie_title = new_title;
                                    }
                                    std::cout << std::endl;
                                }
                                    break;

                                case 'r':
                                case 'R':
                                {
                                    std::string original_movie_rating = movie_container_obj.get_specific_movie_rating(movie_title);
                                    std::string new_movie_rating;                          
                                    check_if_user_movie_rating_input_is_valid(new_movie_rating);
                                    if (original_movie_rating == new_movie_rating)
                                case 'r':
                                case 'R':
                                {
                                    std::string original_movie_rating = movie_container_obj.get_specific_movie_rating(movie_title);
                                    std::string new_movie_rating;                          
                                    check_if_user_movie_rating_input_is_valid(new_movie_rating);
                                    if (original_movie_rating == new_movie_rating)
                                    {
                                        std::cout << std::endl;
                                        break;
                                    } else 
                                    {
                                        movie_container_obj.change_movie_rating(movie_title, new_movie_rating);
                                        std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                                        std::cout << "Movie rating successfully changed from: \"" << original_movie_rating << "\" to: \"" << movie_container_obj.get_specific_movie_rating(movie_title) << "\"" << std::endl;
                                    }
                                    std::cout << std::endl;
                                }
                                    break;

                                case 'w':
                                case 'W':
                                    char change_watch_count_through_option;
                                    // --------------
                                    std::cout << "-------------------------- Performing increase watch count funtionality... ----------------------------" << std::endl;
                                    std::cout << "To select a function, press the corresponding letter" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "Change movie watch count in tracker: C" << std::endl; 
                                    std::cout << "Increment a movie's watch count in tracker: I" << std::endl; 
                                    std::cout << "Decrement a movie's watch count in tracker: D" << std::endl;

                                    std::cout << "What would you like to do? ";
                                    std::cin >> change_watch_count_through_option;
                                    std::cout << std::endl;

                                    if (change_watch_count_through_option == 'c' || change_watch_count_through_option == 'C')
                                    {
                                        size_t new_watch_count {};
                                        std::cout << "What would you like to change the watch count to? ";
                                        check_if_user_watch_count_input_is_valid(new_watch_count);
                                        std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                                        movie_container_obj.change_movie_watch_count(movie_title, new_watch_count);
                                    } else if (change_watch_count_through_option == 'i' || change_watch_count_through_option == 'I')
                                    {
                                        std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                                        movie_container_obj.increment_movie_watch_count(movie_title);
                                    } else if (change_watch_count_through_option == 'd' || change_watch_count_through_option == 'D')
                                    {
                                    std::cout << std::endl;
                                
                                    break;

                                case 'e':
                                case 'E':
                                    break;

                                default:
                                    std::cout << "Invalid option." << std::endl;
                            }
                    } while (edit_mode_option != 'e' && edit_mode_option != 'E');
                } else 
                {
                    std::cout << "-------------------------- RESULT ----------------------------" << std::endl;
                    std::cout << "There is no move titled: \"" << movie_title << "\" in your tracker." << std::endl;
                    std::cout << std::endl;
                }
                
                break;
            } 

            case 'g':
            case 'G':
                std::cout << "-------------------------- NUMBER OF MOVIES IN YOUR TRACKER: ----------------------------" << std::endl;
                std::cout << movie_container_obj.get_size() << std::endl;
                std::cout << std::endl;
                break;

            case 'q':
            case 'Q':
                break;

            default:
                std::cout << "-------------------------- hit default case ----------------------------" << std::endl;
                std::cout << "Invalid option. Enter a letter option from the list provided." << std::endl;
                std::cout << std::endl;
                break;
        }

    } while (option != 'q' && option != 'Q');


    return 0;
}


void check_if_user_watch_count_input_is_valid(size_t& watched_count)
{
    bool valid_input = false;

    while (!valid_input) {
        std::cout << "Please enter an integer: ";
        if (std::cin >> watched_count) {
            valid_input = true;                                                                                      
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
}

void check_if_user_movie_rating_input_is_valid(std::string& movie_rating)
{
    std::cout << "Enter movie rating (G, PG, PG-13, R): ";
    std::cin >> movie_rating;                                                                                                            
                                                                                                                                        
    if (movie_rating != "G" || movie_rating != "PG" || movie_rating != "PG-13" || movie_rating != "R")                                  
    {
        while (movie_rating != "G" &&  movie_rating != "PG" && movie_rating != "PG-13" && movie_rating != "R") 
        {
            std::cout << "Invalid rating, enter one of these (G, PG, PG-13, R): ";                                                      
            std::cin >> movie_rating;
        }
    } else {
        std::cin >> movie_rating;    
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << std::endl;
}

void get_movie_title_from_user_and_store_in_memory(std::string& movie_title)
{
    std::cout << "Enter the title of the movie: ";
    std::cin >> std::ws;
    std::getline(std::cin, movie_title);
    std::cout << std::endl;
void get_movie_title_from_user_and_store_in_memory(std::string& movie_title)
{
    std::cout << "Enter the title of the movie: ";
    std::cin >> std::ws;
    std::getline(std::cin, movie_title);
    std::cout << std::endl;
}
