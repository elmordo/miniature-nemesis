/*
 * Node.cpp
 *
 *  Created on: 20. 7. 2014
 *      Author: petr
 */

#include "Node.h"
#include "Edge.h"

namespace Visualiser {

Node::Node() {
	_x = 0.0f;
	_y = 0.0f;
	t = UNKNOWN;
}

Node::~Node() {
	// remove self from edges
	for (
			EdgeList::reverse_iterator pos = e.rbegin();
			pos != e.rend();
			pos++
	) {
		(*pos)->derefere(this);
	}
}

Node::Node(float x, float y, NODE_TYPE nodeType) {
	_x = x;
	_y = y;
	t = nodeType;
}

const Node::EdgeList& Node::edges() const {
	return e;
}

Node::NODE_TYPE Node::type() const {
	return t;
}

void Node::type(NODE_TYPE type) {
	t = type;
}

float Node::x() const {
	return _x;
}

void Node::x(float x) {
	_x = x;
}

float Node::y() const {
	return _y;
}

void Node::y(float y) {
	this->_y = y;
}

Edge* Node::edge(const Node* target) {
	EdgeList::iterator pos = e.begin();
	Edge *retVal = 0x0;

	do {
		if ((*pos)->first() == target || (*pos)->second() == target) {
			retVal = *pos;
		}

		++pos;
	} while (retVal == 0x0 && pos != e.end());

	return retVal;
}

} /* namespace Visualiser */

