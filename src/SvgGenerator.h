/*
 * SvgGenerator.h
 *
 *  Created on: 26. 7. 2014
 *      Author: petr
 */

#ifndef SVGGENERATOR_H_
#define SVGGENERATOR_H_

#include <string>
#include <stdio.h>
#include <map>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "NodeContainer.h"

using namespace std;

namespace Visualiser {

class SvgGenerator {

	/**
	 * structure for store size of image
	 */
	struct SIZE {

		/**
		 * width of image
		 */
		float width;

		/**
		 * height
		 */
		float height;
	};

	typedef map<string, string> ParamMap;

	/**
	 * vrite doctype to given string
	 * @param out output string
	 */
	static void docType(string &out);

	/**
	 * draw edge between nodes
	 * @param first begin of edge
	 * @param second end of edge
	 * @param scale scale of size
	 */
	static string drawEdge(const Node *first, const Node *second, const char *tpl, float scale, float width);

	/**
	 * generate lables for nodes
	 * @param container container with nodes
	 * @param scale scle of size
	 */
	static string drawLabels(const NodeContainer *container, float scale);

	/**
	 * draw nodes and 'solid' edges
	 * @param nodes container with nodes
	 * @param scale scale of coordinates
	 */
	static string drawNodes(const NodeContainer *container, float scale);

	/**
	 * draw fix edges to SVG
	 * @param container container with nodes
	 * @param scale scale of image
	 */
	static string edges(const NodeContainer *container, float scale);

	/**
	 * try to calculate optimal position of node label
	 * @param node give node
	 * @param offset offset of label from node mark
	 */
	static SIZE optimalNodeLabelPosition(const Node *node, float offset);

	/**
	 * load and return SVG template
	 * @param fileName name of file where template is stored
	 */
	static string loadTemplate(const char *fileName);

	/**
	 * load all templates from files
	 */
	static string loadTemplates();

	/**
	 * return dimension of image
	 */
	static SIZE size(const NodeContainer *container, float scale);

	/**
	 * wrap content to tag
	 * @param content string to wrap
	 * @param tag tag to wrap
	 * @param params parameters for wrapper
	 */
	static string wrap(const string &content, const char *tag, ParamMap params =
			ParamMap());

public:

	/**
	 * file where crossroad symbol is stored
	 */
	static const char *TEMPLATE_FILE_CROSSROAD;

	/**
	 * file where customer symbol is stored
	 */
	static const char *TEMPLATE_FILE_CUSTOMER;

	/**
	 * file where factory symbol is stored
	 */
	static const char *TEMPLATE_FILE_FACTORY;

	/**
	 * template definition SVG tag
	 */
	static const char *TAG_DEF;

	/**
	 * SVG group tag
	 */
	static const char *TAG_GROUP;

	/**
	 * root node
	 */
	static const char *TAG_SVG;

	/**
	 * size of input buffer
	 */
	static const int BUFFER_SIZE;

	/**
	 * maximal width of edge line
	 */
	static const float MAX_LINE_WIDTH;

	/**
	 * minimal width of edge line
	 */
	static const float MIN_LINE_WIDTH;

	/**
	 * pi constant
	 */
	static const float PI;

	/**
	 * offset of node width
	 */
	static const float NODE_ID_OFFSET;

	/**
	 * name of SVG template group with
	 * factory symbol
	 */
	static const char *GROUP_FACTORY;

	/**
	 * name of SVG template group with
	 * customer symbol
	 */
	static const char *GROUP_CUSTOMER;

	/**
	 * name of SVG template group with
	 * crossroad symbol
	 */
	static const char *GROUP_CROSSROAD;

	/**
	 * template for node generator
	 */
	static const char *NODE_TEMPLATE;

	/**
	 * template for render fix edge line
	 */
	static const char *FIX_EDGE_TEMPLATE;

	/**
	 * template for render switchable edge line
	 */
	static const char *SWITCHABLE_EDGE_TEMPLATE;

	/**
	 * template for label
	 */
	static const char *LABEL_TEMPLATE;

	SvgGenerator();
	virtual ~SvgGenerator();

	/**
	 * generate SVG file
	 * @param container source data
	 */
	static string generateSvg(const NodeContainer *container);
};

} /* namespace Visualiser */

#endif /* SVGGENERATOR_H_ */
