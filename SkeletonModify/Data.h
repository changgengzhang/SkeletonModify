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
	bool loadData(QString configureFilePath);

private:
	bool parseConfigureFile();
	bool parseJointsDataFile();

public:
	// 数据是否加载好
	bool m_isvalid;
	// 帧数
	uint m_frameCount;
	// 所有帧的关节点数据
	QVector<QVector<glm::vec3>> m_jointsData;

	// 骨骼的长度
	QVector<float> m_bonesLen;
	
	// Frame 的路径，为了加载Frame
	QString m_frameBasePath;

private:
	// 加载数据的路径
	QString m_configureFilePath;
	QString m_baseDir;
	QString m_jointsFilePath;
};
