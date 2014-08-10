/*
 * FileRow.cpp
 *
 *  Created on: 22. 7. 2014
 *      Author: petr
 */

#include "FileRow.h"

namespace Visualiser {

FileRow::FileRow() {
}

FileRow::FileRow(string data) {
	d = data;
	p = d.begin();
}

FileRow::~FileRow() {
	// TODO Auto-generated destructor stub
}

const string& FileRow::data() const {
	return d;
}

void FileRow::data(string d) {
	this->d = d;
}

string FileRow::nextValue() {
	// iterate over white spaces
	skipWhites();

	// check end of line
	if (p == d.end()) return string();

	// iterate until next white character is found
	string::const_iterator start = p;

	while (!isWhite(*p) && p != d.end()) ++p;

	// return string beween iterators
	string retVal = string(start, p);
	return retVal;
}

void FileRow::skipWhites() {
	while (isWhite(*p) && p != d.end())
		++p;
}

bool FileRow::isWhite(char c) {
	return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}

FileRow::FileRow(const FileRow& o) {
	operator =(o);
}

void FileRow::reset() {
	p = d.begin();
}

stringstream *FileRow::prepareSStream() {
	return new stringstream(nextValue());
}

float FileRow::asFloat() {
	stringstream *str = prepareSStream();
	float retVal;

	(*str) >> retVal;

	delete str;

	return retVal;
}

int FileRow::asInt() {
	stringstream *str = prepareSStream();
	int retVal;

	(*str) >> retVal;

	delete str;

	return retVal;
}

string FileRow::asString() {
	return nextValue();
}

bool FileRow::isEnd() const {
	return p == d.end();
}

FileRow& FileRow::operator =(const FileRow& o) {
	d = o.d;
	p = d.begin() + (o.p - o.d.begin());

	return *this;
}

} /* namespace Visualiser */
