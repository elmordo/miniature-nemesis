/*
 * DeltasReader.cpp
 *
 *  Created on: 28. 7. 2014
 *      Author: petr
 */

#include "DeltasReader.h"
#include "Edge.h"

namespace Visualiser {

const char *DeltasReader::EDGE_SIGNATURE_TEMPLATE = "%d-%d";

DeltasReader::DeltasReader() {
	// TODO Auto-generated constructor stub

}

DeltasReader::~DeltasReader() {
	// TODO Auto-generated destructor stub
}

DeltasReader::NODE_INDEXES DeltasReader::explodeSignature(string signature) {
	int from, to;

	sscanf(signature.c_str(), EDGE_SIGNATURE_TEMPLATE, &from, &to);

	NODE_INDEXES retVal = {from - 1, to - 1};

	return retVal;
}

void DeltasReader::setData(NodeContainer *container) {
	// iterate over rows (edges)
	const FileRows &rows = this->rows();

	for (
			FileRows::const_iterator pos = rows.begin();
			pos != rows.end();
			++pos
	) {
		FileRow row(*pos);

		// read edge signature
		string signature = row.asString();

		// explode signature to node positions
		NODE_INDEXES indexes = explodeSignature(signature);

		// get edge
		Edge *edge = container->nodes()[indexes.from]->edge(container->nodes()[indexes.to]);

		// if edge not found, continue
		if (edge == 0x0) continue;

		// iterate over data
		while (!row.isEnd()) {
			if (row.asInt()) {
				edge->incrementUsed();
			}
		}
	}
}

} /* namespace Visualiser */
