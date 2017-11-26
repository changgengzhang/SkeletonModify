#include "ArcBall.h"



ArcBall::ArcBall(float windowWidth, float windowHeight, float mouseSensitivity = 0.1)
{
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_adjustCoord = m_windowWidth < m_windowHeight ? m_windowWidth : m_windowHeight;
	m_mouseSensitivity = mouseSensitivity;


	m_angle = 0.0f;
	m_rotaryAxis = glm::vec3(0.0f, 1.0f, 0.0f);
	m_modelMat = glm::mat4(1.0f);
}


ArcBall::~ArcBall()
{
}


glm::vec3 ArcBall::mapToSphereCoord(float x, float y)
{
	glm::vec3 coord(0.0f, 0.0f, 0.0f);

	coord.x = (2 * x - m_windowWidth) / m_adjustCoord;
	coord.y = -(2 * y - m_windowHeight) / m_adjustCoord;

	coord.x = glm::clamp(coord.x, -1.0f, 1.0f);
	coord.y = glm::clamp(coord.y, -1.0f, 1.0f);

	float length = coord.x * coord.x + coord.y * coord.y;

	if (length <= 1.0f)
	{
		coord.z = sqrt(1.0f - length);
	}
	else
	{
		coord = glm::normalize(coord);
	}

	return coord;
}


void ArcBall::mousePressEvent(QMouseEvent *mouseEvent)
{
	float x = mouseEvent->x();
	float y = mouseEvent->y();
	m_preCoord = this->mapToSphereCoord(x, y);
}


void ArcBall::mouseReleaseEvent(QMouseEvent *mouseEvent)
{
	m_angle = 0.0f;
	m_rotaryAxis = glm::vec3(0.0f, 1.0f, 0.0f);
}


void ArcBall::mouseMoveEvent(QMouseEvent *mouseEvent)
{
	float x = mouseEvent->x();
	float y = mouseEvent->y();
	
	if (mouseEvent->buttons() & Qt::LeftButton)
	{
		m_currCoord = this->mapToSphereCoord(x, y);

		if (glm::length(m_preCoord - m_currCoord) < std::numeric_limits<float>::epsilon())
		{
			m_angle = 0.0f;
		}
		else
		{
			m_angle = acos(std::min(1.0f, glm::dot(m_currCoord, m_preCoord)));
			m_rotaryAxis = glm::cross(m_preCoord, m_currCoord);
		}
		m_preCoord = m_currCoord;
	}

	if (mouseEvent->buttons() & Qt::RightButton)
	{

	}

}

glm::mat4 ArcBall::getModelMatrix(glm::mat4& viewMatrix, glm::vec3 modelCenter)
{
	glm::vec3 axis = glm::inverse(glm::mat3(viewMatrix)) * m_rotaryAxis;
	//glm::vec3 axis = m_rotaryAxis;
	m_modelMat = glm::rotate(glm::degrees(m_angle) * m_mouseSensitivity * 0.1f, axis) * m_modelMat;
	
	glm::mat4 realModelMat =  glm::translate(glm::mat4(1.0f), modelCenter) * m_modelMat * glm::translate(glm::mat4(1.0f), -modelCenter);
	
	return realModelMat;
}


void ArcBall::reset()
{
	m_angle = 0.0f;
	m_rotaryAxis = glm::vec3(0.0f, 1.0f, 0.0f);
	m_modelMat = glm::mat4(1.0f);
}