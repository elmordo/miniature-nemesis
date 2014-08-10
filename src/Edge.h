/*
 * Edge.h
 *
 *  Created on: 20. 7. 2014
 *      Author: petr
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <algorithm>

#include "Node.h"

using namespace std;

namespace Visualiser {

/**
 * represents link between two nodes
 */
class Edge {

	/**
	 * start node
	 */
	Node *n1;

	/**
	 * end node
	 */
	Node *n2;

	/**
	 * has value True if edge is switchable
	 */
	bool s;

	/**
	 * has True value if edge is switched on
	 * only for switchable edges
	 */
	bool o;

	/**
	 * specifiy how many times edge was used
	 */
	int u;

	/**
	 * discard old node reference and set new one
	 * @param oldNode node to be replaced
	 * @param newNode node to replace
	 */
	void setReference(Node **slot, Node *newNode);

public:

	/**
	 * empty edge from nowhere to nowhere (0x0)
	 */
	Edge();

	/**
	 * create edge with given nodes
	 * @param first start node
	 * @param second end node
	 */
	Edge(Node *first, Node *second);

	/**
	 * remove self from nodes edge lists
	 */
	virtual ~Edge();

	/**
	 * derefere given node from edge
	 * if edge does not do anything with this node, do nothing
	 */
	void derefere(Node *node);

	/**
	 * return pointer to the first node
	 * if no node is set, return 0x0
	 */
	Node *first();

	/**
	 * return constant pointer to the first node
	 * if no node is set, return 0x0
	 */
	const Node *first() const;

	/**
	 * set new the first node
	 * @param node new the first node
	 */
	void first(Node *node);

	/**
	 * return switchable value
	 */
	bool switchable() const;

	/**
	 * set new switchable value
	 */
	void switchable(bool val);

	/**
	 * set switch status
	 */
	void setSwitch(bool val);

	/**
	 * increment one to used value
	 */
	void incrementUsed();

	/**
	 * return True if edge is on
	 */
	bool isOn() const;

	/**
	 * return pointer to the second node
	 * if no node is set, return 0x0
	 */
	Node *second();

	/**
	 * return constant second to the first node
	 * if no node is set, return 0x0
	 */
	const Node *second() const;

	/**
	 * set new the second node
	 * @param node the second node to be set
	 */
	void second(Node *node);

	/**
	 * return value of used
	 */
	int used() const;
};

} /* namespace Visualiser */

#endif /* EDGE_H_ */
