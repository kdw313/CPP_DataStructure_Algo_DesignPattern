template <typename T>
class HashNode
{
  public:
    HashNode() : m_key(-1) {}
    ~HashNode() {}

    int GetKey() 
    { 
        return m_key;
    }

    void SetKey(int k)
    {
         m_key = k;
    }
    
    T GetObj() 
    { 
        return m_obj; 
    }
    
    void SetObj(T obj) 
    {
         m_obj = obj;
    }

    bool operator==(HashNode &item)
    {
        if (m_key == item.GetKey())
            return true;
            
        return false;
    }
    
    void operator=(HashNode item)
    {
        m_key = item.GetKey();
        m_obj = item.GetObject();
    }

  private:
    int m_key;
    T m_obj;
};
