#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Structure for a node of a linked list.
 *
 * \var element The value stored int the node.
 * \var next The pointer to the next node in the list.
 */
struct Node {
	int value;
	struct Node * next;
};

/**
 * \brief Creates a new node with given value.
 *
 * \param value The value of the node.
 *
 * \return A pointer to the new node.
 */
struct Node * new_node(int value) {
	struct Node * res = NULL;

	res = malloc(sizeof(struct Node));
	if( res == NULL ) {
		fprintf(stderr, "Error: cannot allocate memory for new list node.\n");
		exit(EXIT_FAILURE);
	}

	res-> value = value;
	res->next = NULL;

	return res;
}

/**
 * \brief Creates a linked list of integers from the values in the array of
 *        integers provided.
 *
 * \param data Integer array containing the values with which the list will be
 *             initialized.
 * \param data_size Size of the data array.
 *
 * \return The newly created list.
 */
struct Node * init_list(int * data, int data_size) {
	int i;
	struct Node * current_node;
	struct Node * res = NULL;

	if( data_size != 0 ) {
		res = new_node(data[0]);
		current_node = res;
		for( i = 1 ; i < data_size ; i++ ) {
			current_node->next = new_node(data[i]);
			current_node = current_node-> next;
		}
	}

	return res;
}

/**
 * \brief Frees the memory allocated to a linked list.
 *
 * \param l The list to destroy.
 */
void destroy_linked_list(struct Node * l) {
	struct Node * tmp;
	while( l != NULL ) {
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

/**
 * \brief Counts even elements in a list of integers (Algorithm 1).
 *
 * \param l Integer list.
 *
 * \return The number of even integers in l.
 */
int number_even(struct Node * l) {
	int res = 0;

    while (l != NULL){
        if((l->value % 2) == 0){
            res = res + 1;
        }
		l = l->next;
    }
	return res;
}

int positifs(struct Node * l) {
	int res = 1;

	if (l != NULL && res == 1){
		if ( l-> value < 0){
			res = 0;
		}
		else{
			l = l->next;
			res = positifs(l);
		}
	}
    
	return res;
}

int egal(struct Node * l1, struct Node * l2){
	int res =1;
	if(l1 != NULL && l2 != NULL){
		if(l1->value==l2->value){
			l1=l1->next;
			l2=l2->next;
			//printf("%d,%d",l1->value,l2->value);
			res=egal(l1,l2);
			
		}else{
			res=0;
		}

	}else if((l1 == NULL && l2 != NULL) || (l1 != NULL && l2 == NULL)){
		res = 0;
	}

	return res;
}

int main(int argc, char ** argv) {
	// tests for function number_even
	/*int l1_data[] = {0, 1, 2, 3, 4, 5, 6};
	struct Node * l1 = init_list(l1_data, 7);
	printf("number_even([0,1,2,3,4,5,6]) = %d - Expected: 4\n", number_even(l1));

	int l2_data[] = {1,3,5,7};
	struct Node * l2 = init_list(l2_data, 4);
	printf("number_even([1,3,5,7]) = %d - Expected: 0\n", number_even(l2));

	int l3_data[] = {2,4,6,8,10};
	struct Node * l3 = init_list(l3_data, 5);
	printf("number_even([2,4,6,8,10]) = %d - Expected: 5\n", number_even(l3));

	struct Node * l4 = NULL;
	printf("number_even([]) = %d - Expected: 0\n", number_even(l4));*/

	int l3_data[] = {2,4,6,8,9};
	struct Node * l3 = init_list(l3_data, 5);

	int l4_data[] = {2,4,6,8,10};
	struct Node * l4 = init_list(l3_data, 5);


	printf("%d\n", egal(l3,l4));

	// clean memory
	//destroy_linked_list(l1);
	//destroy_linked_list(l2);
	destroy_linked_list(l3);
	destroy_linked_list(l4);

	return 0;
}
