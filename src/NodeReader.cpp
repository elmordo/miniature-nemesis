/*
 * NodeReader.cpp
 *
 *  Created on: 22. 7. 2014
 *      Author: petr
 */

#include "NodeReader.h"

namespace Visualiser {

NodeReader::NodeReader() {
	// TODO Auto-generated constructor stub

}

NodeReader::~NodeReader() {
	// TODO Auto-generated destructor stub
}

int NodeReader::readItems(int start, int count, NodeContainer& container,
		Node::NODE_TYPE nType) {

	int maxI = start + count;

	for (int i = start; i < maxI; ++i) {
		FileRow row = this->operator [](i);

		float x = row.asFloat(),
				y = row.asFloat();

		container.addNode(x, y, nType);
	}

	return maxI;
}

NodeContainer *NodeReader::readNodes() {
	NodeContainer *retVal = new NodeContainer();

	// read definition of file
	FileRow defs = this->operator [](0);
	int total = defs.asInt(),
			customers = defs.asInt(),
			factories = defs.asInt(),
			crossroads = defs.asInt();

	int current = 1;

	current = readItems(current, customers, *retVal, Node::CUSTOMER);
	current = readItems(current, factories, *retVal, Node::FACTORY);
	readItems(current, crossroads, *retVal, Node::CROSSROAD);

	return retVal;
}

} /* namespace Visualiser */
