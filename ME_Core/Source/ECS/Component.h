#pragma once

namespace ME
{
	class Component
	{
	public:

		Component();
		Component(unsigned int entityID);

		unsigned int GetEntityID();
		
	private:

		unsigned int m_EntityID;

	};
}

