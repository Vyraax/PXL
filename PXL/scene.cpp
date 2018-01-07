#include "scene.h"

Scene::Scene(const std::string& name)
{
	m_name = name;
	m_clearColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	m_fogColor = glm::vec3(0.01f, 0.02f, 0.03f);
	m_fogGradient = 1.5f;
	m_fogDensity = 0.009f;
}

void Scene::addMesh(Mesh* mesh)
{
	m_meshes.emplace_back(mesh);
}

void Scene::addText(Text* text)
{
	m_texts.emplace_back(text);
}

void Scene::addCamera(Camera* camera)
{
	m_cameras.emplace_back(camera);
	m_activeCamera = m_cameras.size() - 1;
}

void Scene::addLight(Light* light)
{
	m_lights.emplace_back(light);
}

void Scene::removeMesh(Mesh* mesh) {
	m_meshes.erase(std::remove(m_meshes.begin(), m_meshes.end(), mesh), m_meshes.end());
}

Mesh* Scene::getMeshByName(const std::string name)
{
	for (unsigned int i = 0; i < m_meshes.size(); i++) {
		if (m_meshes[i]->getName() == name)
			return m_meshes[i];
	}

	return nullptr;
}

Scene::~Scene()
{

}