/*
Movies on Flight

You are on a flight and wanna watch two movies during this flight.
You are given int[] movie_duration which includes all the movie durations.
You are also given the duration of the flight which is d in minutes.
Now, you need to pick two movies and the total duration of the two movies is less than or equal to (d - 30min).
Find the pair of movies with the longest total duration. If multiple found, return the pair with the longest movie.

e.g.
Input
movie_duration: [90, 85, 75, 60, 120, 150, 125]
d: 250

Output from aonecode.com
[90, 125]
90min + 125min = 215 is the maximum number within 220 (250min - 30min)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findLongestMovies(vector<int> movies, int max)
{
    max = max - 30 ;
    vector<int> longest_movies(2);
    int duration = movies[0];
    int temp_duration = 0;

    
        for (int i = 0; i < movies.size(); ++i)
        {
            for (int j = i+1; j < movies.size() - i; ++j)
            {
                temp_duration = movies[i] + movies[j];

                if ( duration < temp_duration && temp_duration <= max ){
                    duration = temp_duration;
                    longest_movies.clear();
                    longest_movies.push_back(movies[i]);
                    longest_movies.push_back(movies[j]);
                }
            }

        }

    return longest_movies;
}

int main()
{
    vector<int> movies(2);
    vector<int> movie_duration = {90, 85, 75, 60, 120, 150, 125};
    int d = 250;

    movies = findLongestMovies(movie_duration, d);

    cout << movies.at(0) << endl;
    cout << movies.at(1) << endl;
}
