project10_scheduler: project10_scheduler.o job.o
	gcc -o project10_scheduler project10_scheduler.o job.o

project10_scheduler.o: project10_scheduler.c job.h
	gcc -c project10_scheduler.c

job.o: job.c job.h
	gcc -c job.c
	