// Aufgabe2.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//#include <rapidxml_ns/rapidxml_ns.hpp>#
//#include "rapidxml_ns/rapidxml_ns_utils.hpp"

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "SVGReader.h"


int main()
{
	std::string fullpath = "D:/QSync/Master_Studium/computational_geometry/Praktikum/ComputationalGeometry/Aufgabe2/Aufgabe2/Data/DeutschlandMitStaedten.svg";

	SVGReader reader(fullpath);

	int x;
	std::cin >> x;
}