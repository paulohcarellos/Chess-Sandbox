#pragma once
#include <string>

using namespace std;

class Error {

	string message_;

public:

	Error(string str) : message_(str) {}
	string message() { return message_; }
};
