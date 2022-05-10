#include <iostream>
#include <unordered_map>
#include <iterator>
#include <cstring>
#include <fstream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <queue>
#include <array>
#include <vector>
#include <queue>
#include <cassert>
#include <stack>
#include <algorithm>
using namespace std;

unordered_map<string, vector<string>> cities;

unordered_map<string, bool> visitedArray;

//unordered_map<string, bool> discoveredSet;

queue<string> nodeQueue;

vector<string> topoSortList;

vector<string> noIncoming;

stack<string> vertexStack;



void DepthFirstSearch(string node){
  if(visitedArray[node] == true){
    return;
  }
  visitedArray[node] = true; //NOT CORRECT YET

  //push to stack
  //vertexStack.push(node);

  for(int i = 0; i < cities[node].size(); i++){
      DepthFirstSearch(cities[node][i]);
  }
  vertexStack.push(node);
}





int main() {
  
  //tester code, comment out on Kattis
  ifstream cin("input.txt");
  ifstream textFile;
  textFile.open("input.txt");
  if(textFile.fail()){
    cout << "File Open Failed";
    return 0;
  }


  string inputInt;
  getline(cin, inputInt);
  int numFiles = std::stoi(inputInt);
  //cout << numFiles;
  string inputLine;
  string first;

  for(int i = 0; i < numFiles; i++){
    getline(cin, inputLine);



    //first 
    first = inputLine.substr(0, inputLine.find(':'));
    if(first.length() + 1 == inputLine.length()){
      noIncoming.push_back(first);
    }
//cout << first;

    //files
    if(inputLine.length() > inputLine.find(':') + 2){
    string dependencies = inputLine.substr(inputLine.find(':') + 2);
      int numOfOccurences = std::count(dependencies.begin(), dependencies.end(), ' ');
      for(int j = 0; j < numOfOccurences + 1; j++){
      string file = dependencies.substr(0, dependencies.find(' '));
        cities[file].push_back(first);
        //cout << file;
      dependencies = dependencies.substr(dependencies.find(' ') + 1);
        }
  }
    //cout << endl;
    }

  string head;
  getline(cin, head);
  DepthFirstSearch(head);
  //vertexStack.push(head);
  while(vertexStack.size() != 0){
    cout << vertexStack.top();
    cout << endl;
    vertexStack.pop();
  }
/*
for(int i = 0; i < noIncoming.size(); i++){
  cout << noIncoming[i];
}
*/

  /*
  for(int i = 0; i < cities["gmp"].size(); i++){
    cout << cities["gmp"][i];
  }
  */

  
}