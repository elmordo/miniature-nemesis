/*
 * NodeContainer.h
 *
 *  Created on: 21. 7. 2014
 *      Author: petr
 */

#ifndef NODECONTAINER_H_
#define NODECONTAINER_H_

#include <vector>
#include <algorithm>

#include "Node.h"

using namespace std;

namespace Visualiser {

/**
 * constains list of nodes
 * this container is not "destructor proof" - if node is deleted
 * invalid pointer remains in container
 */
class NodeContainer {
public:

	/**
	 * contains list of nodes
	 */
	typedef vector<Node *> NodeList;

private:

	/**
	 * list of nodes
	 */
	NodeList n;

public:

	/**
	 * create empty instance
	 */
	NodeContainer();

	/**
	 * copytor
	 * @param o other instance
	 */
	NodeContainer(const NodeContainer &o);

	/**
	 * delete nodes in list
	 */
	virtual ~NodeContainer();

	/**
	 * create new node, add it to list and return pointer to it
	 * @param x x coordinate
	 * @param y y coordinate
	 * @param type type of node
	 */
	Node *addNode(float x, float y, Node::NODE_TYPE type);

	/**
	 * return list of nodes filtered by type
	 */
	NodeList filter(Node::NODE_TYPE type);

	/**
	 * return list of crossroads
	 */
	NodeList filterCrossroads();

	/**
	 * return list of customers
	 */
	NodeList filterCustomer();

	/**
	 * return list of factories
	 */
	NodeList filterFactories();

	/**
	 * return list of nodes
	 */
	const NodeList &nodes() const;

	/**
	 * return reference on node list
	 */
	NodeList &nodes();

	/**
	 * remove node from container
	 * instance is deleted
	 */
	void removeNode(Node *node);
};

} /* namespace Visualiser */

#endif /* NODECONTAINER_H_ */
