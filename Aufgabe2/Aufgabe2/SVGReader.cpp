#include "stdafx.h"
#include "SVGReader.h"


BundesLand parsePath(std::string & path, std::string & bundeslandname) {

	std::vector<Polygon> patches;

	Polygon curPatch;
	Point2D startPoint(0,0);
	std::istringstream f(path);
	std::string line;
	//boost::char_separator<char> sep(",");
	while (std::getline(f, line)) {

		if (line.empty()) {
			continue;
		}

		if (boost::starts_with(line,"l")) {
			std::string values = line.substr(1);
			Point2D point;
			int index = values.find(',');

			point.x = atof(values.substr(0, index).c_str());
			point.y = atof(values.substr(index+1).c_str());
			startPoint = startPoint + point;
			curPatch.addPoint(startPoint);
			//std::cout << "l" << std::endl;
		}
		else if (boost::starts_with(line, "M") || (boost::starts_with(line, "L"))) {
			std::string values = line.substr(1);
			Point2D point;
			int index = values.find(',');

			point.x = atof(values.substr(0, index).c_str());
			point.y = atof(values.substr(index+1).c_str());
			startPoint = point;
			curPatch.addPoint(startPoint);
			//std::cout << "M" << std::endl;
		}
		else if (boost::starts_with(line, "z")) {
			//std::cout << "z" << std::endl;
			patches.push_back(curPatch);
			curPatch = Polygon();
		}
		else {
			std::cout << "ignored Line" << line << std::endl;
		}
	}
	return BundesLand(patches, bundeslandname);
}


SVGReader::SVGReader(std::string path)
{
	this->path = path;

	typedef boost::property_tree::ptree tree;

	tree pt;
	try {

		boost::property_tree::xml_parser::read_xml(path, pt);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}



	pt = pt.get_child("svg");

	BOOST_FOREACH(tree::value_type &v, pt.get_child("g")) {

		//The data function is used to access the data stored in a node.	
		tree cur_path = v.second;
		std::string id = cur_path.get<std::string>("<xmlattr>.id");
		std::string path = cur_path.get<std::string>("<xmlattr>.d");
		BundesLand curstate = parsePath(path, id);
		std::cout << curstate <<std::endl;
	}

	// test only first element
	//std::string id = pt.get<std::string>("path.<xmlattr>.id");
	//std::string v = pt.get<std::string>("path.<xmlattr>.d");
	//BundesLand curstate = parsePath(v, id);

}

void readPath() {



}




SVGReader::~SVGReader()
{
}
