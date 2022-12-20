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
			DeleteWithEntityID(entityID);

			m_NextID++;
			m_Components.emplace_back(C(entityID));

			return &m_Components[m_Components.size() - 1];
		}

		C* GetWithEntityID(const unsigned int id)
		{
			int index = GetComponentIndex(id);
			if (index == -1) return nullptr;

			return &m_Components[index];
		}

		void DeleteWithEntityID(const unsigned int id)
		{
			int index = GetComponentIndex(id);
			if (index == -1) return;

			m_Components.erase(m_Components.begin() + index);
		}

		std::vector<C>* GetAll()
		{
			return &m_Components;
		}

		unsigned int GetCount()
		{
			return m_Components.size();
		}

	private:

		int GetComponentIndex(const unsigned int id)
		{
			unsigned int low = 0;
			unsigned int high = m_Components.size();

			while (low <= high)
			{
				unsigned int mid = low + (high - low) / 2;

				if (mid >= m_Components.size()) return -1;

				if (m_Components[mid].GetEntityID() == id) return mid;
				if (m_Components[mid].GetEntityID() <  id) low = mid + 1;
				else high = mid - 1;
			}

			return -1;
		}


		std::vector<C> m_Components;
		unsigned int m_NextID;

	};
}
