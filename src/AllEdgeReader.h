/*
 * AllEdgeReader.h
 *
 *  Created on: 24. 7. 2014
 *      Author: petr
 */

#ifndef ALLEDGEREADER_H_
#define ALLEDGEREADER_H_

#include "NodeContainer.h"
#include "Edge.h"
#include "Reader.h"

namespace Visualiser {

class AllEdgeReader: public Visualiser::Reader {
public:

	AllEdgeReader();

	virtual ~AllEdgeReader();

	/**
	 * create edges
	 */
	void buildEdges(NodeContainer *container);
};

}

#endif /* ALLEDGEREADER_H_ */
