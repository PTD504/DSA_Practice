#include <vector>
#include <functional>

// Unordered map is a data structure built based on the hash table data structure. 
// Due to its many practical applications, I will implement an unordered_map-like data structure, which is used to solve problems later on.

const int INITIAL_SIZE = 84;

template<typename K, typename V>
class UnorderedMap {
private:
    std::vector<std::pair<std::pair<K, V>, bool>> table;
    int capacity, size;

    int hashFunction1(const K& key) const;
    int hashFunction2(const K& key) const;

    void rehash();

public:
    UnorderedMap(int capacity = INITIAL_SIZE);
    void insert(const K& key, const V& value);
    bool search(const K& key) const;
    void remove(const K& key);
    V& operator[](const K& key);

    class Iterator {
    private:
        typename std::vector<std::pair<std::pair<K, V>, bool>>::iterator iter;
        typename std::vector<std::pair<std::pair<K, V>, bool>>::iterator endIter;
        
        void advance() {
            while (iter != endIter && !iter->second) {
                ++iter;
            }
        }

    public:
        Iterator(typename std::vector<std::pair<std::pair<K, V>, bool>>::iterator start,
                 typename std::vector<std::pair<std::pair<K, V>, bool>>::iterator end)
            : iter(start), endIter(end) {
            advance();
        }

        Iterator& operator++() {
            ++iter;
            advance();
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return iter != other.iter;
        }

        std::pair<K, V>& operator*() const {
            return iter->first;
        }
    };

    Iterator begin();
    Iterator end();
};

template<typename K, typename V>
UnorderedMap<K, V>::UnorderedMap(int capacity) : capacity(capacity), size(0) {
    table.resize(capacity, std::make_pair(std::make_pair(K(), V()), false));
}

template<typename K, typename V>
int UnorderedMap<K, V>::hashFunction1(const K& key) const {
    return std::hash<K>()(key) % capacity;
}

template<typename K, typename V>
int UnorderedMap<K, V>::hashFunction2(const K& key) const {
    return 1 + (std::hash<K>()(key) % (capacity - 1));
}

template<typename K, typename V>
void UnorderedMap<K, V>::rehash() {
    int newCapacity = 2 * capacity;
    std::vector<std::pair<std::pair<K, V>, bool>> newTable(newCapacity, std::make_pair(std::make_pair(K(), V()), false));

    for (const auto& entry : table) {
        if (entry.second) {
            int index = std::hash<K>()(entry.first.first) % newCapacity;
            int stepSize = 1 + (std::hash<K>()(entry.first.first) % (newCapacity - 1));

            while (newTable[index].second) {
                index = (index + stepSize) % newCapacity;
            }

            newTable[index] = entry;
        }
    }

    table = std::move(newTable);
    capacity = newCapacity;
}

template<typename K, typename V>
void UnorderedMap<K, V>::insert(const K& key, const V& value) {
    if (size >= capacity) {
        rehash();
    }
    
    // Using double hashing to handle collisions.

    int index = hashFunction1(key);
    int stepSize = hashFunction2(key);

    while (table[index].second) {
        if (table[index].first.first == key) {
            table[index].first.second = value; // Update the value if key already exists
            return;
        }
        index = (index + stepSize) % capacity;
    }

    table[index] = std::make_pair(std::make_pair(key, value), true);
    ++size;
}

template<typename K, typename V>
bool UnorderedMap<K, V>::search(const K& key) const {
    int index = hashFunction1(key);
    int stepSize = hashFunction2(key);
    int start = index;

    while (table[index].second) {
        if (table[index].first.first == key) {
            return true;
        }
        index = (index + stepSize) % capacity;
        if (index == start) {
            break;
        }
    }
    return false;
}

template<typename K, typename V>
void UnorderedMap<K, V>::remove(const K& key) {
    int index = hashFunction1(key);
    int stepSize = hashFunction2(key);
    int start = index;

    while (table[index].second) {
        if (table[index].first.first == key) {
            table[index].second = false;
            --size;
            return;
        }
        index = (index + stepSize) % capacity;
        if (index == start) {
            break;
        }
    }
}

template<typename K, typename V>
V& UnorderedMap<K, V>::operator[](const K& key) {
    int index = hashFunction1(key);
    int stepSize = hashFunction2(key);
    int start = index;

    while (table[index].second) {
        if (table[index].first.first == key) {
            return table[index].first.second;
        }
        index = (index + stepSize) % capacity;
        if (index == start) {
            break;
        }
    }

    // Insert a new entry with the default value if key not found
    if (size >= capacity) {
        rehash();
    }

    index = hashFunction1(key);
    stepSize = hashFunction2(key);

    while (table[index].second) {
        index = (index + stepSize) % capacity;
    }

    table[index] = std::make_pair(std::make_pair(key, V()), true);
    ++size;
    return table[index].first.second;
}

template<typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::begin() {
    return Iterator(table.begin(), table.end());
}

template<typename K, typename V>
typename UnorderedMap<K, V>::Iterator UnorderedMap<K, V>::end() {
    return Iterator(table.end(), table.end());
}
