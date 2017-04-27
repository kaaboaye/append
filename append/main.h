#pragma once

#include <iostream> 
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std; 

void usage();
vector<string> get_files_list(const string dir);