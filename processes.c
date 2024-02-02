#include <stdio.h>
#include <stdlib.h>


#define max_process_count 25



typedef struct Process{
    int process_state;
    int process_id;
    struct Process * parent_process;
    struct Process * child_process;
    struct Process * younger_sib;
    struct Process * older_sib;
} process;


process * list[max_process_count]; //<-- array of processes, which can be linked by a linked list?
                 // Actuallly can we just link them with pointers? Because  
                 // Try younger sibling, older sibling



// process state:
//  0: ready
//  1: running
//  -1: blocked

void command_create(){
	// First ever process
	process * init_proc = (process *) malloc (sizeof(process *));
	init_proc->process_id = 0;
	init_proc->process_state = 0;
	init_proc->parent_process = NULL;
	init_proc->child_process = NULL;
	init_proc->younger_sib = NULL;
	init_proc->older_sib = NULL;
	list[init_proc->process_id] = init_proc;
};


void create_child_process( int id, process * parent, process * child){
     process * new_proc = (process *) malloc (sizeof(process * ));

     new_proc->process_state = 1;
     new_proc->process_id = id;
     new_proc->parent_process = parent;
     new_proc->child_process = NULL;
     new_proc->younger_sib = NULL;
     new_proc->older_sib = NULL;
     list[id] = new_proc;
    // list[id] = new_proc;
     printf("%d",new_proc->process_id);
};  // <--- 


void destroy_process(); // <--- Recursive function


int main(int argc, char *argv[]){
      
      int user_argument = 0;
      int process_num;
      int proc_parent;

     while(user_argument != 5){
     printf("Test program for abstractin of process Creation, please enter in a numerical argument 1-5 \n");
     printf("------------------------------------------------------------------------------------------\n");
     printf(" 1. Initilize process heirchy \t2. Create child process\t3. Destroy process \n");
     scanf("%d",&user_argument);

     printf("\n USER INPUT %d \n", user_argument);

          switch(user_argument) {
          case 1: 
          	       printf("Initilize process Hierarchy \n");
          	       command_create(1);
          	       break;
          case 2:
          	       printf("Create\n");
          	       if(list[0] == NULL)
          	       	printf(" DNE!");
          	       else{
          	       	 printf("Enter in id for process:\t");
          	       	 scanf("%d",&process_num);
          	       	 printf("\nEnter parent of process %d",process_num);
          	       	 scanf("%d",&proc_parent);
          	       	 create_child_process(process_num,list[proc_parent], NULL);
          	       }

          	       break;
          case 3:
          	      printf("Destroy \n");
          	      break;
          case 4:
          	      printf("Do nothing \n");
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