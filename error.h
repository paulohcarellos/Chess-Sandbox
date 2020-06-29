#pragma once
#include <string>

using namespace std;

class Error {

	string message_;

public:

	Error(string msg) : message_(msg) {}
	string message() const { return message_; }
};