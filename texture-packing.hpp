#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <chrono>
#include <vector>
#include <map>
#include <algorithm>

#include <sys/stat.h>
#include <sys/types.h>

#include "PPMImage.hpp"
#include "Rectangle.hpp"
#include "Bin.hpp"

#include "algoFF.hpp"
#include "algoFFDH.hpp"
#include "algoNFDH.hpp"
#include "algoBFDH.hpp"

int main (int argc, char *argv[]);

void showUsage(const std::string name);
void showHelp(const std::string name);
bool isBadInt(const std::string s);

typedef void (*funcAlgo)(const std::vector<Rectangle>&, std::vector<Bin>&, coord, coord);
