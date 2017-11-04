#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


static const char* skeletonVertexShaderFile = "./skeletonShader.vert";
static const char* skeletonFragShaderFile = "./skeletonShader.frag";

static const char* backdropVertexShaderFile = "./backdropShader.vert";
static const char* backdropFragShaderFile = "./backdropShader.frag";

// 16:9
static const float RenderViewWidth = 960.0f;
static const float RenderViewHeight = 540.0f;

static const float BaseViweWidth = 16.0f;
static const float BaseViweHeight = 9.0f;

static const float Fov = 45.0f;

static const int JointsNumber = 21;

// …„œÒª˙Œª÷√
static glm::mat4 ViewMat = glm::lookAt(glm::vec3(0.0f, 0.0f, 4.7f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
static glm::mat4 ProjMat = glm::perspective(Fov, BaseViweWidth / BaseViweHeight, 0.1f, 100.f);