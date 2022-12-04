#pragma once

namespace ME
{
	class ComponentRef
	{
	public:

		ComponentRef();
		ComponentRef(unsigned int entityID);
		
		unsigned int GetEntityID();

	private:

		unsigned int m_EntityID;
		
	};
}

