struct exmem
{
	int len;
	int used;
	char* mem;
};

extern struct exmem* exmem_new(int size);
extern int exmem_push(struct exmem* mp, char* bytes, int size);
extern int exmem_pop(struct exmem* mp, char* bytes, int size);
extern void exmem_del(struct exmem* mp);
extern int exmem_len(struct exmem* mp);
