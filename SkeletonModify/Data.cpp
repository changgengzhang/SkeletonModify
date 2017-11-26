#include "Data.h"
#include "json.h"
#include "Utils.h"

#include <fstream>
#include <QMessageBox>

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
bool Data::parseConfigureFile()
{
	std::ifstream ifs;
	Json::Reader reader;
	Json::Value root;

	ifs.open(m_configureFilePath.toStdString());
	if (!ifs.is_open())
	{
		QMessageBox::warning(NULL, "Error", "Failed to open configure file");
		return false;
	}

	if (!reader.parse(ifs, root, false)) {
		return false;
	}

	m_frameCount = root["frameCount"].asUInt();
	m_frameBasePath = QString(root["frameFolderPath"].asCString()) + "/frame_%1.jpg";
	m_jointsFilePath = root["positionFilePath"].asCString();

	return true;
}


bool Data::parseJointsDataFile()
{
	// 帧数
	m_jointsData.resize(m_frameCount);

	std::ifstream ifs;
	Json::Reader reader;
	Json::Value root;

	ifs.open(m_jointsFilePath.toStdString());

	if (!ifs.is_open())
	{
		QMessageBox::warning(NULL, "Error", "Failed to open dance json file");
		return false;
	}
	
	if (!reader.parse(ifs, root, false)) {
		return false;
	}
	// 关节点位置
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
	// 骨骼长度
	data = root["bones_len"];
	m_bonesLen.resize(JointsNumber);
	for (uint i = 0; i < JointsNumber; i++)
	{
		m_bonesLen[i] = data[i].asFloat();
	}

	return true;
}

bool Data::loadData(QString configureFilePath)
{
	m_configureFilePath = configureFilePath;
	
	if (!this->parseConfigureFile())
	{
		m_isvalid = false;
		return false;
	}

	if (!this->parseJointsDataFile())
	{
		m_isvalid = false;
		return false;
	}
	// 复制一份数据到另一个文件夹，防止被覆盖
	if (m_jointsFilePath.contains("resize_bones"))
	{
		QString modifiedFilePath = m_jointsFilePath;
		modifiedFilePath.replace("resize_bones", "modified");
		// 原来的数据
		std::ifstream ifs;
		Json::Reader reader;
		Json::Value root;

		ifs.open(m_jointsFilePath.toStdString());

		if (!reader.parse(ifs, root, false)) {
			return false;
		}
		ifs.close();

		// 写入到新的文件中
		std::ofstream ofs;
		Json::FastWriter writer;
		std::string json_file;
		ofs.open(modifiedFilePath.toStdString(), std::ios::trunc);
		assert(ofs.is_open());
		json_file = writer.write(root);

		ofs << json_file;
		ofs.close();

		// 更改实际文件路径
		m_jointsFilePath = modifiedFilePath;

		// 更改配置文件
		ifs.open(m_configureFilePath.toStdString());
		
		if (!reader.parse(ifs, root, false)) {
			return false;
		}
		ifs.close();

		// 新的数据文件的地址
		Json::Value data;
		root["positionFilePath"] = m_jointsFilePath.toStdString();

		ofs.open(m_configureFilePath.toStdString(), std::ios::trunc);
		assert(ofs.is_open());
		json_file = writer.write(root);

		ofs << json_file;
		ofs.close();
	}

	// 数据有效
	m_isvalid = true;
	return true;
}