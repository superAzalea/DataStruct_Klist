/*
 * =====================================================================================
 *       Filename:  test.c
 *    Description:  
 *        Version:  1.0
 *        Created:  06/27/2016 15:06:04
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Azalea, 
 *   Organization: 
 * =====================================================================================
 */

#include <stdio.h>
#include "list.h"
struct data_info {
	char *name;
	int age;
	struct list_head list;
};

int main()
{
	struct data_info s[] = {
	{"tom", 18}, {"jack", 19},
		{"frank", 20}, {"niko", 21},
		{"richard", 22}, {"mack", 23},

	};
	INIT_LIST_HEAD(head);
	int i;
	for (i = 0; i <sizeof s/sizeof s[0];++i)
	{
		list_add_tail(&s[i].list,&head);
	}
	list_del(&s[1].list);
	struct list_head *cur;
	list_for_each(cur,&head){
		struct data_info *pa = container_of(cur,struct data_info,list);
		printf("%s:%d\n",pa->name,pa->age);
	}
	return 0;
}


