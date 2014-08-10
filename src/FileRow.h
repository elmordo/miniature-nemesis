/*
 * FileRow.h
 *
 *  Created on: 22. 7. 2014
 *      Author: petr
 */

#ifndef FILEROW_H_
#define FILEROW_H_

#include <string>
#include <sstream>

using namespace std;

namespace Visualiser {

class FileRow {

	/**
	 * row data
	 */
	string d;

	/**
	 * current position in string
	 */
	string::const_iterator p;

	/**
	 * iterate over white spaces to next non-white character
	 */
	void skipWhites();

	/**
	 * return true if given character
	 * is white space
	 * @param c character to test
	 */
	static bool isWhite(char c);

	/**
	 * read value and insert it to string stream
	 */
	stringstream *prepareSStream();

public:

	/**
	 * create empty instance
	 */
	FileRow();

	/**
	 * initialise instance with data
	 */
	FileRow(string data);

	/**
	 * copytor
	 */
	FileRow(const FileRow &o);

	/**
	 * destructor
	 */
	virtual ~FileRow();

	/**
	 * read next value as float
	 */
	float asFloat();

	/**
	 * read next value as integer
	 */
	int asInt();

	/**
	 * read next value as string
	 * (alias for nextValue())
	 */
	string asString();

	/**
	 * return row data
	 */
	const string &data() const;

	/**
	 * set new data
	 */
	void data(string d);

	/**
	 * return true if last value was read
	 */
	bool isEnd() const;

	/**
	 * read next value in string
	 * if there is no more data, return empty string
	 */
	string nextValue();

	/**
	 * reset position in string to start
	 */
	void reset();

	/**
	 * assign operator
	 * @param o original instance
	 */
	FileRow &operator =(const FileRow &o);
};

} /* namespace Visualiser */

#endif /* FILEROW_H_ */
