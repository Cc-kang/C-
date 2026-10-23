#include <iostream>
using namespace std;
struct jiedian
{
    int data;
    jiedian *next;
};

struct biao
{
    jiedian *head;
    jiedian *rear;
    int num;
};

void chushihua(biao *list);                   // 初始化
void charu(biao *lsit, jiedian *prev, int v); // 插入逻辑
void toucha(biao *list, int v);               // 头插
void weicha(biao *list, int v);               // 尾插
void shanchu(biao *list, jiedian *prev);      // 删除逻辑
void shanyi(biao *list, int v);               // 删除指定节点
void souyoushan(biao *list);                  // 删除所有节点
void bianli(const biao *list);                // 遍历

int main()
{
    biao list;
    chushihua(&list);

    for (int i = 1; i <= 10; i++)
    {
        weicha(&list, i + 100);
    }
    bianli(&list);
    souyoushan(&list);
    bianli(&list);
    return 0;
}

void chushihua(biao *list)
{
    list->head = nullptr;
    list->rear = nullptr;
    list->num = 0;
}

void charu(biao *list, jiedian *prev, int v)
{
    jiedian *xin = new (jiedian);
    xin->data = v;
    xin->next = prev->next;
    prev->next = xin;
}

void toucha(biao *list, int v)
{
    jiedian duyym;
    duyym.next = list->head;
    jiedian *prev = &duyym;
    charu(list, prev, v);
    list->head = duyym.next;
    if (list->rear == nullptr)
    {
        list->rear = list->head;
    }
    list->rear->next = list->head;
    list->num++;
}

void weicha(biao *list, int v)
{
    if (list->rear == nullptr)
    {
        toucha(list, v);
    }
    else
    {
        jiedian *prev = list->rear;
        charu(list, prev, v);
        list->rear = list->rear->next;
        list->num++;
    }
}

void shanchu(biao *list, jiedian *prev)
{
    if (list->head == nullptr)
    {
        return;
    }

    jiedian *tmp = prev->next;

    if (list->head == list->rear)
    {
        delete (tmp);
        list->head = list->rear = nullptr;
        list->num = 0;
        return;
    }

    if (tmp == list->head)
    {
        list->rear->next = tmp->next;
        list->head = tmp->next;
    }

    if (tmp == list->rear)
    {
        list->rear = prev;
    }
    prev->next = tmp->next;
    delete (tmp);
}

void shanyi(biao *list, int v)
{
    jiedian duyym;
    duyym.next = list->head;
    jiedian *prev = &duyym;
    do
    {
        if (prev->next->data == v)
        {
            shanchu(list, prev);
            list->num--;
            break;
        }
        prev = prev->next;
    } while (prev->next != list->head);
}

void souyoushan(biao *list)
{
    jiedian duyym;
    duyym.next = list->head;
    jiedian *prev = &duyym;
    // 循环链表中 prev->next 永不为空，必须靠 head 判断表是否已空；
    // prev 要保持指向哑结点，不能往后走，否则删不到表头
    while (list->head != nullptr)
    {
        shanchu(list, prev);
    }
    cout << " 成功";
}

void bianli(const biao *list)
{

    if (list->head == nullptr)
    {
        cout << endl;
        return;
    }
    jiedian *prev = list->head;
    do
    {
        cout << prev->data << " ";
        prev = prev->next;
    } while (prev != list->head);
    cout << endl
         << list->num;
}
