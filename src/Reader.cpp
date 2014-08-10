/*
 * Reader.cpp
 *
 *  Created on: 22. 7. 2014
 *      Author: petr
 */

#include "Reader.h"

namespace Visualiser {

Reader::Reader() {
	// TODO Auto-generated constructor stub

}

Reader::~Reader() {
	// TODO Auto-generated destructor stub
}

void Reader::readFile(const char* fileName) {
	ifstream input;

	input.open(fileName, ios::in);

	bool x = input.is_open();
	r.clear();

	string buffer;

	while (std::getline(input, buffer)) {
		r.push_back(FileRow(buffer));
	}
}

const Reader::FileRows& Reader::rows() const {
	return r;
}

const FileRow Reader::operator [](int index) const {
	return r[index];
}

} /* namespace Visualiser */
