#include <iostream>
#include <string>
#include <vector>
#include <list>


template <class T>
void print(std::list<T> &data, const std::string &label) {
  std::cout << label << " ";
  for (typename std::list<T>::iterator p=data.begin(); p != data.end(); p++) {
    std::cout << " " << *p;
  }
  std::cout << std::endl;
}


template <class T>
void reverse(std::list<T> &data) {
  T temp;
  typename std::list<T>::iterator itr1 = data.begin();
  typename std::list<T>::iterator itr2 = data.end();
  int count = data.size()-1;
  while (count != 0){
    temp = data.front();
    data.pop_front();
    itr2 = data.insert(itr2,temp);
    count--;
  }

}



int main() {
  std::list<int> data;
  data.push_back(1);
  //data.push_back(2);
  //data.push_back(3);
  //data.push_back(4);
  //data.push_back(5);
  //data.push_back(6);
  //data.push_back(7);

  print(data,"before:");
  reverse(data);
  print(data,"after: ");

  std::list<std::string> data2;
  data2.push_back("apple");
  data2.push_back("banana");
  data2.push_back("carrot");
  data2.push_back("date");

  print(data2,"before:");
  reverse(data2);
  print(data2,"after: ");
}