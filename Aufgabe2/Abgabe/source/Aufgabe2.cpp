// Aufgabe2.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//#include <rapidxml_ns/rapidxml_ns.hpp>#
//#include "rapidxml_ns/rapidxml_ns_utils.hpp"
//#include <boost/lambda/lambda.hpp>
#include <iostream>
//#include <iterator>
//#include <algorithm>
#include "SVGReader.h"
#include <map>

#include "PolygonAlgorithmTests.cpp"

std::map<std::string, float> statistic = { {"Bayern", 70542 }, {"Niedersachsen", 47710 },{"Baden__x26__WÃ¼rttemberg", 35748}, {"Nordrhein-Westfalen", 34113}, {"Brandenburg", 29654}, {"Mecklenburg-Vorpommern", 23294},
{"Hessen", 21115}, {"Sachsen-Anhalt", 20452}, {"Rheinland-Pfalz", 19858}, {"Sachsen", 18450}, {"ThÃ¼ringen", 16202}, {"Schleswig-Holstein", 15802}, {"Saarland", 2571}, {"Berlin", 891}, {"Hamburg", 755},
{"Bremen", 420} };

void calculateAreaOfAllstates() {

	std::string fullpath = "D:/QSync/Master_Studium/computational_geometry/Praktikum/ComputationalGeometry/Aufgabe2/Aufgabe2/Data/DeutschlandMitStaedten.svg";

	SVGReader reader(fullpath);

	// Routine for calculating the Area of all patches to for all states 
	std::vector<BundesLand> land = reader.getLand();
	std::map<std::string, float> area_of_bundesland;

	for (auto state_iter = land.begin(); state_iter != land.end(); state_iter++) {
		
		BundesLand state = *state_iter;
		float area = 0;
		int index = 0;
		

		for (auto iter = state.patches.begin(); iter != state.patches.end(); iter++) {
			float patch_area = std::abs(calcAreaOfPolygon(*iter));
			//std::cout << "patch:\t" << index++ << "\t" << patch_area << std::endl;
			area += patch_area;
		}
		area_of_bundesland[state.name] = area;
		
	}
	float scaling_mean = 0;
	for (auto bundesland : area_of_bundesland) {
		float original_area = statistic[bundesland.first];
		float area = bundesland.second;
		if (bundesland.first == "Brandenburg") {
			area = area - area_of_bundesland["Berlin"];
			area_of_bundesland["Brandenburg"] = area;
		}
		else if (bundesland.first == "Niedersachsen") {
			area = area - area_of_bundesland["Bremen"];
			area_of_bundesland["Niedersachsen"] = area;
		}
			
		float scaling = area / original_area;
		scaling_mean += scaling;
		std::cout << "state:\t" << bundesland.first << std::endl;
		std::cout << "state area:\t" << area << "\toriginal statearea:\t" << original_area  << "\tscaling factor:\t" << scaling << std::endl << std::endl;
	
	}
	scaling_mean /= float(area_of_bundesland.size());
	std::cout << "Berlin area is subtracted from Brandenburgs" << std::endl;
	std::cout << "Bremen area is subtracted from Niedersachsens" << std::endl;
	std::cout << "mean scale for svg to match original area\t" << scaling_mean << std::endl;

	float mean_error = 0;
	for (auto bundesland : area_of_bundesland) {
		float original_area = statistic[bundesland.first];
		float area = bundesland.second / scaling_mean;
		float error = abs(original_area - area);
		mean_error += error;

	}
	mean_error /= float(area_of_bundesland.size());;

	std::cout << "mean error for svg to match original area\t" << mean_error << "km^2" << std::endl;


	

} 

void calculateCityInStates() {
	std::string fullpath = "D:/QSync/Master_Studium/computational_geometry/Praktikum/ComputationalGeometry/Aufgabe2/Aufgabe2/Data/DeutschlandMitStaedten.svg";

	SVGReader reader(fullpath);

	// Routine for calculating the Area of all patches to for all states 
	std::vector<BundesLand> land = reader.getLand();
	std::vector<Stadt> städte = reader.getStädte();

	for (auto s : städte) {
		std::cout << std::endl;
		std::cout << s.name << std::endl;
		for (auto l : land) {
			bool in_patch = false;
			for (auto p : l.patches) {
				in_patch |= pointInPolygon(p, s.center);

			}
			
			if (in_patch) {
				
				std::cout << "in \t" << l.name << std::endl;
			}

		
			//std::cout << "in \t" << l.name << "\t" << in_patch << std::endl;
			
		
		}
	}





}

int main()
{

	//test_1();
	//test_2();
	//test_min_max();
	calculateAreaOfAllstates();
	calculateCityInStates();
	//test_point_in_polygon();
	//test_point_in_polygon_2();




	int x;
	std::cin >> x;
}