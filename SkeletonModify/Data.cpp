#include "Data.h"
#include "json.h"
#include "Utils.h"

#include <fstream>

Data::Data(QObject *parent)
	: QObject(parent)
{
	m_isvalid = false;
}

Data::~Data()
{
}

void Data::saveDataToFile(QString filePath)
{
	if (!m_isvalid)
		return;

	std::ifstream ifs;
	Json::Reader reader;
	Json::Value root;

	ifs.open(m_jointsFilePath.toStdString());
	assert(ifs.is_open());
	if (!reader.parse(ifs, root, false)) {
		return;
	}
	ifs.close();

	std::ofstream ofs;
	Json::FastWriter writer;
	Json::Value data;
	
	ofs.open(m_jointsFilePath.toStdString(), std::ios::trunc);
	assert(ofs.is_open());
	
	for (uint i = 0; i < m_jointsData.count(); i++)
	{
		Json::Value onePeopleJoints;
		//onePeopleJoints.append(m_jointsData[i].constData());
		for (int j = 0; j < JointsNumber; j++)
		{
			onePeopleJoints.append(m_jointsData[i][j].x);
			onePeopleJoints.append(m_jointsData[i][j].y);
			onePeopleJoints.append(m_jointsData[i][j].z);
			
		}
		data.append(onePeopleJoints);
		
	}

	root["position"] = data;
	std::string json_file = writer.write(root);

	ofs << json_file;
	ofs.close();
}


//////////////////////////////////////////////////////////////////////////
void Data::parseConfigureFile()
{
	if (!m_isvalid)
		return;

	std::ifstream ifs;
	Json::Reader reader;
	Json::Value root;

	ifs.open(m_configureFilePath.toStdString());
	assert(ifs.is_open());
	if (!reader.parse(ifs, root, false)) {
		return;
	}

	m_frameCount = root["frameCount"].asUInt();
	m_frameBasePath = QString(root["frameFolderPath"].asCString()) + "//frame_%1.jpg";
	m_jointsFilePath = root["positionFilePath"].asCString();

}


void Data::parseJointsDataFile()
{
	if (!m_isvalid)
		return;

	// Ö¡Êý
	m_jointsData.resize(m_frameCount);

	std::ifstream ifs;
	Json::Reader reader;
	Json::Value root;

	ifs.open(m_jointsFilePath.toStdString());
	assert(ifs.is_open());
	if (!reader.parse(ifs, root, false)) {
		return;
	}
	Json::Value data = root["position"];
	for (uint i = 0; i < m_frameCount; i++)
	{
		Json::Value oneFrame = data[i];
		QVector<glm::vec3> oneFrameData;
		for (uint j = 0; j < JointsNumber; j++)
		{
			Json::Value x = oneFrame[j * 3 + 0];
			Json::Value y = oneFrame[j * 3 + 1];
			Json::Value z = oneFrame[j * 3 + 2];

			oneFrameData.append(glm::vec3(x.asFloat(), y.asFloat(), z.asFloat()));
		}

		m_jointsData[i] = oneFrameData;
	}
}


//////////////////////////////////////////////////////////////////////////
// slots

void Data::acceptConfigureFilePath(QString configureFilePath)
{
	m_isvalid = true;
	m_configureFilePath = configureFilePath;
	this->parseConfigureFile();
	this->parseJointsDataFile();
}