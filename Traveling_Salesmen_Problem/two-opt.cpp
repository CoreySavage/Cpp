//
//  two-opt.cpp
//  CS325_Project3
//
//  2-opt Algorithm demonstrating a solution to the Traveling Salesmen Problem
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <math.h>
#include <chrono>
#include <algorithm>
#include <cstdlib>


using namespace std;

typedef vector<int> (*vectorOfFunctions) (vector<int>, int);


vector<vector <int> > parse_input(vector<string> input);


vector<vector <int> > two_opt(vector<vector <int> >);

vector<vector <int> > two_opt_competition(vector<vector <int> >);

long calc_distance(int x1, int y1, int x2, int y2);

vector<vector <int> > two_optSwap( const int& i, const int& k, vector<vector <int> >);

long long calc_total_distance(vector<vector <int> >);


int main(int argc, char *argv[]) {
    
    clock_t start_t, end_t;
    double runtime;

    vector< vector<int> > problemSet;
    vector<string> problemSet_notParsed;
    vector< vector<int> > route;
    string userInput;
    string temp;
    bool invalidInput = true;
    
    // Usage Error
    if(argc != 2) {
        cout << "Format Error!" << endl << "Usage: " << argv[0] << " <filename.txt>" << endl;
        return 1;
    }
    
    while (invalidInput) {
        cout << "Competition Mode? (y/n) ";
        cin >> userInput;
        
        if (userInput == "y" || userInput == "Y" || userInput == "n" || userInput == "N") {
            invalidInput = false;
        }
        else {
            cout << "Invalid Input!" << endl;
        }
    }
    
    ifstream problemsFile (argv[1]);
    
    // Error opening file
    if (!problemsFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    
    while(problemsFile.good()) {
        getline(problemsFile, temp);
        problemSet_notParsed.push_back(temp);
    }
    
    problemsFile.close();
    problemSet = parse_input(problemSet_notParsed);

    // Get input filename for output file
    string inputFile = argv[1];
    long i = inputFile.find_last_of(".");
    
    string outputFilename = inputFile.substr(0, i) + ".txt.tour";
    
    ofstream outputFile;
    outputFile.open(outputFilename.c_str(), ofstream::out);

    // Get algorithm runtime
    if (userInput == "n" || userInput == "N") {
        start_t = clock();
        route = two_opt(problemSet);
        end_t = clock();
        
        runtime = ((double) end_t - (double) start_t) / CLOCKS_PER_SEC;
        
        cout << endl << "Run Time = " << fixed << runtime << endl;
    }
    else {
        route = two_opt_competition(problemSet);
    }


    // Inputted coin values outputted to <fileName>change.txt
    outputFile << calc_total_distance(route) << endl;
    for (int i=0; i<route.size()-1;i++) {
        if (i != route.size()-2) {
            outputFile << route[i][0] << endl;
        }
        else {
            outputFile << route[i][0];
        }
    }
    
    outputFile.close();
    
    return 0;
}

//
// Parses vector<stings> to vector< vector<int> > data.
// Returns parsed vector< vector<int> > data.
//
vector<vector <int> > parse_input(vector<string> input) {
    
    string tempS;
    vector<int> tempV;
    vector< vector<int> > problemSet;
    
    for(int i = 0; i < input.size(); i++) {
        for(int j = 0; j < input[i].length(); j++) {
            // Store digits as temp strings
            if(isdigit(input[i][j])) {
                
                tempS.push_back(input[i][j]);
                // Last number in the problem set pushed to temp vector
                if (j == input[i].length() - 1) {
                    tempV.push_back(atoi(tempS.c_str()));
                    tempS = "";
                }
            }
            // Push temp string to temp vector when spaces are found
            else if(input[i][j] == ' ' && tempS.length() != 0) {
                tempV.push_back(atoi(tempS.c_str()));
                tempS = "";
            }
        }
        problemSet.push_back(tempV);
        tempV.clear();
        tempS = "";
    }
    /* ---- FOR TESTING ----
    for (int i=0; i<problemSet.size();i++) {
        for (int j=0; j<problemSet[i].size(); j++) {
            cout << problemSet[i][j] << " ";
        }
        cout << endl;
    }
    */
    return problemSet;

}


//
// Utilizes a 2-opt algorithm to find the min possible distance for TSP
//
vector<vector <int> > two_opt(vector<vector <int> > v) {
    // Get tour size
    int size = (int) v.size()-1;
    
    vector<vector <int> > newRoute = v;
    
    cout << "Start Distance: " << calc_total_distance(v) << endl;
    
    // repeat until no improvement is made
    int improve = 0;
    while ( improve < 20 ) {
        cout << "Break Counter: " << improve << endl;
        long long best_distance = calc_total_distance(v);
        
        for ( int i = 1; i < size - 1; i++ ) {
            for ( int k = i + 1; k < size; k++) {
                newRoute = two_optSwap( i, k, v);
                long long new_distance = calc_total_distance(newRoute);
                
                if ( new_distance < best_distance ) {
                    // Improvement found so reset
                    improve = 0;
                    best_distance = new_distance;
                    v = newRoute;
                }
            }
        }
        
        improve ++;
    }

    return v;
}

//
// Utilizes a 2-opt algorithm to find the min possible distance for TSP
// ---- Competition Mode (3 Min Timer) ----
//
vector< vector <int> > two_opt_competition(vector<vector <int> > v) {
    // Get tour size
    int size = (int) v.size()-1;
    
    vector<vector <int> > newRoute = v;
    
    cout << "Start Distance: " << calc_total_distance(v) << endl;
    
    std::chrono::time_point<std::chrono::system_clock> end;
    
    chrono::minutes m(3);
    end = std::chrono::system_clock::now() + m; // this is the end point
    
    // repeat until no improvement is made
    int improve = 0;
    long best_distance = calc_total_distance(v);
    while ( std::chrono::system_clock::now() < end && improve < 20 ) {
        
        for ( int i = 1; i < size - 1; i++ ) {
            for ( int k = i + 1; k < size; k++) {
                newRoute = two_optSwap( i, k, v);
                long new_distance = calc_total_distance(newRoute);
                
                if ( new_distance < best_distance ) {
                    // Improvement found so reset
                    improve = 0;
                    best_distance = new_distance;
                    v = newRoute;
                }
            }
        }
        
        improve ++;
    }
    
    return v;
    
}
vector<vector <int> > two_optSwap( const int& i, const int& k, vector<vector <int> > v)
{
    int size = (int) v.size();
    vector<int> tempV;
    vector<vector <int> > newTour;
    
    
    // 1. take route[0] to route[i-1] and add them in order to new_route
    for ( int c = 0; c <= i - 1; ++c ) {
        newTour.push_back(v[c]);
    }
    
    // 2. take route[i] to route[k] and add them in reverse order to new_route
    int dec = 0;
    for ( int c = i; c <= k; ++c ) {
        newTour.push_back(v[k-dec]);
        dec++;
    }
    
    // 3. take route[k+1] to end and add them in order to new_route
    for ( int c = k + 1; c < size; ++c ) {
        newTour.push_back(v[c]);
    }
    return newTour;
}


long calc_distance(int x1, int y1, int x2, int y2) {

    long xd = x1 - x2;
    long yd = y1 - y2;
    
    // ---- FOR TESTING ----
    //cout << endl << x1 << " - " << x2 << " = " << xd <<  endl;
    //cout << y1 << " - " << y2 << " = " << yd << endl;
    
    double notRounded = sqrt(xd*xd + yd*yd) +.5;
    
    long rounded = notRounded;

    return rounded;
    
}

long long calc_total_distance(vector<vector <int> > v) {
    
    
    long long totalDistance =  0;
    
    for (int i=0; i<v.size()-1; i++) {
        if (i != v.size()-2) {
            totalDistance += calc_distance(v[i][1], v[i][2], v[i+1][1], v[i+1][2]);
        }
        else {
            totalDistance += calc_distance(v[i][1], v[i][2], v[0][1], v[0][2]);
        }
    }
    
    return totalDistance;
   
}













