#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

string sha256(const string& data);

#endif // UTILS_H
