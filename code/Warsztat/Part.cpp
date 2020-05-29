#include "Part.h"
#include <string>

using namespace std;

Part::Part(string _name, double _price): name(_name), price(_price) {
}

Part::Part(string _name) : name(_name), price(0.0) {
}