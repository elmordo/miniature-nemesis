/*
 * FixEdgeReader.h
 *
 *  Created on: 27. 7. 2014
 *      Author: petr
 */

#ifndef FIXEDGEREADER_H_
#define FIXEDGEREADER_H_

#include "Reader.h"
#include "NodeContainer.h"

namespace Visualiser {

class FixEdgeReader: public Reader {
public:
	FixEdgeReader();
	virtual ~FixEdgeReader();

	/**
	 * create edges
	 */
	void buildEdges(NodeContainer *container);
};

} /* namespace Visualiser */

#endif /* FIXEDGEREADER_H_ */
