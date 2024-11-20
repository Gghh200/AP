#include <iostream>
#include <fstream>
#include <array>
#include <queue>
#include <list>
using namespace std;

class Test
{
    public:
        int integer;
        bool TF;
        array<int, 3> arrays;
        queue<int> historic;
        inline Test(array<int, 3>& arrays, queue<int> queue) : integer(10), TF(true), arrays(arrays), historic(queue){};
        inline Test() : integer(10), TF(true){};
};
int main(){
    ofstream ifs;
    ifs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
    ifs.close();
    array<int, 3> myNum{10, 20, 30};
    queue<int> queue;
    queue.push(10);
    Test* test1 = new Test(myNum, queue);
    list<Test*> queueT;
    queueT.push_front(test1);

    int count = 0;
    Test one[queueT.size()];
	list<Test*>::iterator it(queueT.begin());
	while (it!=queueT.end()){
		one[count] = **(it++);
        count ++;
	}
    ifs.open("test.txt", ios::app);
    const char* length = (to_string(queueT.size()).c_str());
    ifs.write((char*)&one, sizeof(one));
    ifs.close();
    ifstream ofs;
    streampos begin,end;
    ofs.open("test.txt", ifstream::out);
    begin = ofs.tellg();
    ofs.seekg(0, ios::end);
    end = ofs.tellg();
    Test two[queueT.size()];
    ofs.read((char*)&two, begin - end);
    ofs.close();
    return 0;
}
// int main () {
//     ofstream ifs;
//     ifs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
//     ifs.close();
//     ifs.open("test.txt", ios::app);
//     array<int, 3> myNum{10, 20, 30};
//     queue<int> queue;
//     queue.push(10);
//     test* test1 = new test(myNum, queue);
//     myNum[0] = 20;
//     test test2 = *test1;
//     ifs.write((char*)&test2, sizeof(test2));
//     ifs.close();
//     ifstream ofs;
//     ofs.open("test.txt", ifstream::out);
//     ofs.seekg(0);
//     test test3;
//     ofs.read((char*)&test3,sizeof(test3));
//     ofs.close();
//     return 0;
// }

