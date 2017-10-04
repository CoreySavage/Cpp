//
//  main.cpp
//  CS325_Project2
//
//  Algorithms demonstrating greedy and dynamic methods for determining minimum change.
//  Usage: main.cpp <filename.txt>
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

typedef vector<int> (*vectorOfFunctions) (vector<int>, int);


vector<vector <int> > parse_input(vector<string> input);

vector<int> changegreedy(vector<int>, int);

vector<int> changedp(vector<int>, int);


int main(int argc, char *argv[]) {
    
    clock_t start_t, end_t;
    double time;
    
    vectorOfFunctions algorithm[] = {changegreedy, changedp};
    string functionNames[] = {"changegreedy", "changedp"};
    
    vector< vector<int> > problemSet;
    vector<string> problemSet_notParsed;
    string temp;
    int minCoins = 0;
    
    // Usage Error
    if(argc != 2) {
        cout << "Format Error!" << endl << "Usage: " << argv[0] << " <filename.txt>" << endl;
        return 1;
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
    int i = inputFile.find_last_of(".");
    
    string outputFilename = inputFile.substr(0, i) + "change.txt";
    
    ofstream outputFile;
    outputFile.open(outputFilename.c_str(), ofstream::out);
    
    // Runs problem sets for both greedy and dynamic methods
    for (int a=0; a<2 ; a++) {
        outputFile << "Algorithm " << functionNames[a] << ":" << endl;
        cout << "Algorithm " << functionNames[a] << ":" << endl;
        for (int i = 0; i < problemSet.size(); i++) {
            
            int index = i + 1;                              // Amount values are odd
            vector<int> c(problemSet[i].size(), 0);         // Initialize coin solutions to 0
            
            // Get algorithm runtime
            start_t = clock();
            c = algorithm[a](problemSet[i], problemSet[index][0]);
            end_t = clock();
            
            time = ((double) end_t - (double) start_t) / CLOCKS_PER_SEC;
            
            cout << "A= " << problemSet[index][0] <<" time = " << fixed << time << endl;
            
            // Count min number of coins needed
            for (int i = 0; i < c.size(); i++){
                minCoins += c[i];
            }
            
            // Inputted coin values outputted to <fileName>change.txt
            for (int j=0; j<problemSet[i].size(); j++) {
                outputFile << problemSet[i][j];
                outputFile << " ";
            }
            
            outputFile << endl;
            // Output coin solution
            for(int i = 0; i < c.size(); i++) {
                outputFile << c[i];
                outputFile << " ";
            }
            // Min number of coins
            outputFile << endl << minCoins << endl;
            
            minCoins = 0;
            c.clear();
            
            i++;
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
            else if(input[i][j] == ' ') {
                tempV.push_back(atoi(tempS.c_str()));
                tempS = "";
            }
        }
        problemSet.push_back(tempV);
        tempV.clear();
        tempS = "";
    }
    /* -For testing-
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
// Utilizes a greedy method for making change.
// Returns vector containing number of each coin that is needed for a
//
vector<int> changegreedy(vector<int> v, int a) {
    // Store number of each coin needed
    vector<int> c(v.size(), 0);
    
    // Begin with highest coin value
    int i = v.size() - 1;
    
    while (a > 0) {
        // When a coin is less than a, add to solution
        if (v[i] <= a) {
            a -= v[i];
            c[i] += 1;
        }
        // If a coin is higher, lower the index
        if (v[i] > a) {
            i--;
        }
    }
    
    return c;
}

//
// Utilizes a dynamic programming method for making change.
// Returns vector containing number of each coin that is needed for a
//
vector<int> changedp(vector<int> v, int a) {
    
    // Table for solutions from 0..1..a
    vector< vector<int> > allProblemSolutions;
    vector<int> singleProblemSolutions;
    
    // Base case: set T[0]= 0
    vector<int> baseCase(v.size(), 0);
    allProblemSolutions.push_back(baseCase);

    // Bottom up, fill table with num of coins needed for every int to a
    for (int i = 1; i <= a; i++) {
        
        vector<int> tempSolutions(v.size(), 0);
        // Set count to worst possible solution 1 * a
        int currentCount = a;
        int j = 0;

        // Find coins needed to make change
        while (j < v.size() && v[j] <= i) {
            
            vector<int> tempSolutions(v.size(), 0);
            int tempCount = 0;
            
            // use old coin solutions from table
            tempSolutions = allProblemSolutions[i - v[j]];
            tempSolutions[j]++;

            for (int p = 0; p < tempSolutions.size(); p++) {
                // Num of coins needed
                tempCount += tempSolutions[p];
            }
            // add new solution if temp count is lower or equal to current count
            if (tempCount <= currentCount) {
                singleProblemSolutions = tempSolutions;
                currentCount = tempCount;
            }
            
            j++;
        }
        allProblemSolutions.push_back(singleProblemSolutions);
    }
    
    return allProblemSolutions[a];
}














