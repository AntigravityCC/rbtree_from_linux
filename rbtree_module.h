#ifndef	_RBTREE_MODULE_H_
#define	_RBTREE_MODULE_H_
#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

// 初始化红黑树根节点
#define RBTREE_DATA_ROOT RB_ROOT

struct address_t 
{
    int address
};

typedef struct address_t data_t;

// 定义示例数据结构
struct rbtree_data 
{
    int key;
    data_t data;// 其他数据成员...
    struct rb_node node;
};

void rbtree_data_insert(struct rb_root *root, struct rbtree_data *data) ;
struct rbtree_data *rbtree_data_search(const struct rb_root *root, int key);
void rbtree_data_delete(struct rb_root *root, struct rbtree_data *data) ;

#endif