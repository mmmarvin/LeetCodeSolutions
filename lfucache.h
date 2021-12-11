/**
 * Marvin Manese
 * 86 ms solution (better than 94.97%)
 **/

#include <list>
#include <memory>
#include <unordered_map>
#include <utility>

class LFUCache
{
public:
    LFUCache(LFUCache* ptr) :
        LFUCache(ptr ? std::move(*ptr) : LFUCache())
    {
        delete ptr;
    }

    explicit LFUCache(int capacity = 1) :
        m_leastFrequent(1),
        m_capacity(capacity),
        m_count(0)
    {
        m_valueHash.reserve(capacity);
    }

    int get(int key)
    {
        if(!m_capacity)
            return -1;

        auto find_it = m_valueHash.find(key);
        if(find_it == m_valueHash.end())
            return -1;

        Value& v = (*find_it).second;
        auto& p = (*v.iterator);
        int freq = p.first;
        CountListType& l = p.second;
        int ret = v.value;

        // Remove old count iterator
        l.erase(v.literator);

        // Update freq
        int new_freq = freq + 1;
        if(freq == m_leastFrequent && l.empty())
            m_leastFrequent = new_freq;

        // Readd
        auto lp = addToCount(new_freq, key);
        v.iterator = lp.first;
        v.literator = lp.second;

        return ret;
    }

    void put(int key, int value)
    {
        if(!m_capacity)
            return;

        auto find_it = m_valueHash.find(key);
        if(find_it != m_valueHash.end()) {
            Value& v = (*find_it).second;
            auto& p = (*v.iterator);
            int freq = p.first;
            CountListType& l = p.second;

            // Update the value, and remove old count iterator
            v.value = value;
            l.erase(v.literator);

            // Update freq
            int new_freq = freq + 1;
            if(freq == m_leastFrequent && l.empty())
                m_leastFrequent = new_freq;

            // Readd
            auto lp = addToCount(new_freq, key);
            v.iterator = lp.first;
            v.literator = lp.second;
        } else {
            if(m_count >= m_capacity) {
                // Remove least frequent
                int key_to_remove = (*m_countHash.at(m_leastFrequent).begin());
                Value& v = m_valueHash.at(key_to_remove);

                CountListType& l = (*v.iterator).second;
                l.erase(v.literator);
                m_valueHash.erase(key_to_remove);
            } else
                ++m_count;

            const int new_lf = 1;
            auto p = m_valueHash.emplace(key, value);
            auto it = (p.first);
            Value& v = (*it).second;
            auto lp = addToCount(new_lf, key);
            v.iterator = lp.first;
            v.literator = lp.second;
            m_leastFrequent = new_lf;
        }
    }

private:
    typedef std::list<int>                                          CountListType;
    typedef CountListType::iterator                                 CountListIteratorType;
    typedef std::unordered_map<int, CountListType>                  CountHashType;
    typedef CountHashType::iterator                                 CountHashIteratorType;
    typedef std::pair<CountHashIteratorType, CountListIteratorType> CountIteratorsPair;

    struct Value
    {
        Value(int v) : value(v) {}
        Value(int v, const CountHashIteratorType& it) : value(v), iterator(it) {}

        int                     value;
        CountListIteratorType   literator;
        CountHashIteratorType   iterator;
    };

    typedef std::unordered_map<int, Value> ValueHashType;

    CountIteratorsPair addToCount(int count, int key)
    {
        auto find_it = m_countHash.find(count);
        if(find_it != m_countHash.end()) {
            auto& l = (*find_it).second;
            l.push_back(key);
            CountListIteratorType lit = std::prev(l.end());
            return CountIteratorsPair(find_it, lit);
        }

        auto p = m_countHash.emplace(count, CountListType());
        auto it = p.first;
        auto& l = (*it).second;

        l.push_back(key);
        CountListIteratorType lit = std::prev(l.end());
        return CountIteratorsPair(it, lit);
    }

    ValueHashType   m_valueHash;
    CountHashType   m_countHash;
    int             m_leastFrequent;

    int             m_capacity;
    int             m_count;
};
