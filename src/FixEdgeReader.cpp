/*
 * FixEdgeReader.cpp
 *
 *  Created on: 27. 7. 2014
 *      Author: petr
 */

#include "FixEdgeReader.h"
#include "Edge.h"

namespace Visualiser {

FixEdgeReader::FixEdgeReader() {
	// TODO Auto-generated constructor stub

}

FixEdgeReader::~FixEdgeReader() {
	// TODO Auto-generated destructor stub
}

void FixEdgeReader::buildEdges(NodeContainer* container) {
	// iterate over all nodes
	NodeContainer::NodeList &nodes = container->nodes();
	int nodeCount = nodes.size();

	for (int i = 0; i < nodeCount; ++i) {
		// get row
		FileRow row = operator [](i);

		for (int j = 0; j < nodeCount; ++j) {
			int isEdge = row.asInt();

			// if value is 1, edge will be created
			if (isEdge) {
				Edge *e =  nodes[i]->edge(nodes[j]);
				e->switchable(false);
				e->setSwitch(true);
			}
		}
	}
}

} /* namespace Visualiser */
