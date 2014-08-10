/*
 * main.cpp
 *
 *  Created on: 24. 7. 2014
 *      Author: petr
 */

#include <string>
#include <iostream>
#include <fstream>
#include "NodeReader.h"
#include "AllEdgeReader.h"
#include "FixEdgeReader.h"
#include "DeltasReader.h"
#include "SvgGenerator.h"

using namespace Visualiser;
using namespace std;

int main(int argc, char **argv) {

	NodeReader nodeReader;
	AllEdgeReader edgeReader;
	FixEdgeReader fixReader;
	DeltasReader deltaReader;

	string path = argv[1];
	string coordPath = path + "coordinates.txt";
	string allEdgePath = path + "all_possible_edges.txt";
	string fixEdgePath = path + "existing_edges.txt";
	string deltasPath = path + "optimal_deltas.txt";

	nodeReader.readFile(coordPath.c_str());
	NodeContainer *container = nodeReader.readNodes();

	edgeReader.readFile(allEdgePath.c_str());
	edgeReader.buildEdges(container);

	fixReader.readFile(fixEdgePath.c_str());
	fixReader.buildEdges(container);

	deltaReader.readFile(deltasPath.c_str());
	deltaReader.setData(container);

	string output = SvgGenerator::generateSvg(container);
	cout << output;

	fstream out;
	out.open("output.svg", ios::out);
	out << output;

	delete container;

	return 0;
}
