#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
    int info;
    int access;
    struct sNode *next;
}Node;

void initiation_List( Node **ptList ){
    *ptList = NULL;
}

int empty_List( Node *ptList ){
    if( ptList == NULL )
        return 1;
    else
        return 0;
}

int read_Integer( int number ){
    printf( "\n---Enter an integer:---\n" );
    scanf( "%d", &number );
    return number;
}

void print_Integer( int number ){
    printf( "%d ", number );
}

Node *allocate_Node(){
    Node *new = ( Node* ) malloc( sizeof( Node ) );
    if( new != NULL ){
        new->info = read_Integer( new->info );
        new->access = 0;
        new->next = NULL;
        return new;
    }else{
        printf( "\n---Error to allocate node!---\n" );
        return NULL;
    }
}

void deallocate_Node( Node *ptList ){
    free( ptList );
    printf( "\n---Successfully deallocate memory!---\n" );
}

void insert_Begin( Node **ptList ){
    Node *new = allocate_Node();
    new->next = *ptList;
    *ptList = new;
    printf( "\n---Element successfully inserted at the beginning!---\n" );
}

void insert_End( Node **ptList ){
    Node *new = allocate_Node();
    if( empty_List( *ptList ) )
        *ptList = new;
    else{
        Node *assist = *ptList;
        while( assist->next != NULL )
            assist = assist->next;
        assist->next = new;
    }
    printf( "\n---Element successfully inserted at the end!---\n" );
}

void insert_Orderly( Node **ptList ){
    Node *current = *ptList;
    Node *before = NULL;
    Node *new = allocate_Node();
    
    while( current != NULL && current->info < new->info ){
        before = current;
        current = current->next;
    }

    if( current == *ptList ){
        new->next = *ptList;
        *ptList = new;
    }else{
        before->next = new;
        new->next = current;
    }
    printf( "\n---Element successfully inserted in order!---\n" );
}

void insert_Recursive( Node **ptList, int number ){
    if( *ptList == NULL ){
    	*ptList = ( Node* ) malloc( sizeof( Node ) );
    	( *ptList )->info = number;
    	( *ptList )->next = NULL;
	}else
		insert_Recursive( & ( ( *ptList )->next ), number );
}

void success_Recursive(){
    printf( "\n---Element successfully inserted recursively!---\n" );
}

void remove_Begin( Node **ptList ){
    if( empty_List( *ptList ) )
        printf( "\n---Empty list!---\n" );
    else{
        Node *aux = *ptList;
        *ptList = ( *ptList )->next;
        deallocate_Node( aux );
    }
}

void remove_End( Node **ptList ){
    if( empty_List( *ptList ) )
        printf( "\n---Empty list!---\n" );
    else{
        Node *current = *ptList;
        Node *before = NULL;
        
        while( current->next != NULL ){
            before = current;
            current = current->next;
        }
        
		if( current == *ptList )
            *ptList = NULL;
        else 
            before->next = NULL;
        deallocate_Node( current );
    }
}

Node *return_Node( Node *ptList, int number ){
    if( empty_List( ptList ) ){
        printf( "\n---Empty list!---\n" );
        return NULL;
    }else{
        Node *assist = ptList;
        while( assist != NULL ){
            if( assist->info == number )
                return assist;
            else   
                assist = assist->next;
        }
    }
    return NULL;
}

void remove_Ordely( Node **ptList ){
    int number = read_Integer( number );
    Node *assist = return_Node( *ptList, number );
    
	if( assist != NULL ){
        if( assist == *ptList )
            remove_Begin( ptList );
        else{
            Node *before = *ptList;
            while( before->next != assist )
                before = before->next;
            
            before->next = assist->next;
            deallocate_Node( assist );
        }
    }else
        printf( "\n---Element not found!---\n" );
}

Node *remove_Recursive( Node *ptList, int number ){
    if( ptList == NULL ){
        printf( "\n---Element not found!---\n" );
        return NULL;
    }else{
        if( ptList->info == number ){
            Node *assist = ptList->next;
            deallocate_Node( ptList );
            return assist;
        }else
            ptList->next = remove_Recursive( ptList->next, number );
    }
}

void remove_AllNodes( Node **ptList ){
    if( empty_List( *ptList ) )
        printf( "\n---Empty list!---\n" );
    else{
       Node *current = *ptList;
       Node *before = NULL;
       
       while( current != NULL ){
           before = current;
           current = current->next;
           deallocate_Node( before );
       }
       *ptList = NULL;
       printf( "\n---All nodes removed successfully!---\n" );
    }
}

void iterative_Search( Node *ptList ){
    int number = read_Integer( number );
    Node *assist = return_Node( ptList, number );
    
	if( assist != NULL ){
        assist->access++;
        printf( "\n---Element found!---\n" );
        printf( "%d\n", assist->info );
    }else 
        printf( "\n---Element not found!---\n" );
}

