#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>       /* time */
#include "Problem.hpp"

using namespace std;

int main(){
    int user_features;          // number of featuers entered by user
    int user_algorithm_pick;    // algorithm pick
    
    vector<int> init;           // initial vector we will use (filled/unfilled)

    vector<int> temp_vector;    // holds the vector with i
    double temp_vector_score;   // holds
    vector<int> curr_max = {};  // holds the current max state
    double curr_max_score = -1; // the max score based on curr max
    vector<int> temp_max = {};  // holds the best feature set of parent while it checks other children score
    double temp_max_score = 0;  // accuracy of temp_max feature set
    bool hill_climb = true;     // makes sure the child is larger than parent for our greedy search
    int i_val;                  // value assigned to our i for the for-loop's
    int i_less;                 // less than value for our for-loop

    // class object
    Problem search;
    

    // User selects the amount of features they want
    user_features = search.get_features(user_features);
    // User selects the algorithm
    user_algorithm_pick = search.get_algorithm(user_algorithm_pick);
    // create initial set
    init = search.create_init_vector(init, user_features, user_algorithm_pick); // init = {1,2,...,user_num}
    
    // Set our int i value for our for-loop
    // Set the value we are counting up to;
    // The reason we do this is:
    // Forward selection for loop is "for(int i = 1; i<user_features; i++)"
    // Backward selection for loop is "for(int i = 0; i<{1,2,...,n}; i++)" since we remove item n from vector
    if(user_algorithm_pick == 1){
        i_val = 1;
        i_less = user_features+1; // plus 1 since we are starting with one (int i =1)
    } else {
        i_val = 0;
        i_less = init.size();
    }
    
    // used to generate random number for score
    srand(time(0));
    // Loop as long as temp_max >= && the child is larger than parent node
    while(temp_max_score >= curr_max_score && hill_climb){
        // if curr_max is empty aka first iteration
        if(curr_max.empty()){
            for(int i = i_val; i<i_less; i++){
                // create a new vector by inserting or removing i (based on forward or backward selection)
                temp_vector = search.make_temp_vector(init, i, user_algorithm_pick);
                temp_vector_score = (rand() % 100+1); // (0...100) to get a percentage
                // print our feature set and the accuracy
                search.print_features_and_accurary(temp_vector,temp_vector_score);
                // if new max is found replace temp_max
                if(search.temp_score_larger(temp_vector_score, temp_max_score)){
                    temp_max = temp_vector;
                    temp_max_score = temp_vector_score;
                }
            }
            cout << endl;
        }
        // else not in the first iteration
        else {
            // change i_less to curr_max since the max before was init<int>
            if(user_algorithm_pick == 2)
                i_less = curr_max.size();
            
            for(int i = i_val; i<i_less; i++){
                if(user_algorithm_pick == 1){
                    // check if i exists in our vector already (ex: {1,2} cannot add another 1 or 2)
                    if(!(find(curr_max.begin(), curr_max.end(), i) != curr_max.end())){
                        // create a new vector by inserting i (forward selection)
                        temp_vector = search.make_temp_vector(curr_max, i, user_algorithm_pick);
                        temp_vector_score = (rand() % 100+1); // (0...100) / 100 to get a percentage
                        // print features and accuracy of current set
                        search.print_features_and_accurary(temp_vector,temp_vector_score);
                        // if new max is found replace temp_max
                        if(search.temp_score_larger(temp_vector_score, temp_max_score)){
                            temp_max = temp_vector;
                            temp_max_score = temp_vector_score;
                        }
                    }
                // else do backward selection
                } else {
                    // create a new vector by removing i (backward selection)
                    temp_vector = search.make_temp_vector(curr_max, i, user_algorithm_pick);
                    temp_vector_score = (rand() % 100+1); // (0...100) / 100 to get a percentage
                    // print features and accuracy of current set
                    search.print_features_and_accurary(temp_vector,temp_vector_score);
                    // if new max is found replace temp_max
                    if(search.temp_score_larger(temp_vector_score, temp_max_score)){
                        temp_max = temp_vector;
                        temp_max_score = temp_vector_score;
                    }
                }
            }
        }
        
        // only update curr_max_score if temp_max is bigger
        if(temp_max_score > curr_max_score){
            curr_max = temp_max;
            curr_max_score = temp_max_score;
            hill_climb = true;
            // print the best set up to this point
            search.print_best(curr_max, curr_max_score);
        } else {
            hill_climb = false;
        }
        cout << endl;
    }
    
    cout << "Finished search! ";
    search.print_best(curr_max, curr_max_score);
    cout << endl;
    return 1;
}




