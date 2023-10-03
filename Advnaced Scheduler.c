//Muhammad Zain Ali U64584914

//The program is an implementation of a job scheduler, which allows the user to add, remove, and search for jobs. The program starts by displaying a list of available operations to the user, such as adding a job, removing a job, searching for jobs per user or per capacity, listing all jobs, removing jobs and quitting the program. The job scheduler is implemented using a linked list data structure, where each node of the linked list represents a job, and temporary pointers loop around the linked nodes. 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 20
#define SIZE_LEN 3

struct job {
	char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
	int num_cpus, num_gpus, memory, priority;
	double time;
	struct job *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority);
struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority);
struct job * pop_job(struct job *scheduler);
void list_user(struct job *scheduler, char *user_name);
void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time);
void list_all_jobs(struct job *scheduler);
struct job * clear_jobs(struct job *scheduler);

///////////////////
// main function //
///////////////////

int main() {
	char code;
	char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
	int num_cpus, num_gpus, memory, priority;
	double time;

	struct job *scheduler = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'h':
				help();
				break;
			case 'a':
				read(job_name, user_name, &num_cpus, &num_gpus, &memory, &time, &priority);
				scheduler = add_job(scheduler, job_name, user_name, num_cpus, num_gpus, memory, time, priority);
				break;
			case 'p':
				scheduler = pop_job(scheduler);
				break;
			case 'u':
				read(NULL, user_name, NULL, NULL, NULL, NULL, NULL);
				list_user(scheduler, user_name);
				break;
			case 'j':
				read(NULL, NULL, &num_cpus, &num_gpus, &memory, &time, NULL);
				list_jobs(scheduler, num_cpus, num_gpus, memory, time);
				break;
			case 'l':
				list_all_jobs(scheduler);
				break;
			case 'q':
				scheduler = clear_jobs(scheduler);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a job to the scheduler;\n");
	printf("\t'p' for removing a job from the scheduler;\n");
	printf("\t'u' for searching jobs per user;\n");
	printf("\t'j' for searching jobs per capacity;\n");
	printf("\t'l' for listing all jobs;\n");
	printf("\t'q' for quit.\n");
}

void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) {
	if(job_name != NULL) {
		printf("Enter the name of the job: ");
		scanf("%s", job_name);
	}
	if(user_name != NULL) {
		printf("Enter the name of the user: ");
		scanf("%s", user_name);
	}
	if(num_cpus != NULL) {
		printf("Enter the number of CPUs: ");
		scanf("%d", num_cpus);
	}
	if(num_gpus != NULL) {
		printf("Enter the number of GPUs: ");
		scanf("%d", num_gpus);
	}
	if(memory != NULL) {
		printf("Enter the amount of memory: ");
		scanf("%d", memory);
	}
	if(time != NULL) {
		printf("Enter the amount of time: ");
		scanf("%lf", time);
	}
	if(priority != NULL) {
		printf("Enter the priority: ");
		scanf("%d", priority);
	}
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) {

	struct job *new_job = malloc(sizeof(struct job)); // allocate memory for new job
    
  // assign values to new job
  strcpy(new_job->job_name, job_name);
  strcpy(new_job->user_name, user_name);
  new_job->num_cpus = num_cpus;
  new_job->num_gpus = num_gpus;
  new_job->memory = memory;
  new_job->time = time;
  new_job->priority = priority;

  
    
  // if the scheduler is empty, new job becomes the first job
  if (scheduler == NULL) {
    scheduler = new_job;
  }
  else {
        // traverse the scheduler linked list until the last node
    struct job *current_job = scheduler;
    while (current_job->next != NULL) {
      current_job = current_job->next;
        }
        
        // add new job after the last node
    current_job->next = new_job;
    new_job -> next = NULL;
    }
    
  return scheduler;
  

}

struct job * pop_job(struct job *scheduler) {


    struct job *p;
    if(scheduler == NULL){
        return NULL;
  } 
    p = scheduler; //p pointing at the same node where head is pointing
  
  
  

	// output format
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

	printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler->job_name, scheduler->user_name, scheduler->num_cpus, scheduler->num_gpus, scheduler->memory, scheduler->time, scheduler->priority);
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

    scheduler = scheduler -> next; //move the head to point to the next job
    free(p); // remove the first job
    return scheduler;
}

void list_user(struct job *scheduler, char *user_name) {
    struct job *finder;
    int jobs_found = 0; //flag to check if job is found or not

    // check if there is at least one job for the user
    for(finder = scheduler; finder != NULL; finder = finder->next) {
        if(strcmp(finder->user_name, user_name) == 0) {
            jobs_found = 1;
            break;
        }
    }

    // print headings only if jobs are found for the user
    if(jobs_found) {
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    }

    // loop through the scheduler and print job info for the user
    for(finder = scheduler; finder != NULL; finder = finder->next) {
        if(strcmp(finder->user_name, user_name) == 0) {
            printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", finder->job_name, finder->user_name, finder->num_cpus, finder->num_gpus, finder->memory, finder->time, finder->priority);
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        }
    }
}



void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) {


  //find jobs which fulfill the requirement of having maximum values
   
  
    struct job *finder;
    int jobs_found = 0;
    for(finder=scheduler; finder!=NULL; finder=finder->next){
        if(finder->num_cpus <= num_cpus && finder->num_gpus <= num_gpus &&
        finder->memory <= memory && finder->time <= time){
            jobs_found = 1;
            break;
        }
    }
                

    if(jobs_found) {
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    }    			
    
    //loop through all the linked list until it reaches NULL
    for(finder=scheduler; finder!=NULL; finder=finder->next){
      if(finder->num_cpus <= num_cpus && finder->num_gpus <= num_gpus &&
            finder->memory <= memory && finder->time <= time){
			// output the job information
			printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", finder->job_name, finder->user_name, finder->num_cpus, finder->num_gpus, finder->memory, finder->time, finder->priority);

			// output closing line
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

		}
      
      
  

	
}
  }
    

void list_all_jobs(struct job *scheduler) {

    //go over all the linked list, and print them all
    
    struct job *finder;
    int jobs_found = 0;
    for(finder=scheduler; finder!=NULL; finder=finder->next){
        jobs_found = 1;
        break;
    }
    
    if(jobs_found) {
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
        printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    }   
    
    for(finder=scheduler; finder!=NULL; finder=finder->next){
        printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", finder->job_name, finder->user_name, finder->num_cpus, finder->num_gpus, finder->memory, finder->time, finder->priority);

			// output closing line
	    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

    
}
}

struct job * clear_jobs(struct job *scheduler) {
//go over the loop and clear it one by one using free function
	struct job *p;
  while(scheduler!=NULL){
    p = scheduler;
    scheduler = scheduler -> next;
    if(p!=NULL){
      free(p);
    }
    }

    return NULL;
  }
  




