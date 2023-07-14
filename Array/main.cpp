#include <iostream>

using namespace std;

template <typename T>
class Array
{
  unsigned int size;
  T *arr;

public:
  explicit Array(unsigned int size) : size{size}, arr{new T[size]}
  {
    for (int i = 0; i < size; i++)
    {
      arr[i] = T();
    }
  };
  Array() : size{0}, arr{nullptr} {};

  ~Array()
  {
    if (arr != nullptr)
    {
      delete[] arr;
      arr = nullptr;
    }
  };

  unsigned int GetSize() const { return size; }
  void SetSize(unsigned int size)
  {
    if (this->size == size)
    {
      return;
    }

    if (this->size < size)
    {
      T *newArr = new T[size];
      for (int i = 0; i < this->size; i++)
      {
        newArr[i] = this->arr[i];
      }
      delete [] arr;
      arr = newArr;
      this->size = size;
    }
    else
    {
      T *newArr = new T[size];
      for (int i = 0; i < size; i++)
      {
        newArr[i] = this->arr[i];
      }
      delete [] arr;
      arr = newArr;
      this->size = size;
    }
  };

  bool IsEmpty() const { return !this->size; };

  void Clear()
  {
    if (this->size == 0)
    {
      return;
    }
    this->size = 0;
    if (arr != nullptr)
    {
      delete[] arr;
      arr = nullptr;
    }
  };

  T &operator[](unsigned int indx)
  {
    if (indx <= size)
    {
      return arr[indx];
    }
    T temp = T();
    return temp;
  };

  Array &operator+(const Array &obj)
  {
    unsigned int size = obj.size + this->size;
    T *newArr = new T[size];
    int i = 0;
    for (; i < this->size; i++)
    {
      newArr[i] = arr[i];
    }
    for (int j = 0; j < size - this->size; j++)
    {
      newArr[i + j] = obj.arr[j];
    }
    delete[] arr;
    this->size = size;
    this->arr = newArr;
    return *this;
  };

  Array &operator+=(const T &el)
  {
    SetSize(this->size + 1);
    T *newArr = new T[this->size];

    for (int i = 0; i < this->size - 1; i++)
    {
      newArr[i] = arr[i];
    }

    newArr[this->size] = el;
    delete[] arr;
    arr = newArr;
    return *this;
  };

  Array &operator=(const Array &obj)
  {
    if (this != &obj)
    {
      delete[] arr;

      if (size != obj.size)
      {
        size = obj.size;
        arr = new int[size];
      }

      for (int i = 0; i < size; i++)
      {
        arr[i] = obj.arr[i];
      }
    }
    return *this;
  };

  friend ostream &operator<<(ostream &OUT, Array &obj)
  {
    for (int i = 0; i < obj.size; i++)
    {
      OUT << obj.arr[i] << " ";
    }
    OUT << endl;
    return OUT;
  };
};

int main()
{
  srand(time(NULL));
  Array<int> arr1(5);
  // Array<int> arr2(1);
  // cout << arr1 << endl;
  // arr1.SetSize(3);
  // cout << arr1 << endl;
  // cout << arr1.GetSize() << endl;
  // cout << arr1.IsEmpty() << endl;
  // arr1.Clear();
  // cout << arr1.IsEmpty() << endl;
  // cout << arr1[2] << endl;
  // arr1[2] = 1;
  // cout << arr1[2] << endl;
  // cout << "First: " << arr1;
  // cout << "Second: " << arr2;
  // Array<int> arr3;
  // arr3 = arr1 + arr2;
  // cout << "Third: " << arr3;

  return 0;
}