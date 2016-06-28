/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:   kernel list  
 *
 *        Version:  1.0
 *        Created:  06/27/2016 14:17:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Azalea, 
 *   Organization:  
 *
 * =====================================================================================
 */

struct list_head {
	struct list_head *next;
	struct list_head *prev;
};


#define INIT_LIST_HEAD(head) \
	struct list_head head = {&(head),&(head)}

static inline void list_head_init(struct list_head *phead)
{
	phead->next = phead;
	phead->prev = phead;
}

static inline void __list_add(struct list_head *pnode,
			struct list_head *Prev,struct list_head *Next)
{
	pnode->next = Next;
	pnode->prev = Prev;
	Next->prev = pnode;
	Prev->next = pnode;
}

static inline void list_add(struct list_head *pnode, struct list_head *phead)
{
	__list_head(pnode,phead,phead->next);
}

static inline void list_add_tail(struct list_head *pnode,struct list_head *phead)
{
	__list_add(pnode,phead->prev,phead);
}

static inline int list_is_empty(struct list_head *phead)
{
	return (phead->next == phead) && (phead->prev == phead);
}

static inline void list_del(struct list_head *pnode)
{
	pnode->next->prev = pnode->prev;
	pnode->prev->next = pnode->next;
}

static inline void lsit_del_init(struct list_head *pnode)
{
	list_del(pnode);
	list_head_init(pnode);
}

#define list_for_each(cur, head) \
	for(cur = (head)->next; cur != head; cur = cur->next)
#define offset_of(type,member) \
	((size_t)&(((type *)0)->member))

#define container_of(ptr,type,member) \
	((type *)((char *)ptr - offset_of(type, member)))


