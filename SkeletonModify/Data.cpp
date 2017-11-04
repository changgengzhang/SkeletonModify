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

	std::ofstream ofs;
	Json::FastWriter writer;
	Json::Value root;

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
		root.append(onePeopleJoints);
	}

	std::string json_file = writer.write(root);

	ofs << json_file;
	ofs.close();
}


//////////////////////////////////////////////////////////////////////////
// 根据配置文件解析数据文件路径
void Data::parseDataPath()
{
	if (!m_isvalid)
		return;

	m_baseDir = m_configureFilePath.section('/', 0, -2);
	// 3d 数据点文件  ../Data/joints3d.json
	m_jointsFilePath = m_baseDir + "/joints3d.json";
	// frame 文件  ../Data/frame/frame_%06d.jpg
	m_frameBasePath = m_baseDir + "/frame/frame_%1.jpg";
	//m_frameBasePath = m_frameBasePath.arg(2, 6, 10, QLatin1Char('0'));
}


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
}


void Data::parseJointsDataFile()
{
	if (!m_isvalid)
		return;

	// 帧数
	m_jointsData.resize(m_frameCount);

	std::ifstream ifs;
	Json::Reader reader;
	Json::Value root;

	ifs.open(m_jointsFilePath.toStdString());
	assert(ifs.is_open());
	if (!reader.parse(ifs, root, false)) {
		return;
	}

	for (uint i = 0; i < m_frameCount; i++)
	{
		Json::Value oneFrame = root[i];
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
	this->parseDataPath();
	this->parseConfigureFile();
	this->parseJointsDataFile();
}