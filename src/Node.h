/*
 * Node.h
 *
 *  Created on: 20. 7. 2014
 *      Author: petr
 */

#ifndef NODE_H_
#define NODE_H_

#include <vector>

namespace Visualiser {

using namespace std;

class Edge;

/**
 *
 */
class Node {
public:

	/**
	 * type for edge store
	 */
	typedef vector<Edge *> EdgeList;

	enum NODE_TYPE {
		CUSTOMER,
		FACTORY,
		CROSSROAD,
		UNKNOWN
	};

private:

	/**
	 * x coordinate
	 */
	float _x;

	/**
	 * y coordinate
	 */
	float _y;

	/**
	 * contains list of edges
	 */
	EdgeList e;

	/**
	 * type of node
	 */
	NODE_TYPE t;

public:

	/**
	 * create node at 0,0
	 */
	Node();

	/**
	 * create node at given position
	 * @param x x coordinate
	 * @param y y coordiante
	 */
	Node(float x, float y, NODE_TYPE nodeType);

	/**
	 * derefere self from attached edges
	 */
	virtual ~Node();

	/**
	 * return list of edges
	 */
	const EdgeList &edges() const;

	/**
	 * return pointer on edge
	 * @param target other node of edge
	 */
	Edge *edge(const Node *target);

	/**
	 * return type of node
	 */
	NODE_TYPE type() const;

	/**
	 * set new node type
	 */
	void type(NODE_TYPE type);

	/**
	 * return X coordinate value
	 */
	float x() const;

	/**
	 * set new X coordinate value
	 * @param x new value
	 */
	void x(float x);

	/**
	 * return Y coordinate value
	 */
	float y() const;

	/**
	 * set new Y coordinate value
	 * @param y new value
	 */
	void y(float y);

	friend Edge;
};

} /* namespace Visualiser */

#endif /* NODE_H_ */
