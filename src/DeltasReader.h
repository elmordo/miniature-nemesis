/*
 * DeltasReader.h
 *
 *  Created on: 28. 7. 2014
 *      Author: petr
 */

#ifndef DELTASREADER_H_
#define DELTASREADER_H_

#include <string>
#include <cstdio>

#include "Reader.h"
#include "NodeContainer.h"

using namespace std;

namespace Visualiser {

class DeltasReader: public Reader {

	/**
	 * contains information about edge
	 */
	struct NODE_INDEXES {
		/**
		 * start node
		 */
		int from;

		/**
		 * end node
		 */
		int to;
	};

	static NODE_INDEXES explodeSignature(string signature);

public:

	static const char *EDGE_SIGNATURE_TEMPLATE;

	DeltasReader();
	virtual ~DeltasReader();

	/**
	 * set data read from file
	 * @param container node container
	 */
	void setData(NodeContainer *container);
};

} /* namespace Visualiser */

#endif /* DELTASREADER_H_ */
