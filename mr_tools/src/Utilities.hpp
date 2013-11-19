/*
 * Utilities.hpp
 *
 *  Created on: Nov 11, 2013
 *      Author: blackpc
 */

#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <ros/ros.h>

using namespace std;

class Utilities {
public:

	static vector<string> getTopicNames(int robotsCount, string robotNsFormat, string topicName) {
		vector<string> topics;

		for (int i = 1; i < robotsCount + 1; i++) {
			string newTopicName = robotNsFormat + "/" + topicName;

			boost::replace_all(newTopicName, "{robotId}", boost::lexical_cast<string>(i));
			topics.push_back(newTopicName);
		}

		return topics;
	}

private:
};





#endif /* UTILITIES_HPP_ */