Node *recursive_Search( Node *ptList, int number ){
    if( ptList == NULL ){
        printf( "\n---Element not found!---\n" );
        return NULL;
    }else{
        if( ptList->info == number ){
            ptList->access++;
            printf( "\n---Element found!---\n" );
            printf( "%d\n", ptList->info );
            return ptList;
        }else{
            recursive_Search( ptList->next, number );
        }
    }
    return NULL;
}

void move_Front( Node **ptList ){
    int number = read_Integer( number );
    Node *assist = return_Node( *ptList, number );
    
	if( assist != NULL ){
        assist->access++;
        if( assist == *ptList )
            printf( "\n---Element is at the beginning of the list!---\n" );
        else{
            Node *current = *ptList;
            while( current->next != assist )
                current = current->next;
            
			current->next = assist->next;
            assist->next = *ptList;
            *ptList = assist;
            printf( "\n---Element moved forward successfully!---\n" );
        }
    }else
        printf( "\n---Element not found!---\n" );
}

void transposition( Node **ptList ){
    int number = read_Integer( number );
    Node *assist = return_Node( *ptList, number );
    
    if( assist != NULL ){
        assist->access++;
        if( assist == *ptList )
            printf( "\n---Element is at beginning of the list!---\n" );
        
        if( ( *ptList )->next == assist ){
            ( *ptList )->next = assist->next;
            assist->next = *ptList;
            *ptList = assist;
        }else{
            Node *current = *ptList;
            Node *before = NULL;
            
            while( current->next != assist ){
                before = current;
                current = current->next;
            }
            
            current->next = assist->next;
            before->next = assist;
            assist->next = current;
        }
        printf( "\n---Successful transposition!---\n" );
    }else
        printf( "\n---Element not found!---\n" );
}

void count( Node **ptList ){
    int number = read_Integer( number );
    Node *assist = return_Node( *ptList, number );

    if( assist != NULL ){
        assist->access++;
        if( assist == *ptList )
            printf( "\n---Element is at beginning of the list!---\n" );
        
        if( ( *ptList )->next == assist && ( *ptList )->access < assist->access ){
            ( *ptList )->next = assist->next;
            assist->next = *ptList;
            *ptList = assist;
        }else{
            Node *current = *ptList;
            Node *beforeAssist = *ptList;
            Node *before = NULL;

            while( beforeAssist->next != assist )
                beforeAssist = beforeAssist->next;
            beforeAssist->next = assist->next;

            while( current->access >= assist->access ){
                before = current;
                current = current->next;
            }

            if( current == *ptList ){
                assist->next = *ptList;
                *ptList = assist;
            }else{
                before->next = assist;
                assist->next = current;
            }
        }
    }
}

void iterative_Print( Node *ptList ){
	if( empty_List( ptList ) )
		printf( "\n---Empty list!---\n" );
	else{
		Node *assist = ptList;
		printf( "\n---List---\n" );
		while( assist != NULL ){
			print_Integer( assist->info );
			assist = assist->next;
		}
		printf( "\n---End of list---\n" );
	}
}

void recursive_Print( Node *ptList ){
	if( ptList != NULL ){
		print_Integer( ptList->info );
		recursive_Print( ptList->next );
	}
}

void memory_Address( Node *ptList ){
	if( empty_List( ptList ) )
		printf( "\n---Empty list!---\n" );
	else{
		Node *assist = ptList;
		printf( "\n---List---\n" );
		while( assist != NULL ){
			printf( "%x ", assist );
			assist = assist->next;
		}
		printf( "\n---End of list---\n" );
	}
}

void number_Access( Node *ptList ){
	if( empty_List( ptList ) )
		printf( "\n---Empty list!---\n" );
	else{
		int i = 0;
		Node *assist = ptList;
		
		while( assist!= NULL ){
			printf( "Number of accesses to the %d node: %d\n", i, assist->access );
			i++;
			assist = assist->next;
		}
	}
}

void print_Menu(){
    printf( "\n0-Exit\n1-Insertion\n2-Removal\n3-Search\n4-Ordination\n" );
    printf( "5-Print\n6-Display memory addresses\n7-Display number of access\n8-Remove all nodes\n" );
}

void print_InsertionRemoval(){
    printf( "\n1-Begin\n2-End\n3-Orderly\n4-Recursive\n" );
}

void access_Types(){
    printf( "\n1-Iterative\n2-Recursive\n" );
}

void ordination_Types(){
    printf( "\n1-Move to front\n2-Transposition\n3-Count\n" );
}

void print_Invalid(){
    printf( "\n---Invalid option!---\n" );
}


