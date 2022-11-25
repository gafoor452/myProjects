
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class PersistanceData{
public:
uint8_t *WriteBuffer;
uint8_t *ReadBuffer;

//TODO - remove the parameter length
void WriteDataToFile(const char* path, uint8_t length){
    ofstream filetoWrite;
    filetoWrite.open(path, ios::out);
    for(uint8_t i=0; i<length;i++)
        filetoWrite<<WriteBuffer[i];
    filetoWrite.close();

} 
//TODO - remove the parameter length 
T* ReadDataFromFile(const char* path, uint8_t length){
    ifstream filetoRead;
    memset(ReadBuffer, 0 , length);
    filetoRead.open(path,ios::in);
    for(uint8_t i=0; i<length;i++)
        filetoRead>>ReadBuffer[i];
    filetoRead.close();
    return reinterpret_cast<T*>(ReadBuffer);
}
PersistanceData(T* data){
    WriteBuffer = reinterpret_cast<uint8_t*>(data);
    ReadBuffer = new uint8_t [sizeof(uint8_t)*sizeof(T)];
    
}
~PersistanceData(){
    delete ReadBuffer;
}

PersistanceData(const PersistanceData&) = delete;
PersistanceData& operator=(const PersistanceData&) = delete;
};