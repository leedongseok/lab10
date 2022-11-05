//
// Created by joonhyeok on 10/24/22.
//

#include "doublelinked_list.h"

DLinkedList::DLinkedList(unsigned int max_size_in) :
    max_size(max_size_in) {

    head = NULL;
    tail = NULL;

    size = 0;
}


DLinkedList::~DLinkedList() {

	node* temp = head;

	while(temp != NULL){

		node* nodetodelete = temp;
		temp = temp -> next_node;
		nodetodelete -> ~node();
		size--;

	}	

    std::cout << "!! Delete DLinked List !!"  << std::endl;
}


void DLinkedList::addNode(int data_i) {
	

	node* temp = new node(data_i, NULL, NULL);

	if(head == NULL){
		head = temp;
		tail = temp;
		size++;

	}
	else{
		if(size < max_size){
			
			if(findNode(get_head(), data_i)){
				
				node* temp0 = head;

				if(temp0 -> data == data_i){

					node* temp1 = head -> next_node;
					head = temp1;
					size--;
					temp1 -> ~node();

					if(temp1 == NULL){
						
						head = temp;

					}
					
					
				}
				else{
					while(temp0->data != data_i){

						temp0 = temp0 -> next_node;

					}
					
					if(temp0 == tail){

						node* temp1 = tail -> prev_node;

						temp1 -> next_node = NULL;
						
						tail = temp1;

						size--;
						
						temp0 -> ~node();

	
					}

					else{
						node* temp0_prev = temp0 -> prev_node;
						temp0_prev -> next_node = temp0 -> next_node;
						temp0 -> next_node -> prev_node = temp0_prev;
						size--;
						temp0 -> ~node();

					}
				}


				
			}
	

		}
		else{

			if(findNode(get_head(), data_i)){
				
				node* temp0 = head;

                                if(temp0 -> data == data_i){

                                        node* temp1 = head -> next_node;

					head = temp1;

					size--;

					temp1 -> ~node();
                                

					if(temp1 == NULL){

						head = temp;

					}

                                   												
				}

                                else{
					while(temp0->data != data_i){

						
						temp0 = temp0 -> next_node;
				
					}

					if(temp0 == tail){

						node* temp0_prev = temp0 -> prev_node;

						tail = temp0_prev;

						size--;

						temp0 -> ~node();

					}
					else{
					
						node* temp0_prev = temp0 -> prev_node;
						node* temp0_next = temp0 -> next_node;
				
						temp0_prev -> next_node = temp0 -> next_node;
					
						temp0_next -> prev_node = temp0_prev;
					
						size--;
					
						temp0 -> ~node();
					
					}

				}

				
			}

			else{

				node* temp0 = head;
				                   
				head = temp0 -> next_node;
			
				temp0 -> ~node();

			}


		}


		temp -> prev_node = tail;

		tail -> next_node = temp;

		tail = temp;

		head -> prev_node = NULL;

		tail -> next_node = NULL;

		size++;

	}	
	
}


void DLinkedList::eraseNode(unsigned int data_i){
    if (size == 0){
        std::cout << "!! erase Error !!" << std::endl;
        abort();  // Not find specific node, program exit
    }


}


bool DLinkedList::findNode(node* node_find, unsigned int data_i) {
	

	if(head == NULL){
		return false;
	}
	else{

		bool find = false;
		if(node_find -> data == data_i){

			return true;

		}
		else{
			if(node_find == tail){
				return false;
			}
			else{
			
				find = findNode(node_find->next_node, data_i);
			}
		}	

		return find;
	}
	

}


void DLinkedList::print() {
    
	
	node* temp = head;

	if(head == NULL){
		std::cout << "Linked List is empty !!" << std::endl;
	}
	else{
		
	        while(temp != tail){
		
        	        std::cout << temp -> data << " ";
                	temp = temp -> next_node;

        	}
		std::cout << temp -> data << std::endl;
		
	}

}
