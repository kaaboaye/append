#include "main.h"

using namespace std;
namespace fs = std::experimental::filesystem;

const float VERSION = (float)1.0;

string input_dir;
vector<string> input_files;
string output_filename;
ifstream input_file;
ofstream output_file;

int main(int argc, char *argv[], char *envp[])
{
	if (argc != 3) { usage(); return EXIT_FAILURE; }

	input_dir = argv[1];
	output_filename = argv[2];

	input_files = get_files_list(input_dir);

	output_file = ofstream(output_filename);
	for (string &file : input_files)
	{
		input_file = ifstream(file);

		output_file << input_file.rdbuf() << endl;

		input_file.close();
	}

	output_file.close();
	return EXIT_SUCCESS;
}

void usage()
{
	cout
		<< "Append version: " << VERSION << endl
		<< endl
		<< "Usage" << endl
		<< "$ append [input directory] [output filename] " << endl
		<< endl
		<< "Author: kaye" << endl
		<< "Email: kaaboaye(at)gmail.com" << endl
		<< endl;
}

vector<string> get_files_list(const string dir)
{
	vector<string> files;

	for (auto &file : fs::directory_iterator(dir))
	{
		files.push_back(file.path().string());
	}

	return files;
}