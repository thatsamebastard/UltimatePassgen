#pragma once
#include <codecvt>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;


void debug(wostream&,const vector<int>&);
void print(wostream&,const vector<int>&);
void print(wostream&,const vector<int>&, const vector<int>&);
void set(string,int&);
extern vector<int> rus;
extern vector<int> en;
extern vector<int> num;
