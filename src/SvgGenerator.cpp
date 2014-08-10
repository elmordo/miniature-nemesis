/*
 * SvgGenerator.cpp
 *
 *  Created on: 26. 7. 2014
 *      Author: petr
 */

#include "SvgGenerator.h"
#include "Edge.h"

namespace Visualiser {

const char *SvgGenerator::TEMPLATE_FILE_CROSSROAD = "templates/crossroad.tpl";
const char *SvgGenerator::TEMPLATE_FILE_CUSTOMER = "templates/customer.tpl";
const char *SvgGenerator::TEMPLATE_FILE_FACTORY = "templates/factory.tpl";

const char *SvgGenerator::TAG_DEF = "defs";
const char *SvgGenerator::TAG_GROUP = "g";
const char *SvgGenerator::TAG_SVG = "svg";

const int SvgGenerator::BUFFER_SIZE = 1024;
const float SvgGenerator::MAX_LINE_WIDTH = 5.0f;
const float SvgGenerator::MIN_LINE_WIDTH = 1.0f;
const float SvgGenerator::PI = 3.14159265f;
const float SvgGenerator::NODE_ID_OFFSET = 15;

const char *SvgGenerator::GROUP_CROSSROAD = "crossroad-group";
const char *SvgGenerator::GROUP_CUSTOMER = "customer-group";
const char *SvgGenerator::GROUP_FACTORY = "factory-group";

const char *SvgGenerator::NODE_TEMPLATE = "<use xlink:href='#%s' x='%f' y='%f' width=\"10\" height=\"10\" />\n";
const char *SvgGenerator::FIX_EDGE_TEMPLATE = "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke: #000000; stroke-width: %f;stroke-dasharray:6,2;stroke-dashoffset:0\" />\n";
const char *SvgGenerator::SWITCHABLE_EDGE_TEMPLATE = "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke: #000000; stroke-width: %f;\" />\n";
const char *SvgGenerator::LABEL_TEMPLATE = "<g transform=\"translate(%f, %f)\"><text transform=\"scale(1, -1)\" fill=\"red\" style=\"fill-opacity: 1\">%d</text></g>\n";

SvgGenerator::SvgGenerator() {
	// TODO Auto-generated constructor stub

}

void SvgGenerator::docType(string& out) {
	out += "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
}

string SvgGenerator::wrap(const string &content, const char *tag, ParamMap params) {
	// prepare tag sequence
	string tagString(tag);

	for (ParamMap::iterator pos = params.begin();
			pos != params.end();
			++pos
	) {
		tagString += " ";
		tagString += pos->first + "=\"" + pos->second + "\"";
	}

	return string("<") + tagString + ">\n" + content + "\n</" + tag + ">";
}

string SvgGenerator::drawEdge(const Node* first, const Node* second,
		const char *tpl, float scale, float width) {

	float x1 = first->x() * scale,
			y1 = first->y() * scale,
			x2 = second->x() * scale,
			y2 = second->y() * scale;

	char buffer[1024];

	sprintf(buffer, tpl, x1, y1, x2, y2, width);

	return string(buffer);
}

SvgGenerator::~SvgGenerator() {
	// TODO Auto-generated destructor stub
}

string SvgGenerator::loadTemplate(const char* fileName) {
	// open file
	fstream tplFile;
	tplFile.open(fileName, ios::in);

	// read file and return data
	string retVal;
	char buffer[BUFFER_SIZE];

	// erase buffer
	for (int i = 0; i < BUFFER_SIZE; ++i)
		buffer[i] = 0x0;

	while (!tplFile.eof()) {
		// read file to buffer
		tplFile.read(buffer, BUFFER_SIZE);

		// append buffer to return string
		retVal += buffer;
	}

	// close file
	tplFile.close();

	return retVal;
}

string SvgGenerator::loadTemplates() {
	string templates;

	templates += loadTemplate(TEMPLATE_FILE_CROSSROAD);
	templates += loadTemplate(TEMPLATE_FILE_CUSTOMER);
	templates += loadTemplate(TEMPLATE_FILE_FACTORY);

	return wrap(templates, TAG_DEF);
}

string SvgGenerator::drawNodes(const NodeContainer* container, float scale) {
	string content;

	// iterate over nodes
	const NodeContainer::NodeList &nodes = container->nodes();

	for (NodeContainer::NodeList::const_iterator pos = nodes.begin();
			pos < nodes.end();
			++pos
	) {
		// dereference node
		const Node *n = *pos;

		// get coordinates
		float x = n->x() * scale,
				y = n->y() * scale;

		// resolve type
		string nodeType;

		switch (n->type()) {
		case Node::FACTORY:
			nodeType = GROUP_FACTORY;
			break;

		case Node::CUSTOMER:
			nodeType = GROUP_CUSTOMER;
			break;

		case Node::CROSSROAD:
			nodeType = GROUP_CROSSROAD;
			break;

		case Node::UNKNOWN:
			nodeType = "";
			break;
		}

		char buffer[1024];
		buffer[0] = 0x0;
		sprintf(buffer, NODE_TEMPLATE, nodeType.c_str(), x, y);
		content += buffer;

	}

	return wrap(content, TAG_GROUP);
}

string SvgGenerator::edges(const NodeContainer* container, float scale) {
	const NodeContainer::NodeList &nodes = container->nodes();
	string output;

	float range = MAX_LINE_WIDTH - MIN_LINE_WIDTH;

	// iterate over nodes
	for (
			NodeContainer::NodeList::const_iterator pos = nodes.begin();
			pos != nodes.end();
			++pos
	) {
		// derefere iterator and get list of edges
		Node *node = *pos;
		const Node::EdgeList &edges = node->edges();

		// iterate over edges
		for (
				Node::EdgeList::const_iterator pos = edges.begin();
				pos != edges.end();
				++pos
		) {
			// if first node is this node, draw line
			const Edge *edge = *pos;

			// calculate width
			if ((edge->switchable() && edge->used() == 0) || edge->first() != node) continue;

			float width = MIN_LINE_WIDTH + range / 100.0f * (float) edge->used();
			const char *tpl;

			if (edge->switchable()) {
				tpl = SWITCHABLE_EDGE_TEMPLATE;
			} else {
				tpl = FIX_EDGE_TEMPLATE;
				width = 1;
			}

			// draw edge
			output += drawEdge(node, edge->second(), tpl, scale, width);
		}
	}

	return wrap(output, TAG_GROUP);
}

SvgGenerator::SIZE SvgGenerator::size(const NodeContainer* container, float scale) {
	SIZE retVal = { 0, 0 };

	// iterate over nodes and test dimension
	for (
			NodeContainer::NodeList::const_iterator pos = container->nodes().begin();
			pos != container->nodes().end();
			++pos
	) {
		Node *node = *pos;

		if (retVal.width < node->x()) retVal.width = node->x();
		if (retVal.height < node->y()) retVal.height = node->y();
	}

	// multiply by scale and add reserve
	retVal.width = 10.0f + retVal.width * scale;
	retVal.height = 10.0f + retVal.height * scale;

	return retVal;
}

SvgGenerator::SIZE SvgGenerator::optimalNodeLabelPosition(const Node* node, float offset) {
	// get list of edge angles
	vector<float> angles;
	float x, y;
	for (Node::EdgeList::const_iterator pos = node->edges().begin();
			pos != node->edges().end();
			++pos
	) {
		// calculate x and y of vector to other node

		const Edge *e = *pos;

		if (!e->isOn()) continue;

		if (e->first() == node) {
			x = e->second()->x() - node->x();
			y = e->second()->y() - node->y();
		} else {
			x = e->first()->x() - node->x();
			y = e->first()->y() - node->y();
		}

		float angl = atan2f(y, x);
		angles.push_back(angl);
	}

	// check angle count
	float optimalAngle;

	if (angles.size() == 0) {
		optimalAngle = PI * 1.5;
	} else if (angles.size() == 1) {
		float t = angles[0];
		optimalAngle = angles[0] + PI;
	} else {
		// order angles
		sort(angles.begin(), angles.end());

		// search for the biggest gap
		float maxGap = 0;
		int gapIndex = 0;
		angles.push_back(angles[0]);

		int maxI = angles.size() - 1;

		for (int i = 0; i < maxI; ++i) {
			float currGap = fabsf(angles[i] - angles[i + 1]);

			if (currGap > maxGap) {
				maxGap = currGap;
				gapIndex = i;
			}
		}

		// calculate optimal angle
		optimalAngle = angles[gapIndex] + maxGap / 2.0f;
	}

	// calculate position
	SIZE retVal;

	retVal.width = cosf(optimalAngle) * offset;
	retVal.height = sinf(optimalAngle) * offset;

	return retVal;
}

string SvgGenerator::drawLabels(const NodeContainer* container, float scale) {
	string retVal;

	// iterate over nodes
	int index = 1;
	char buffer[BUFFER_SIZE];

	for (NodeContainer::NodeList::const_iterator pos = container->nodes().begin();
			pos != container->nodes().end();
			++pos
	) {
		//if (index != 7) { 	++index; continue; }
		Node *node = *pos;
		SIZE position = optimalNodeLabelPosition(node, NODE_ID_OFFSET);

		float x = node->x() * scale - 3 + position.width;
		float y = node->y() * scale - 3 + position.height;

		sprintf(buffer, LABEL_TEMPLATE, x, y, index);

		retVal += buffer;
		++index;
	}

	return retVal;
}

string SvgGenerator::generateSvg(const NodeContainer* container) {
	// add doctype
	float scale = 5.0f;
	string retVal;
	docType(retVal);

	// read node icon definition
	string defs = loadTemplates();

	// generate graphic data
	string nodes = drawNodes(container, scale);
	string edges = SvgGenerator::edges(container, scale);
	string labels = drawLabels(container, scale);

	// get size of image (maximum size)
	SIZE docSize = size(container, scale);
	float maxSize = (docSize.width > docSize.height) ? docSize.width : docSize.height;

	char buffer[128];

	ParamMap params;

	// create size string
	sprintf(buffer, "%f", docSize.width + 20);
	string strSize(buffer);

	// create offset Y string
	sprintf(buffer, "%f", docSize.width + 10);
	string strTranslate(buffer);

	params["transform"] = "translate(0,-" + strTranslate + ")";

	// merge nodes and edges to one group and transform it
	string graphicData = edges + nodes + labels;
	string translated = wrap(graphicData, TAG_GROUP, params);

	params.clear();
	params["transform"] = "scale(1,-1)";
	string transformed = wrap(translated, TAG_GROUP, params);

	params.clear();

	params["width"] = strSize;
	params["height"] = strSize;

	params["xmlns:xlink"] = "http://www.w3.org/1999/xlink";
	params["xmlns:dc"] = "http://purl.org/dc/elements/1.1/";
	params["xmlns:cc"] = "http://creativecommons.org/ns#";
	params["xmlns:rdf"] = "http://www.w3.org/1999/02/22-rdf-syntax-ns#";
	params["xmlns:svg"] = "http://www.w3.org/2000/svg";
	params["xmlns"] = "http://www.w3.org/2000/svg";
	params["xmlns:sodipodi"] = "http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd";
	params["style"] = "fill-color:ffffff; fill-opacity: 1;";

	retVal += wrap(defs + transformed, TAG_SVG, params);

	return retVal;
}

} /* namespace Visualiser */
