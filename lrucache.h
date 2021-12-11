/**
 * Marvin Manese
 * 79 ms solution (better than 92.38%)
 **/
 
#include <memory>
#include <unordered_map>
#include <utility>

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
class LRUCache
{
public:
    LRUCache(LRUCache* ptr) :
        LRUCache(ptr ? std::move(*ptr) : LRUCache())
    {
        delete ptr;
    }

    explicit LRUCache(int capacity = 1) :
        m_begin(nullptr),
        m_end(nullptr),
        m_capacity(capacity),
        m_count(0)
    {
        m_valueHash.reserve(capacity);
    }

    int get(int key)
    {
        auto find_it = m_valueHash.find(key);
        if(find_it == m_valueHash.end())
            return -1;

        IntNodePairPtr new_ptr = &(*(find_it));
        int ret = new_ptr->second.value;
        reinsertPointer(new_ptr);

        return ret;
    }

    void put(int key, int value)
    {
        auto find_it = m_valueHash.find(key);
        if(find_it != m_valueHash.end()) {
            m_valueHash.at(key).value = value;
            reinsertPointer(&(*find_it));
            return;
        }

        auto new_it = m_valueHash.emplace(key, value);
        insertBackOfList(&(*(new_it.first)));
    }

private:
    struct Node;
    typedef std::pair<const int, Node>* IntNodePairPtr;

    struct Node
    {
        Node(int v) : value(v), next(nullptr), prev(nullptr) {}
        Node(int v, IntNodePairPtr n, IntNodePairPtr p) : value(v), next(n), prev(p) {}

        int value;
        IntNodePairPtr next;
        IntNodePairPtr prev;
    };

    typedef std::unordered_map<int, Node>   HashType;

    void insertBackOfList(IntNodePairPtr ptr)
    {
        if(!m_begin) {
            // Set the begin and end to the new ptr
            m_begin = m_end = ptr;

            // Increment count;
            ++m_count;
        } else {
            if(m_count < m_capacity) {
                // Put the ptr to back
                connect(m_end, ptr);
                m_end = ptr;

                // Increment count
                ++m_count;
            } else {
                int key_to_remove = m_begin->first;

                // Disconnect the beginning of list
                IntNodePairPtr ne = m_begin->second.next;
                disconnect(m_begin);
                m_begin = ne;

                // Remove the key
                m_valueHash.erase(key_to_remove);

                // Put the ptr to back
                connect(m_end, ptr);
                m_end = ptr;
            }
        }
    }

    void reinsertPointer(IntNodePairPtr ptr)
    {
        if(m_end == ptr)
            return;

        if(m_begin == ptr) {
            m_begin = ptr->second.next;
            if(!m_begin)
                m_begin = ptr;
        }

        disconnect(ptr);
        connect(m_end, ptr);
        m_end = ptr;
    }

    void connect(IntNodePairPtr ptr, IntNodePairPtr node_ptr)
    {
        ptr->second.next = node_ptr;
        node_ptr->second.prev = ptr;
    }

    void disconnect(IntNodePairPtr ptr)
    {
        Node& val = ptr->second;
        IntNodePairPtr next = val.next;
        IntNodePairPtr prev = val.prev;

        if(next)
            next->second.prev = prev;
        if(prev)
            prev->second.next = next;
    }

    IntNodePairPtr  m_begin;
    IntNodePairPtr  m_end;
    HashType        m_valueHash;
    int             m_capacity;
    int             m_count;
};
