#include <stdio.h>
#include <stdlib.h>
#include "rbtree_module.h"

int main(int argc, char *argv[])
{
    struct rb_root rbree_root = RBTREE_DATA_ROOT;

    // 创建示例数据
    struct rbtree_data data1 = { .key = 10, .data = 100};
    struct rbtree_data data2 = { .key = 20, .data = 200 };
    struct rbtree_data data3 = { .key = 30, .data = 300 };

    // 插入数据
    rbtree_data_insert(&rbree_root, &data1);
    rbtree_data_insert(&rbree_root, &data2);
    rbtree_data_insert(&rbree_root, &data3);

    // 查找数据并打印结果
    int search_key = 20;
    struct rbtree_data *result = rbtree_data_search(&rbree_root, search_key);
    if (result != NULL) 
    {
        printf("Found data with key %d, address %d\n", result->key, result->data.address);
    } 
    else 
    {
        printf("Data with key %d not found\n", search_key);
    }

    // 删除数据
    int delete_key = 20;
    struct rbtree_data *to_delete = rbtree_data_search(&rbree_root, delete_key);
    if (to_delete != NULL) {
        rbtree_data_delete(&rbree_root, to_delete);
        printf("Data with key %d deleted\n", delete_key);
    } else {
        printf("Data with key %d not found, cannot delete\n", delete_key);
    }

    // 查找数据并打印结果
    struct rbtree_data *result_again = rbtree_data_search(&rbree_root, search_key);
    if (result_again != NULL) 
    {
        printf("Found data with key %d, address %d\n", result_again->key, result_again->data.address);
    } 
    else 
    {
        printf("Data with key %d not found\n", search_key);
    }
    return 0;
}
