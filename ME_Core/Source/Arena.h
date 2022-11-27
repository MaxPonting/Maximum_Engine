#pragma once
#include <vector>

//
// Container for objects.
// Stores objects on the stack.
// If object count reaches maximum size, new objects are allocated on the heap.
// 
// Template to set the Class of object and the count to be stored
template <class C, int size>
class Arena
{
public:
    /* Reserves space on for the object pointer vector. */
    Arena()
    {
        m_Pointers.reserve(size);
    }

    /* Allows access to containted objects */
    C& operator[](const int index)
    {
        if (index < m_Pointers.size())
        {
            return *m_Pointers[index];
        }
        else if (index < m_Pointers.size() + m_HeapObjects.size())
        {
            return m_HeapObjects[index - m_Pointers.size()];
        }
    }

    /* Adds an object to the stack or heap if the allocated memory is full. */
    void Add(C object)
    {
        if (m_FreeSpaces.empty())
        {
            if (pointer >= size)
            {
                m_HeapObjects.emplace_back(object);
                return;
            }
            else
            {
                m_StackObjects[pointer] = object;
                m_Pointers.push_back(&m_StackObjects[pointer]);
                pointer++;
                return;
            }
        }

        int space = m_FreeSpaces.front();
        m_FreeSpaces.pop_back();
        m_StackObjects[space] = object;
        m_Pointers.push_back(&m_StackObjects[space]);
        return;
    }

    /* Deletes an object either from the stack or the heap given an index. */
    void Delete(const int index)
    {
        if (index < m_Pointers.size())
        {
            C* address = m_Pointers[index];
            m_Pointers.erase(m_Pointers.begin() + index);
            int i = 0;
            for (i = 0; i < pointer; i++)
            {
                if (&m_StackObjects[i] == address)
                {
                    m_StackObjects[i] = C();
                    m_FreeSpaces.push_back(i);
                    return;
                }
            }
        }
        else if (index < m_Pointers.size() + m_HeapObjects.size())
        {
            m_HeapObjects.erase(m_HeapObjects.begin() + index - m_Pointers.size());
        }
    }

    /* Returns the count of allocated objects */
    int GetCount()
    {
        return m_Pointers.size() + m_HeapObjects.size();
    }
private:

    /* STACK ALLOCATION */
    C m_StackObjects[size];
    int pointer;
    std::vector<int> m_FreeSpaces;
    std::vector<C*> m_Pointers;

    /* HEAP ALLOCATION */
    std::vector<C> m_HeapObjects;

};





