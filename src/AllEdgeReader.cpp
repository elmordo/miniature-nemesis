/*
 * AllEdgeReader.cpp
 *
 *  Created on: 24. 7. 2014
 *      Author: petr
 */

#include "AllEdgeReader.h"

namespace Visualiser {
AllEdgeReader::AllEdgeReader() {
	// TODO Auto-generated constructor stub

}

AllEdgeReader::~AllEdgeReader() {
	// TODO Auto-generated destructor stub
}

void AllEdgeReader::buildEdges(NodeContainer* container) {
	// iterate over all nodes
	int nodeCount = container->nodes().size();

	for (int i = 0; i < nodeCount; ++i) {
		// get row
		FileRow row = operator [](i);

		for (int j = 0; j < nodeCount; ++j) {
			int isEdge = row.asInt();

			// if value is 1, edge will be created
			if (isEdge) {
				Edge *edge = new Edge(container->nodes()[i], container->nodes()[j]);
				edge->setSwitch(false);
				edge->switchable(true);
			}
		}
	}
}

}
