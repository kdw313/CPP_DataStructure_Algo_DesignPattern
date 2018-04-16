template<class T>
class OrderedArray
{
    public:
    OrderedArray(int size, int growBy = 1) :
            m_array(NULL), m_maxSize(0),
            m_growSize(0), m_numElements(0)
    {
        if(size)
        {
            m_maxSize = size;
            m_array = new T[m_maxSize];
            memset(m_array, 0, sizeof(T) * m_maxSize);
            m_growSize = ((growBy > 0) ? growBy : 0);
        }
    }

    virtual ~OrderedArray()
    {
        if(m_array != NULL)
        {
            delete[] m_array;
            m_array = NULL;
        }
    }

    void push(T val)
    {
        assert(m_array != NULL);
        
        if(m_numElements >= m_maxSize)
        {
            Expand();
        }
        
        for(int i = 0; i < m_numElements; i++)
        {
            if(m_array[i] > val)
                break;
        }
        
        for(int k = m_numElements; k > i; k—)
        {
            m_array[k] = m_array[k - 1];
        }
        
        m_array[i] = val;
        m_numElements++;
    }
    
    void pop() {
        if(m_numElements > 0)
            m_numElements—;
    }
    
    void remove(int index)
    {
    assert(m_array != NULL);
    if(index >= m_maxSize)
    {
        return;
    }
    
    for(int k = index; k < m_maxSize - 1; k++)
        m_array[k] = m_array[k + 1];
    
    m_maxSize—;
    
    if(m_numElements >= m_maxSize)
        m_numElements = m_maxSize - 1;
    }

    // Making this const allows for reading but not writing.
    virtual const T& operator[](int index)
    {
        assert(m_array != NULL && index <= m_numElements);
        return m_array[index];
    }

    int search(T searchKey)
    {
        if(!m_array)
            return -1;
    
        int lowerBound = 0;
        int upperBound = m_numElements - 1;
        int current = 0;
    
        while(1) {
            current = (lowerBound + upperBound) >> 1;
            
            if(m_array[current] == searchKey)
            {
                return current;
            }
            else if(lowerBound > upperBound)
            {
                return -1;
            }
            else
            {
                if(m_array[current] < searchKey)
                    lowerBound = current + 1;
                else
                    upperBound = current - 1;
            } 
        }
        return -1;
    }

    void clear()
    {
        m_numElements = 0;
    }
    
    int GetSize()
    {
        return m_numElements;
    }

    int GetMaxSize() 
    {
        return m_maxSize;
    }
    
    int GetGrowSize()
    {
        return m_growSize;
    }
    
    void SetGrowSize(int val)
    {
        assert(val >= 0);
        m_growSize = val;
    }
    void Shellsort()
    {
        assert(m_array != NULL);

        T temp;
        int i = 0, k = 0;

        int seq = 1;

        while(seq <= m_numElements / 3)
        {
            seq = seq * 3 + 1;
        }


        while(seq > 0)
        {
            for ( k = seq; k < m_numElements; k++)
            {
                temp = m_array[k];
                i = k;

                while (i > seq -1 && m_array[i-seq] > temp)
                {
                    m_array[i] = m_array [i - seq];
                    i -= seq;
                }

                m_array[i] = temp;
            }
            
            seq = (seq - 1) / 3;
        }
    }
    
    private:
        bool Expand()
        {
            if(m_growSize <= 0)
                return false;
            T *temp = new T[m_maxSize + m_growSize];
            assert(temp != NULL);
            memcpy(temp, m_array, sizeof(T) * m_maxSize);
            delete[] m_array;
            m_array = temp;
            m_maxSize += m_growSize;
            return true;
        }
        
    private:
        T *m_array;
        int m_maxSize;
        int m_growSize;
        int m_numElements;
};
