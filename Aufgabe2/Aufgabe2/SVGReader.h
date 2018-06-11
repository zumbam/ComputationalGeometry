#pragma once
#include <string>
#include <sstream>
#include "Polygon.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

class SVGReader
{
public:
	SVGReader(std::string path);
	~SVGReader();

	std::vector<BundesLand> getLand();

private:
	std::string path;
	std::vector<BundesLand> land;
};

