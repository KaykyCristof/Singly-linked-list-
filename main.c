#include "implementation.h"

int main(){
    int option;
    int choice;
    int number;
    Node *list;

    initiation_List( &list );

    do{
        print_Menu();
        scanf( "%d", &option );

        switch( option ){
            case 1:
            {
                print_InsertionRemoval();
                scanf( "%d", &choice );

                switch( choice ){
                    case 1:
                    {
                        insert_Begin( &list );
                        break;
                    }
                    case 2:
                    {
                        insert_End( &list );
                        break;
                    }
                    case 3:
                    {
                        insert_Orderly( &list );
                        break;
                    }
                    case 4:
                    {
                        number = read_Integer( number );
                        insert_Recursive( &list, number );
                        success_Recursive();
                        break;
                    }
                    default:
                    {
                        if( choice != 0 )
                            print_Invalid();
                    }
                }
                break;
            }
            case 2:
            {
                print_InsertionRemoval();
                scanf( "%d", &choice );

                switch( choice ){
                    case 1:
                    {
                        remove_Begin( &list );
                        break;
                    }
                    case 2:
                    {
                        remove_End( &list );
                        break;
                    }
                    case 3:
                    {
                        remove_Ordely( &list );
                        break;
                    }
                    case 4:
                    {
                        number = read_Integer( number );
                        remove_Recursive( list, number );
                        break;
                    }
                    default:
                    {
                        if( choice != 0 )
                            print_Invalid();
                    }
                }
                break;
            }
            case 3:
            {
                access_Types();
                scanf( "%d", &choice );

                switch( choice ){
                    case 1:
                    {
                        iterative_Search( list );
                        break;
                    }
                    case 2:
                    {
                        number = read_Integer( number );
                        recursive_Search( list, number );
                        break;
                    }
                    default:
                    {
                        if( choice != 0 )
                            print_Invalid();
                    }
                }
                break;
            }
            case 4:
            {
                ordination_Types();
                scanf( "%d", &choice );
                
                switch( choice ){
                    case 1:
                    {
                        move_Front( &list );
                        break;
                    }
                    case 2:
                    {
                        transposition( &list );
                        break;
                    }
                    case 3:
                    {
                        count( &list );
                        break;
                    }
                    default:
                    {
                        if( choice != 0 )
                            print_Invalid();
                    }
                }
                break;
            }
            case 5:
            {
            	access_Types();
            	scanf( "%d", &choice );
            	
            	switch( choice ){
            		case 1:
            		{
            			iterative_Print( list );
            			break;
					}
					case 2:
					{
						recursive_Print( list );
						break;
					}
					default:
					{
						if( choice != 0 )
							print_Invalid();
					}
				}
            	break;
			}
			case 6:
			{
				memory_Address( list );
				break;
			}
            case 7:
            {
                number_Access( list );
                break;
            }
            case 8:
            {
                remove_AllNodes( &list );
                break;
            }
            default:
            {
                if( option != 0 )
                    print_Invalid();
            }
        }
    }while( option != 0 );

    remove_AllNodes( &list );

    return 0;
}
