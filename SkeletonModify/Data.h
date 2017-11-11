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
	// �����Ƿ���غ�
	bool m_isvalid;
	// ֡��
	uint m_frameCount;
	// ����֡�Ĺؽڵ�����
	QVector<QVector<glm::vec3>> m_jointsData;
	// �洢�޸ĺ�Ĺؽڵ�����
	// QVector<QVector<glm::vec3>> m_modifiedJointsData;
	// Frame ��·����Ϊ�˼���Frame
	QString m_frameBasePath;

private:
	// �������ݵ�·��
	QString m_configureFilePath;
	QString m_baseDir;
	QString m_jointsFilePath;
};
