#include <stdio.h>
#include <stdlib.h>


#define max_process_count 25



typedef struct Process{
    
    int process_id;
    struct Process * parent_process;
    struct Process * child_process;
    struct Process * younger_sib;
    struct Process * older_sib;
} process;


process * list[max_process_count]; //<-- array of processes, which can be linked by a linked list?
                 // Actuallly can we just link them with pointers? Because  
                 // Try younger sibling, older sibling

void allocate_list(){
    for(int i; i < max_process_count ; i ++){
        list[i] = malloc(sizeof(process));
        
    }
}

// process state:
//  0: ready
//  1: running
//  -1: blocked

void command_create(int id){
	// First ever process
	// Creation of a parent process, no children
	list[id] = malloc(sizeof(process));
	
	list[id]->process_id = id;
	list[id]->parent_process = NULL;
	list[id]->child_process = NULL;
	
	list[id]->younger_sib = NULL;
	list[id]->older_sib = NULL;
	
	
};


void create_child_process( int id, int parent_id){
     list[id] = malloc(sizeof(process));
     
     list[id]->process_id = id;
     
     
     list[id]->parent_process = list[parent_id];
     
      list[id]->younger_sib = NULL;
      list[id]->older_sib = NULL;
     
     if(list[parent_id]->child_process != NULL){
       process * temptr = list[parent_id]->child_process;
       while(temptr->younger_sib != NULL){
           temptr = temptr->younger_sib;
       }
       
       temptr->younger_sib = list[id];
      
      list[id]->older_sib = temptr;
      list[id]->younger_sib = NULL;
      
     
     }
       else
     list[parent_id]->child_process = list[id];
     
     
     

    // list[id] = new_proc;
     
};  // <--- 


process * destroy_process(int p_id){ 
        // If process has no children or siblings at actually
        if(list[p_id]->child_process == NULL && list[p_id]->younger_sib == NULL){
           list[p_id] = NULL;
       

           return free(list[p_id]);
        }
        else if(list[p_id]->younger_sib != NULL){
           return destroy_process(list[p_id]->younger_sib->process_id);
        }
	 else {
	    return destroy_process(list[p_id]->child_process->process_id);	
	 }
    
}; // <--- Recursive function
// recursive go through child, then young sibling, set pointers to null

void print_proccesses(){
	for(int i = 0; i < max_process_count ; i ++){
	    if(list[i] == NULL){
	       printf("Slot #%d is free.\n", i);// Do nothing
	    }
	    else{
	    process * tempr = list[i];
	    printf("Process ID [%d]\n", tempr->process_id);
	    
	    if(tempr->child_process != NULL){
	    printf("Child Processes ->");
	       tempr = tempr->child_process;
	      while(tempr != NULL){
	        printf(" [%d] ",tempr->process_id);
	        tempr = tempr->younger_sib;
	      }
	      printf("\n");
	      
	    }
	    else
	      printf("No Children \n");
	     
	    }
	    
	}
	 
    printf("====================\n");
    	//printf("\n Procces's children %d \n", list[0]->child_process->process_id); // This will be xpanded with a for loop to go through children actuallyl children to null, younger sibling to null
};


int main(int argc, char *argv[]){
      
      int user_argument = 0;
      int process_num;
      int proc_parent;
      int process_num_init;
       int Process_To_Destroy;
     // allocate_list();

    /*   Test functions
      command_create(0);
      create_child_process(1,0);
      create_child_process(2,0);
      create_child_process(5,1);
      create_child_process(10,2);
      create_child_process(4,0);
      command_create(6);
      create_child_process(9,6);
      print_proccesses();
      destroy_process(0);
      print_proccesses(); */ 
     // destroy_process(6); Create a check if's a parent I'm deleting that has no parent of there own beforehand
      
     

     while(user_argument != 4){
     print_proccesses();
     printf("\n Test program for abstraction of process creation, please enter in a numerical argument 1-5 \n");
     printf("------------------------------------------------------------------------------------------\n");
     printf("1. Initilize process heirchy. 2. Create child process. 3. Destroy process. 4. Quit out. \n");
     printf("User Input : ");
     scanf("%d",&user_argument);

     printf("\n USER INPUT %d \n", user_argument);

          switch(user_argument) {
          case 1: 
          	       printf("Initilize process Hierarchy \n");
          	       printf("Enter in process id: ");
          	       scanf("%d", &process_num_init);
          	       command_create(process_num_init);
          	       break;
          case 2:
          	       printf("Create\n");
          	       if(list[0] == NULL)
          	       	printf(" DNE!");
          	       else{
          	       	 printf("Enter in id for process: ");
          	       	 scanf("%d",&process_num);
          	       	 printf("\nEnter parent of process %d: ",process_num);
          	       	 scanf("%d",&proc_parent);
          	       	 create_child_process(process_num, proc_parent);
          	       }

          	       break;
          case 3:
          	    
          	      printf("Enter in Process to destroy \n");
          	      scanf("%d",&Process_To_Destroy);
          	      destroy_process(Process_To_Destroy);
          	      printf("%d",list[Process_To_Destroy]);
          	      break;
          case 4:
          	      printf("Exiting ");
          	      print_proccesses();
          	      break;
          default:
          	      
          	      break;


          }
       }  
	return 0;
}

// Thinking of gameplan
// create process, put into array
// make a function to go through children, when I reach end of children, go through younger siblings til null, if null set pointers
// IE 1 is child of 0
//   Make 2 a child of 0
// go through 0 -> child til 0->child is null 
// Then 0->child->younger_sib is null
// when that is null, make 0->child->younger point to 2, whose 2->older_sibling is 0->child, 
// Check if we need to pass in the siblings as arguments, because we just go through the the children, then siblings with a temporary pointer
   // Goal of this is to do some thing 0 , 1 ,2 with 1 and 2 as children of 0