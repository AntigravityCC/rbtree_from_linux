#include <stdio.h>
#include <stdlib.h>
#include "rbtree_module.h"

int rbtree_data_compare(const struct rb_node *node, const int *key) 
{
    struct rbtree_data *data = rb_entry(node, struct rbtree_data, node);

    if (data->key < *key)
        return -1;
    else if (data->key > *key)
        return 1;
    else
        return 0;
}

void rbtree_data_insert(struct rb_root *root, struct rbtree_data *data) 
{
    struct rb_node **link = &root->rb_node;
    struct rb_node *parent = NULL;

    // 查找插入位置
    while (*link) {
        struct rb_node *node = *link;
        int result = rbtree_data_compare(node, &data->key);
        parent = node;

        if (result < 0)
            link = &node->rb_left;
        else if (result > 0)
            link = &node->rb_right;
        else {
            // 节点已存在，不进行插入
            return;
        }
    }

    // 插入节点
    rb_link_node(&data->node, parent, link);
    rb_insert_color(&data->node, root);
}



// 在红黑树中查找节点
struct rbtree_data *rbtree_data_search(const struct rb_root *root, int key) 
{
    struct rb_node *node = root->rb_node;

    // 遍历树查找节点
    while (node) {
        struct rbtree_data *data = rb_entry(node, struct rbtree_data, node);
        int result = rbtree_data_compare(&data->node, &key);

        if (result < 0)
            node = node->rb_left;
        else if (result > 0)
            node = node->rb_right;
        else
            return data;  // 找到匹配节点
    }

    return NULL;  // 未找到节点
}

// 删除红黑树中的节点
void rbtree_data_delete(struct rb_root *root, struct rbtree_data *data) 
{
    if (data) {
        rb_erase(&data->node, root);
        RB_CLEAR_NODE(&data->node);
    }
}
