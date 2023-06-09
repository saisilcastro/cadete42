typedef struct{
	int file_flag;
	int pid;
}Thread;

ft_set()
{
set->file_flag = O_RDONLY;
}

ft_process(Thread *set)
{
input_file = open(argv[1], set->file_flag, 0777);
}
