//
//  Problem.hpp
//  Project2_Search_Algo_Test
//
//  Created by Carlos Loeza on 5/20/21.
//

#ifndef Problem_hpp
#define Problem_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>       /* time */
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Problem{
public:
    
    // Alphabetic order (function name)
    
    // create initial vector
    vector<int> create_init_vector(vector<int> init, int user_num, int user_algorithm_pick);
    
    // ask user for algorithm
    int get_algorithm(int user_algorithm_pick);
    
    // ask user for features
    int get_features(int user_feature);
    
    // Make a vector for each new possible combination
    vector<int> make_temp_vector(vector<int> init, int i, int user_algorithm_pick);

    // print the best result up to this point (best feature set based on size and accuracy)
    void print_best(vector<int> curr_max, double curr_max_score);
    
    // print the current feature set and accuracy
    void print_features_and_accurary(vector<int> temp_vector, double temp_vector_score);
    
    // Check if temp_vector_score is larger temp_max_score
    bool temp_score_larger(int temp_vector_score, int temp_max_score);
    

    
};

#endif /* Problem_hpp */
