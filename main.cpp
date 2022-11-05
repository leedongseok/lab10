//
// Created by joonhyeok on 10/24/22.
//

#include <fstream>
#include <vector>
#include "doublelinked_list.h"

int main(int argc, char * argv[]){

    int data_access = 0;  // variable for stats
    int data_hit    = 0;  // variable for stats
    int data_miss   = 0;  // variable for stats

    // Step 1 - get data from test file
    /*********************************/
    std::ifstream data_stream;
    data_stream.open("data_set.txt");
    assert(!data_stream.fail());  // check file open

    typedef std::vector<unsigned int> vec_int;
    vec_int data_vector;

    // push data into vector
    unsigned int data_in;
    while (data_stream >> data_in){  // get data from txt file
        data_vector.push_back(data_in);
    }

    data_stream.close();
    /*********************************/


    // Step 2 - push data into double linked list
    /*********************************/
    DLinkedList * data_list = new DLinkedList(8);  // create double linked list

    // pop data from vector and push it into double linked list
    while(data_vector.size()>0){
        unsigned int data_push = data_vector.front();    // get data from vector
        data_vector.erase(data_vector.begin());  // erase data from vector

        data_access++;  // increase access count

        if (data_list->findNode(data_list->get_head(), data_push)){  // search data
            data_hit++;   // increase hit count;
        }
        else{
            data_miss++;  // increase miss count
        }

        data_list->addNode(data_push);  // add data_push into double linked list

        data_list->print();  // print elements of double linked list
    }
    /*********************************/


    // Step 3 - print stats
    /*********************************/

    // calculate his rate and miss rate
	double hit_rate = data_hit / (double)data_access; 
	double miss_rate = data_miss / (double)data_access;

   // print stats
    std::cout << "*** Stats ***" << std::endl;
    std::cout << "Hit rate  :" << hit_rate << std::endl;
    std::cout << "Miss rate :" << miss_rate << std::endl;

    std::cout << "Double linked list element :" << std::endl;

    /// FIXME
    data_list->print();  // print elements of double linked list
    /*********************************/

    delete data_list;  // delete DLinkedList

    return 0;
}
