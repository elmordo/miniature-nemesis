/*
 * Reader.h
 *
 *  Created on: 22. 7. 2014
 *      Author: petr
 */

#ifndef READER_H_
#define READER_H_

#include <vector>
#include <string>
#include <fstream>

#include "FileRow.h"

using namespace std;

namespace Visualiser {

/**
 * read given file and explode content to rows and values
 */
class Reader {
public:

	/**
	 * contain list of rows in file
	 */
	typedef vector<FileRow> FileRows;

private:

	/**
	 * list of rows in files
	 */
	FileRows r;


public:

	/**
	 * create empty instance
	 */
	Reader();

	/**
	 * destroy instance
	 */
	virtual ~Reader();

	/**
	 * read content from file
	 * all content that was read will be discarted
	 * @param fileName name of file with content
	 */
	void readFile(const char *fileName);

	/**
	 * return list of rows
	 */
	const FileRows &rows() const;

	/**
	 * return row on given index
	 */
	const FileRow operator [](int index) const;
};

} /* namespace Visualiser */

#endif /* READER_H_ */
