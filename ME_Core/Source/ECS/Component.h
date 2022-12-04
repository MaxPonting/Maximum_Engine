#pragma once

namespace ME
{
	class Component
	{
	public:

		Component();
		Component(const unsigned int entityID, const unsigned int componentID);

		unsigned int GetEntityID();
		unsigned int GetComponentID();

	private:

		unsigned int m_EntityID;
		unsigned int m_ComponentID;

	};
}

