#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


static const char* skeletonVertexShaderFile = "./Shader/skeletonShader.vert";
static const char* skeletonFragShaderFile = "./Shader/skeletonShader.frag";

static const char* backdropVertexShaderFile = "./Shader/backdropShader.vert";
static const char* backdropFragShaderFile = "./Shader/backdropShader.frag";


static const char* sphereVertexShaderFile = "./Shader/sphereShader.vert";
static const char* sphereFragShaderFile = "./Shader/sphereShader.frag";

// 16:9
static const float RenderViewWidth = 960.0f;
static const float RenderViewHeight = 540.0f;

static const float BaseViweWidth = 16.0f;
static const float BaseViweHeight = 9.0f;

static const float Fov = 45.0f;

static const int JointsNumber = 16;

// 摄像机位置
static glm::vec3 ViewPos = glm::vec3(0.0f, 0.0f, 4.7f);
static glm::mat4 ViewMat = glm::lookAt(glm::vec3(0.0f, 0.0f, 4.7f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
static glm::mat4 ProjMat = glm::perspective(Fov, BaseViweWidth / BaseViweHeight, 0.1f, 100.f);


#include <QVector>
#include <QMap>

// 骨架连接方式  两两一组， 第一个是父节点
const QVector<uint> JointsConnIndex({
	14, 8, 8, 9, 9, 10,
	14, 11, 11, 12, 12, 13,
	14, 15, 15, 1, 1, 0,
	1, 2, 2, 3, 3, 4,
	1, 5, 5, 6, 6, 7
});

// 0号点对应的父亲节点是1号点
const static QVector<int> JointsParentIndex({
	1, 15,
	1,  2,  3,
	1,  5,  6,
	14,  8,  9,
	14, 11, 12,
	14, 14
});

// 0号点对应8号骨架，以此类推
const static QVector<int> BonesIndex({
	8, 7,
	9, 10, 11,
	12, 13, 14,
	0, 1, 2,
	3, 4, 5,
	-1, 6
});

const QVector< QVector<int> > JointsChildrenIndex({
	QVector<int>({ 0 }),
	QVector<int>({ 2, 3, 4, 5, 6, 7, 0 }),
	QVector<int>({ 3, 4 }),
	QVector<int>({ 4 }),
	QVector<int>({ 4 }),
	QVector<int>({ 6, 7 }),
	QVector<int>({ 7 }),
	QVector<int>({ 7 }),
	QVector<int>({ 9, 10 }),
	QVector<int>({ 10 }),
	QVector<int>({ 10 }),
	QVector<int>({ 12, 13 }),
	QVector<int>({ 13 }),
	QVector<int>({ 13 }),
	QVector<int>({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15 }),
	QVector<int>({ 0, 1, 2, 3, 4, 5, 6, 7 })
});




// 一些需要设置的值

#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QRadioButton>

class ChangeWidgets
{
public:
	QLabel *labelCurrFrame;
	QTextBrowser *textBrowserPositionValue;
	QLabel *labelStartSmoothFrame;
	QLabel *labelEndSmoothFrame;
	QLabel *labelCurrJoint;
	
	QRadioButton *radioButtonCopyFrame;
	QRadioButton *radioButtonSmooth;
};
