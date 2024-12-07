// // #include <iostream>
// // #include <fstream>
// // #include <array>
// // #include <list>
// // using namespace std;

// // class Test
// // {
// //     public:
// //         int integer;
// //         bool TF;
// //         array<int, 3> arrays;
// //         queue<int> historic;
// //         inline Test(array<int, 3>& arrays, queue<int> queue) : integer(10), TF(true), arrays(arrays), historic(queue){};
// //         inline Test() : integer(10), TF(true){};
// // };

// // // int main(){
// // //     ofstream ifs;
// // //     ifs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
// // //     ifs.close();
// // //     array<int, 3> myNum{10, 20, 30};
// // //     queue<int> queue;
// // //     queue.push(10);
// // //     Test tests = *(new Test(myNum, queue));
// // //     // ofstream output("test.txt");
// // //     // if (output.is_open())
// // //     // {
// // //     //     output << ((char*)&tests, sizeof(tests));
// // //     //     output.close();
// // //     // }

// // //     ifs.write((char*)&tests, sizeof(tests));
// // //     ifstream ofs;
// // //     ofs.open("test.txt", ifstream::out);
// // //     ofs.seekg(0);
// // //     Test test3;
// // //     ofs.read((char*)&test3,sizeof(test3));
// // //     // std::string s;
// // //     // std::fstream f;
// // //     // f.open("wordlist.txt");
// // //     // std::getline(f, s);
// // //     // std::cout << s << "\n";
// // //     return 0;
// // // }

// // int main () {
// //     ofstream ifs;
// //     ifs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
// //     ifs.close();

// //     array<int, 3> myNum{10, 20, 30};
// //     queue<int> queue;
// //     queue.push(10);
// //     Test* test1 = new Test(myNum, queue);
// //     list<Test*> queueT;
// //     queueT.push_front(test1);

// //     int count = 0;
// //     Test one[queueT.size()];
// // 	list<Test*>::iterator it(queueT.begin());
// // 	while (it!=queueT.end()){
// // 		one[count] = **(it++);
// //         count ++;
// // 	}
    
// //     array<int, 3> myNums{8, 34, 5};
// //     test1 = new Test(myNums, queue);
// //     ifs.open("test.txt", ios::app);
// //     const char* length = (to_string(queueT.size()).c_str());
// //     ifs.write((char*)&one, sizeof(one));
// //     ifs.close();

// //     ifstream ofs;
// //     streampos begin,end;
// //     ofs.open("test.txt", ifstream::out);
// //     begin = ofs.tellg();
// //     ofs.seekg(0, ios::end);
// //     end = ofs.tellg();

// //     Test two[queueT.size()];
// //     ofs.read((char*)& queueT, begin - end);
// //     ofs.close();
// // }

// #include <iostream>
// #include <fstream>
// #include <stdio.h>
// #include <string.h>

// using namespace std;
// // Class to define the properties
// class Employee {
// public:
//    string Name;
//    int Employee_ID;
//    int Salary;
// };

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
   vector<int> nums;
   nums.push_back(0);
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(2);
   nums.push_back(4);
   nums.push_back(0);
   nums.push_back(3);
   nums.push_back(2);
   int val = 2;
   int returns = nums.size();
   bool end = true;
   while(end){
      int start = nums.size();
      if((find(nums.begin(), nums.end(), val)) != nums.end()){
         nums.erase(find(nums.begin(), nums.end(), val));
      }
      if(start == nums.size()){
            end = false;
      }
   }
   int t = 1;
}

