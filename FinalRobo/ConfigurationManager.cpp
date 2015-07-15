/*
 * ConfigurationManager.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: colman
 */

#include "ConfigurationManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

ConfigurationManager::ConfigurationManager() {
	// TODO Auto-generated constructor stub

}
void ReadConfigurationFile(Robot* rob)
{
	//config.txt
	//Input name = image1.png
	//Num. of rows = 100
	//Num. of cols = 150


	std::string ipName;
	double nR, nC;
	std::string mapName;
	std::ifstream fin("parameters.txt");
	std::string line;
	std::istringstream sin;

	while (std::getline(fin, line)) {
	 sin.str(line.substr(line.find(":")+1));
	 //if (line.find("Input name") != std::string::npos) {
	  //std::cout<<"Input name "<<sin.str()<<std::endl;
	  //sin >> ipName;
	 //}
	 if (line.find("map") != std::string::npos) {
	  sin >> mapName;
	  rob->mapName = mapName.c_str();
	  std::cout<<"Input name "<<mapName<<std::endl;
	 }
	 else if (line.find("MapResolutionCM") != std::string::npos) {
	  sin >> rob->mapResolution;
	 }
	 else if (line.find("GridResolutionCM") != std::string::npos) {
		  sin >> rob->gridResolution;
	 }
	 else if (line.find("startLocation") != std::string::npos) {
		 sin >> rob->startX >> rob->startY >> rob->startYaw;
	 }
	 else if (line.find("robotSize") != std::string::npos) {
		 sin >> rob->robotWidth >> rob->robotLengt;
	 }
	 else if (line.find("goal") != std::string::npos) {
		 sin >> rob->goalX >> rob->goalY;
	 }
	 //sin.clear();
	}
	rob->totalResolution = (rob->gridResolution / rob->mapResolution);
	fin.close();
}


ConfigurationManager::~ConfigurationManager() {
	// TODO Auto-generated destructor stub

}

