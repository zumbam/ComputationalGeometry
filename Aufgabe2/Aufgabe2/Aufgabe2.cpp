// Aufgabe2.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//#include <rapidxml_ns/rapidxml_ns.hpp>#
//#include "rapidxml_ns/rapidxml_ns_utils.hpp"

//#include <boost/lambda/lambda.hpp>
#include <iostream>
//#include <iterator>
//#include <algorithm>
#include "SVGReader.h"

#include "PolygonAlgorithmTests.cpp"

void calculateAreaOfAllstates() {

	std::string fullpath = "D:/QSync/Master_Studium/computational_geometry/Praktikum/ComputationalGeometry/Aufgabe2/Aufgabe2/Data/DeutschlandMitStaedten.svg";

	SVGReader reader(fullpath);

	// Routine for calculating the Area of all patches to for all states 
	std::vector<BundesLand> land = reader.getLand();
	
	for (auto state_iter = land.begin(); state_iter != land.end(); state_iter++) {
		BundesLand state = *state_iter;
		float area = 0;
		int index = 0;
		std::cout << "state:\t" << state.name << std::endl;
		for (auto iter = state.patches.begin(); iter != state.patches.end(); iter++) {
			float patch_area = std::abs(calcAreaOfPolygon(*iter));
			std::cout << "patch:\t" << index++ << "\t" << patch_area << std::endl;
			area += patch_area;
		}
		std::cout << "state area:\t" << area << std::endl;


	}

}

void calculateCityInStates() {
	std::string fullpath = "D:/QSync/Master_Studium/computational_geometry/Praktikum/ComputationalGeometry/Aufgabe2/Aufgabe2/Data/DeutschlandMitStaedten.svg";

	SVGReader reader(fullpath);

	// Routine for calculating the Area of all patches to for all states 
	std::vector<BundesLand> land = reader.getLand();
	std::vector<Stadt> städte = reader.getStädte();

	for (auto s : städte) {
		std::cout << s.name << std::endl;
		for (auto l : land) {
			bool in_patch = false;
			for (auto p : l.patches) {
				in_patch |= pointInPolygon(p, s.center);
			}
			std::cout << "in \t" << l.name << in_patch << std::endl;
		
		}
	}





}

int main()
{

	//test_1();
	//test_2();
	//test_min_max();
	//calculateAreaOfAllstates();
	calculateCityInStates();
	//test_point_in_polygon();
	//test_point_in_polygon_2();




	int x;
	std::cin >> x;
}