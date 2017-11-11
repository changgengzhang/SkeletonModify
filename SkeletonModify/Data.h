#pragma once

#include <QObject>
#include <QString>
#include <QVector>

#include <glm/glm.hpp>

class Data : public QObject
{
	Q_OBJECT

public:
	Data(QObject *parent=nullptr);
	~Data();
	void saveDataToFile(QString filePath="");
	void calProjectionPoint(int index);

public slots:
	void acceptConfigureFilePath(QString configureFilePath);

private:
	void parseDataPath();
	void parseConfigureFile();
	void parseJointsDataFile();

public:
	// 数据是否加载好
	bool m_isvalid;
	// 帧数
	uint m_frameCount;
	// 所有帧的关节点数据
	QVector<QVector<glm::vec3>> m_jointsData;
	// 存储修改后的关节点数据
	// QVector<QVector<glm::vec3>> m_modifiedJointsData;
	// Frame 的路径，为了加载Frame
	QString m_frameBasePath;

private:
	// 加载数据的路径
	QString m_configureFilePath;
	QString m_baseDir;
	QString m_jointsFilePath;
};
