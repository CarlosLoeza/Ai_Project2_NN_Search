//
//  Problem.cpp
//  Project2_Search_Algo_Test
//
//  Created by Carlos Loeza on 5/20/21.
//

#include "Problem.hpp"


vector<int> Problem::create_init_vector(vector<int> init, int user_num, int user_algorithm_pick){
    // forward selection starts with empty set
    if(user_algorithm_pick == 1){
        init = {};
    // backwords starts with full set (ex: 1,2,...,user_num)
    }else{
        for(int i = 1; i<=user_num; i++){
            init.push_back(i);
        }
    }
    return init;
}


int Problem::get_algorithm(int user_algorithm_pick){
    cout << "Type the number of the algorithm you want to run" << endl;
    cout << "1. Forward Selection" << endl;
    cout << "2. Backward Selection" << endl;
    cin >> user_algorithm_pick;
    cout << endl;
    return  user_algorithm_pick;
}


int Problem::get_features(int user_feature){
    cout << "Welcome to Carlos Loeza & Jeffreyson Nguyen Feature Selection Algorithm" << endl;
    cout << endl;
    cout << "Please enter the total number of features: ";
    cin >> user_feature;
    cout << endl;
    return user_feature;
}


void Problem::print_best(vector<int> curr_max, double curr_max_score){
    // print best result
    cout << "Feature(s) set {";
    for(auto it: curr_max)
        cout << it << ",";
    cout << "} was best!";
    cout << " Accuracy is " << curr_max_score << "%" << endl;
}


void Problem::print_features_and_accurary(vector<int> temp_vector, double temp_vector_score){
    // print the feature(s) we are using
    cout << "Using feature(s) {";
    for(auto it: temp_vector)
        cout << it << ",";
    cout << "}";
    cout << " accuracy is " << temp_vector_score << "%" << endl;
}


// Make a vector for each new possible combination
vector<int> Problem::make_temp_vector(vector<int> init, int i, int user_algorithm_pick){
    
    vector<int> temp_vector = init;
    
    // forward selection
    if(user_algorithm_pick == 1){
        temp_vector.push_back(i); // add i to our temp
        sort(temp_vector.begin(), temp_vector.end()); // make the items to avoid problems with map
    // backward selection
    } else {
        auto iterator = temp_vector.begin()+i;
        temp_vector.erase(iterator);
    }
    return temp_vector;
}


bool Problem::temp_score_larger(int temp_vector_score, int temp_max_score){
    if(temp_vector_score > temp_max_score)
        return true;
    else
        return false;
}
