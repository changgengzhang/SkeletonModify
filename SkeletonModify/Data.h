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
	// �����Ƿ���غ�
	bool m_isvalid;
	// ֡��
	uint m_frameCount;
	// ����֡�Ĺؽڵ�����
	QVector<QVector<glm::vec3>> m_jointsData;

	// �����ĳ���
	QVector<float> m_bonesLen;
	
	// Frame ��·����Ϊ�˼���Frame
	QString m_frameBasePath;

private:
	// �������ݵ�·��
	QString m_configureFilePath;
	QString m_baseDir;
	QString m_jointsFilePath;
};
