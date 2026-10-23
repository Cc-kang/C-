#include <iostream>
using namespace std;
typedef int element_t;
struct jiedian
{
    element_t data;
    jiedian *prev;
    jiedian *next;
};

struct biao
{
    jiedian header;
    int num;
};
// 初始化
void chushihua(biao *list);
// 插入
void charu(jiedian *new_node, jiedian *prev, jiedian *next); // 逻辑
void toucha(biao *list, element_t val);
void weicha(biao *list, element_t val);
// 删除
void shanchu(jiedian *prev, jiedian *next);
void yishan(biao *list, element_t val);
void souyoushan(biao *list);
// 遍历
void bianli(const biao *list);

int main()
{
    biao list;
    chushihua(&list);
    for (int i = 0; i < 10; i++)
    {
        weicha(&list, i + 100);
    }
    bianli(&list);
    yishan(&list, 105);
    bianli(&list);
    souyoushan(&list);
}

void chushihua(biao *list)
{
    list->header.next = &list->header;
    list->header.prev = &list->header;
    list->num = 0;
}

void charu(jiedian *new_node, jiedian *prev, jiedian *next)
{
    next->prev = new_node;
    new_node->next = next;
    new_node->prev = prev;
    prev->next = new_node;
}

void toucha(biao *list, element_t val)
{
    jiedian *new_node = new (jiedian);
    new_node->data = val;
    charu(new_node, &list->header, list->header.next);
    list->num++;
}

void weicha(biao *list, element_t val)
{
    jiedian *new_node = new (jiedian);
    new_node->data = val;
    charu(new_node, list->header.prev, &list->header);
    list->num++;
}

void shanchu(jiedian *prev, jiedian *next)
{
    prev->next = next;
    next->prev = prev;
}

void yishan(biao *list, element_t val)
{
    jiedian *pos = list->header.next;
    while (pos != &list->header)
    {
        if (pos->data == val)
        {
            shanchu(pos->prev, pos->next);
            delete (pos);
            list->num--;
            return;
        }
        pos = pos->next;
    }
}

void souyoushan(biao *list)
{
    jiedian *pos = list->header.next;
    while (pos != &list->header)
    {
        jiedian *tmp = pos->next;
        delete (pos);
        pos = tmp;
        list->num--;
    }
    cout << list->num << endl;
}

void bianli(const biao *list)
{
    jiedian *pos = list->header.next;
    while (pos != &list->header)
    {
        cout << pos->data << " ";
        pos = pos->next;
    }
    cout << endl;
}