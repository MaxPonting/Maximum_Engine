#pragma once

#include <vector>


namespace ME
{
	template <class C>
	class ComponentContainer
	{
	public:

		ComponentContainer() :
			m_NextID(0)
		{}

		ComponentContainer(int reserve) :
			m_NextID(0)
		{
			m_Components.reserve(reserve);
		}

		C* operator[](const int index)
		{
			if (index >= m_Components.size()) return nullptr;

			return &m_Components[index];
		}

		C* Add(int entityID)
		{
			m_NextID++;
			m_Components.emplace_back(C(entityID, m_NextID));

			return &m_Components[m_Components.size() - 1];
		}

		void Delete(const int index)
		{
			if (index >= m_Components.size()) return;

			m_Components.erase(m_Components.begin() + index);
		}

		unsigned int GetCount()
		{
			return m_Components.size();
		}

	private:

		std::vector<C> m_Components;
		unsigned int m_NextID;

	};
}
