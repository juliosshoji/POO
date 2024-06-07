/* 
Júlio Shoji Zotovici Kobayashi
Class Series
June, 2024
*/

#ifndef SERIES_HPP_

#define SERIES_HPP_

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Series {
    private:
        int internal_id;
        string series_name;
        int release_year;
        int season;
        int episode_count;
        string main_actors;
        string main_characters;
        string network;
        int rating;

    public:

        Series(int, string, int, int,int, string, string , string, int);
        Series(string, int, int,int, string, string , string, int);
        Series();

        int getInternal_id();
        string getSeries_name();
        int getRelease_year();
        int getSeason();
        int getEpisode_count();
        string getMain_actors();
        string getMain_characters();
        string getNetwork();
        int getRating();

        void setInternal_id(int internal_id);
        void setSeries_name(string series_name);
        void setRelease_year(int release_year);
        void setSeason(int season);
        void setEpisode_count(int episode_count);
        void setMain_actors(string main_actors);
        void setMain_characters(string getMain_characters);
        void setNetwork(string network);
        void setRating(int rating);
};

#endif