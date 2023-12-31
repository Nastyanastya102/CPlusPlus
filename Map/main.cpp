#include <iostream>

using namespace std;

template <typename K, typename V>
class Map
{
  K *keys;
  V *values;
  unsigned int size;

public:
  // explicit Map(unsigned int size) : size(size), keys{new K[size]}, values{new V[size]} {};
  Map() : size(0), keys{nullptr}, values{nullptr} {};
  ~Map()
  {
    if (keys != nullptr)
      delete[] keys;
    if (values != nullptr)
      delete[] values;
  };

  int find(const K &key) const
  {
    for (int i = 0; i < size; i++)
    {
      if (keys[i] == key)
        return i;
    }
    return -1;
  };

  void insert(const K &key, const V &value)
  {
    int newSize = size + 1;
    K *newKeys = new K[newSize];
    V *newValues = new V[newSize];
    if (size > 0)
    {
      for (int i = 0; i < size; i++)
      {
        newKeys[i] = keys[i];
        newValues[i] = values[i];
      }
    }

    newKeys[size] = key;
    newValues[size] = value;

    delete[] keys;
    delete[] values;
    size = newSize;
    keys = newKeys;
    values = newValues;
  };

  void remove(const K &key)
  {
    int index = find(key);
    if (index == -1 || size == 0)
    {
      cout << "Impossible to remove key because it doesn't exits" << endl;
      return;
    }

    int newSize = size - 1;
    if (newSize == 0)
    {
      cout << "Sucessfuly removed" << endl;
      size = newSize;
      delete[] keys;
      delete[] values;
      keys = nullptr;
      values = nullptr;
      return;
    }

    K *newKeys = new K[newSize];
    V *newValues = new V[newSize];

    for (int i = 0; i < index; i++)
    {
      newKeys[i] = keys[i];
      newValues[i] = values[i];
    }

    for (int i = index; i < newSize; i++)
    {
      newKeys[i] = keys[i + 1];
      newValues[i] = values[i + 1];
    }

    delete[] keys;
    delete[] values;
    size = newSize;
    keys = newKeys;
    values = newValues;
  };

  int count(const K &key) const
  {
    int count = 0;
    for (int i = 0; i < size; i++)
    {
      if (find(key) != -1)
      {
        count++;
      }
    }

    return count;
  }

  bool isEmpty(const Map &map) const { return map.size == 0; };

  int length() const { return size; };

  friend ostream &operator<<(ostream &OUT, const Map &map)
  {
    bool notEmpty = map.size;
    if (notEmpty)
    {
      for (int i = 0; i < map.size; i++)
        OUT << "Key: " << map.keys[i] << " | Value: " << map.values[i] << endl;
    }

    return OUT;
  }

  V &operator[](const K &key) const
  {
    int index = find(key);
    if (index == -1)
    {
      cout << "Key doesn't exist in map" << endl;
      return static_cast<V>(NULL);
      ;
    }

    return values[index];
  }
};

int main()
{
  cout << "INT, STRING" << endl;
  Map<int, string> m1;
  m1.insert(0, "value1");
  m1.insert(1, "value2");
  m1.insert(2, "value3");
  cout << m1 << endl;
  cout << "Length: " << m1.length() << endl;
  cout << "Index (-1 if not found): " << m1.find(2) << endl;
  m1.remove(1);
  cout << "Index (-1 if not found): " << m1.find(2) << endl;
  cout << m1 << endl;

  cout << "INT, INT" << endl;
  Map<int, int> m2;
  m2.insert(0, 0);
  m2.insert(1, 1);
  m2.insert(2, 2);
  cout << m2 << endl;
  cout << "Length: " << m2.length() << endl;
  cout << "Index (-1 if not found): " << m2.find(2) << endl;
  m2.remove(2);
  cout << "Index (-1 if not found): " << m2.find(2) << endl;

  cout << "INT, FLOAT" << endl;
  Map<int, float> m3;
  m3.insert(0, 0.0);
  m3.insert(1, 0.1);
  m3.insert(2, 0.2);
  cout << m3 << endl;
  cout << "Length: " << m3.length() << endl;
  cout << "Index (-1 if not found): " << m3.find(2) << endl;
  m3.remove(5);
  cout << "Index (-1 if not found): " << m3.find(2) << endl;
  return 0;
}