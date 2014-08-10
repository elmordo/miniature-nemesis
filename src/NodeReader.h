/*
 * NodeReader.h
 *
 *  Created on: 22. 7. 2014
 *      Author: petr
 */

#ifndef NODEREADER_H_
#define NODEREADER_H_

#include "Reader.h"
#include "NodeContainer.h"

namespace Visualiser {

class NodeReader: public Reader {

	/**
	 * read data and create node
	 * return next start position
	 * @param start first line of data set
	 * @param count number of nodes of given type
	 * @param container container with nodes
	 * @param nType type of node
	 */
	int readItems(int start, int count, NodeContainer &container, Node::NODE_TYPE nType);

public:
	NodeReader();
	virtual ~NodeReader();

	/**
	 * read information about nodes
	 * and their coordinates and create nodes
	 * return container with read nodes
	 */
	NodeContainer *readNodes();
};

} /* namespace Visualiser */

#endif /* NODEREADER_H_ */
