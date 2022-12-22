#include "Camera.h"

namespace ME
{
	Camera::Camera() :
		ComponentRef()
	{}

	Camera::Camera(unsigned int id, ECS* ecs) :
		ComponentRef(id, ecs)
	{}

	void Camera::SetPosition(Vector2f pos)
	{
		if (p_ECS == nullptr) return;
		CameraComponent* camera = p_ECS->GetComponent<CameraComponent>(m_EntityID);
		if (camera == nullptr) return;
		camera->position = pos;
	}

	void Camera::SetScale(float scale)
	{
		if (p_ECS == nullptr) return;
		CameraComponent* camera = p_ECS->GetComponent<CameraComponent>(m_EntityID);
		if (camera == nullptr) return;
		camera->scale = scale;
	}

	Vector2f Camera::GetPosition()
	{
		if (p_ECS == nullptr) return Vector2f();
		CameraComponent* camera = p_ECS->GetComponent<CameraComponent>(m_EntityID);
		if (camera == nullptr) return Vector2f();
		return camera->position;
	}

	float Camera::GetScale()
	{
		if (p_ECS == nullptr) return 0;
		CameraComponent* camera = p_ECS->GetComponent<CameraComponent>(m_EntityID);
		if (camera == nullptr) return 0;
		return camera->scale;
	}
}
