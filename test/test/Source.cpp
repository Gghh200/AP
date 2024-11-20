#include <iostream>
#include <fstream>
using namespace std;

class test
{
    public:
        int integer;
        bool TF;
        int* array;
        inline test(int* array) : integer(10), TF(true), array(array){};
        inline test() : integer(10), TF(true), array(nullptr){};
};



int main () {
    ofstream ifs;
    ifs.open("test.txt", std::ofstream::out | std::ofstream::trunc);
    ifs.close();
    ifs.open("test.txt", ios::app);
    int myNum[3] = {10, 20, 30};
    test* test1 = new test(myNum);
    myNum[0] = 20;
    test test2 = *test1;
    ifs.write((char*)&test2, sizeof(test2) );
    ifs.close();
    ifstream ofs;
    ofs.open("test.txt", ifstream::out);
    ofs.seekg(0);
    test test3;
    ofs.read((char*)&test3,sizeof(test3));
    ofs.close();
    return 0;
}

// #include <fstream>
// #include <iostream>
// using namespace std;

// int main()
// {
//     // Creating an array of size 5
//     int arr[] = { 1, 2, 3, 4, 5 };
//     int size = sizeof(arr) / sizeof(arr[0]);

//     // Opening the file in write mode
//     ofstream outfile("test.txt");
//     if (!outfile.is_open()) {
//         cerr << "Failed to open file for writing.\n";
//         return 1;
//     }

//     // Writing the array elements to the file
//     for (int i = 0; i < size; ++i) {
//         outfile << arr[i] << " ";
//     }

//     // Closing the file
//     outfile.close();

//     // Opening the file in read mode
//     ifstream infile("test.txt");

//     int arr2[5];
//     // Reading the array elements from the file
//     for (int i = 0; i < size; ++i) {
//         infile >> arr2[i];
//     }

//     // Closing the file
//     infile.close();

//     return 0;
// }
