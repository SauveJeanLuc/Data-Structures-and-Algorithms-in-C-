#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> sample){
    for(int i=0; i<sample.size(); i++){
        cout << sample[i] <<endl;
    }
}

int main(){

    vector<int> students;
    vector<int> newVector(5);
    cout << "Size: " << newVector.size() <<endl;
    cout << "Capacity: " << newVector.capacity() <<endl;

    newVector[5] = 6;

    cout << "Size: " << newVector.size() <<endl;
    cout << "Capacity: " << newVector.capacity() <<endl;

    cout<<"New Vector: "<<endl;
    printVector(newVector);
    cout<<"New Vector: "<<endl;
    
    vector<int> people(4);

    students.push_back(4);
    students.push_back(5);

    people.push_back(9);

    
    printVector(students);
    printVector(people);
    cout << "Size: " << people.size() <<endl;
    cout << "Length: " << people.capacity() <<endl;
    people[0] = 1;
    people[1] = 2;
    people[2] = 3;
    cout << "Size: " << people.size() <<endl;
    cout << "Length: " << people.capacity() <<endl;
    printVector(people);

    

}