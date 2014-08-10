/*
 * Edge.cpp
 *
 *  Created on: 20. 7. 2014
 *      Author: petr
 */

#include "Edge.h"

namespace Visualiser {

Edge::Edge() {
	// set nodes to 0x0 value
	n1 = 0x0;
	n2 = 0x0;
	s = true;
	o = false;
	u = 0;
}

Edge::Edge(Node* first, Node* second) {
	// default value for nodes
	n1 = n2 = 0x0;

	u = 0;

	// set given nodes
	this->first(first);
	this->second(second);
	s = true;
	o = false;
}

Edge::~Edge() {
	// remove references
	first(0x0);
	second(0x0);
}

Node* Edge::first() {
	return n1;
}

const Node* Edge::first() const {
	return n1;
}

void Edge::first(Node* node) {
	setReference(&n1, node);
}

Node* Edge::second() {
	return n2;
}

const Node* Edge::second() const {
	return n2;
}

void Edge::setReference(Node** slot, Node* newNode) {
	// remove reference if there is some
	if (*slot != 0x0) {
		Node::EdgeList &edges = (*slot)->e;
		std::remove(edges.begin(), edges.end(), this);
		edges.pop_back();
	}

	// add reference to new node
	if (newNode != 0x0) newNode->e.push_back(this);

	// set new value
	*slot = newNode;
}

void Edge::derefere(Node* node) {
	if (n1 == node) first(0x0);
	if (n2 == node) second(0x0);
}

bool Edge::switchable() const {
	return s;
}

void Edge::switchable(bool val) {
	s = val;
}

void Edge::setSwitch(bool val) {
	o = val;
}

bool Edge::isOn() const {
	/*
	 * if edge is not switchable, value is alwais 1
	 */
	return !s || o;
}

void Edge::second(Node* node) {
	setReference(&n2, node);
}

void Edge::incrementUsed() {
	++u;
}

int Edge::used() const {
	return u;
}

} /* namespace Visualiser */
