/*
 * NodeContainer.cpp
 *
 *  Created on: 21. 7. 2014
 *      Author: petr
 */

#include "NodeContainer.h"

namespace Visualiser {

NodeContainer::NodeContainer() {
	// TODO Auto-generated constructor stub

}

NodeContainer::NodeContainer(const NodeContainer& o) {
}

NodeContainer::~NodeContainer() {
	// delete all nodes
	for (
			NodeList::iterator pos = n.begin();
			pos != n.end();
			++pos)
	{
		delete *pos;
	}
}

Node* NodeContainer::addNode(float x, float y, Node::NODE_TYPE type) {
	// crete node and add it to list
	Node *retVal = new Node(x, y, type);
	n.push_back(retVal);

	return retVal;
}

NodeContainer::NodeList NodeContainer::filter(Node::NODE_TYPE type) {
	// create return value
	NodeList retVal;

	// iterate over nodes and return them
	for (
			NodeList::iterator pos = n.begin();
			pos != n.end();
			++pos
	) {
		// check type
		if ((*pos)->type() == type) retVal.push_back(*pos);
	}

	return retVal;
}

NodeContainer::NodeList NodeContainer::filterCrossroads() {
	return filter(Node::CROSSROAD);
}

NodeContainer::NodeList NodeContainer::filterCustomer() {
	return filter(Node::CUSTOMER);
}

NodeContainer::NodeList NodeContainer::filterFactories() {
	return filter(Node::FACTORY);
}

const NodeContainer::NodeList& NodeContainer::nodes() const {
	return n;
}

NodeContainer::NodeList& NodeContainer::nodes() {
	return n;
}

void NodeContainer::removeNode(Node* node) {
	std::remove(n.begin(), n.end(), node);
	n.pop_back();
}

} /* namespace Visualiser */
