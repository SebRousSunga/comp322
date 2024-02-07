#include <stdio.h>
#include <stdlib.h>


#define max_process_count 25



typedef struct Process{
    
    int ProcessID;
    struct Process * ParentPCB;
    struct Process * ChildPCB;
    struct Process * SiblingPCB;

} process;


process * PcbArray[max_process_count]; //<-- array of processes, which can be linked by a linked PcbArray?
                 // Actuallly can we just link them with pointers? Because  
                 // Try younger sibling, older sibling

void allocate_PcbArray(){
    for(int i; i < max_process_count ; i ++){
        PcbArray[i] = malloc(sizeof(process));
        
    }
}

// process state:
//  0: ready
//  1: running
//  -1: blocked

void CreatePCB(int PCBid){
	// First ever process
	// Creation of a parent process, no children
	process * PCB = malloc(sizeof(process));
	
    PCB->ProcessID = PCBid;
    PCB->ParentPCB = NULL; // Points to nothing
    PCB->ChildPCB = NULL; // points to nothing at initilization
    PCB->SiblingPCB = NULL; //Has no Siblings
 
    PcbArray[PCBid] = PCB;	
	
};


void CreateChildPCB( int PCBid, int ParentPcbId ){
     process * childPCB = malloc(sizeof(process));
     
     
};  // <--- 


int DestroyPCB(int PCBid){ 
        // If process has no children or siblings at actually
        
	 
    
}; // <--- Recursive function
// recursive go through child, then young sibling, set pointers to null

void print_proccesses(){
	for(int i = 0; i < max_process_count ; i ++){
	    if(PcbArray[i] == NULL){
	      // printf("Slot #%d is free.\n", i);// Do nothing
	    }
	    else{
	    process * TempPCBpointer = PcbArray[i];
	    printf("Process ID [%d]\n", TempPCBpointer->ProcessID);
        printf("In Memory: %p\n", TempPCBpointer);
	    
        process * ChildTEMPpointer = TempPCBpointer->ChildPCB;
	    if(ChildTEMPpointer != NULL){
	    printf("Child Processes ->");
	       TempPCBpointer = TempPCBpointer->ChildPCB;
	      while(TempPCBpointer != NULL){
	        printf(" [%d] ",TempPCBpointer->ProcessID);
            printf("In Memory: %p\n", TempPCBpointer );
	        TempPCBpointer = TempPCBpointer->SiblingPCB;
	      }
	      printf("\n");
	      
	    }
	    else
	      printf("No Children \n");
	     
	    }
	    
	}
	 
    printf("====================\n");
    	//printf("\n Procces's children %d \n", PcbArray[0]->child_process->ProcessID); // This will be xpanded with a for loop to go through children actuallyl children to null, younger sibling to null
};


int main(int argc, char *argv[]){
      
      int UserArguement;
      int ParentPCBChoice;
      int PositionInArray = 0;
    
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
          	       CreatePCB(PositionInArray);
                   PositionInArray++;
          	       break;
          case 2:
          	       scanf("Enter in Parent %d", &ParentPCBChoice);
                   if(PcbArray[ParentPCBChoice] == NULL)
                     printf("Parent does not exist within Array");
                    else{
                        CreateChildPCB(PositionInArray,ParentPCBChoice);
                    }

          	       break;
          case 3:
          	    
          	      printf("Enter in Process to destroy \n");
          	      scanf("%d",&Process_To_Destroy);
          	      DestroyPCB(Process_To_Destroy);
          	      
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
// Then 0->child->SiblingPCB is null
// when that is null, make 0->child->younger point to 2, whose 2->older_sibling is 0->child, 
// Check if we need to pass in the siblings as arguments, because we just go through the the children, then siblings with a temporary pointer
   // Goal of this is to do some thing 0 , 1 ,2 with 1 and 2 as children of 0