#pragma once

#include <string>

using namespace std;

class Arguments
{
public:
	Arguments(int argc, string argv[]);
	~Arguments();

	bool check();
private:
	int argc;
	char argv[3];
	char envp[3];
	bool ok;
};

