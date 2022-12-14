#include <iostream>
#include <fstream>
#include <cstring>

struct node
{
    char *str;
    int count;
    node *next;
};

bool hasLowercaseOnly(const char *str);
bool isLowercase(char c);
bool isInList(const node *list, const char *str);
void updateList(node *&list, const char *str);
void insert(node *&list, const char *str);
void deleteList(node *&list);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: ./esercizio1.out <input> <output>" << std::endl;
        exit(1);
    }

    const int MAX_SIZE = 100;

    std::ifstream in;
    in.open(argv[1]);
    if (in.fail())
    {
        std::cerr << "Error: cannot open " << argv[1] << std::endl;
        exit(1);
    }

    node *list = NULL;
    char buffer[MAX_SIZE + 1] = {};
    while (in >> buffer)
    {
        // buffer[MAX_SIZE] = '\0';
        if (hasLowercaseOnly(buffer))
        {
            if (isInList(list, buffer))
            {
                updateList(list, buffer);
            }
            else
            {   
                insert(list, buffer);
            }
        }
    }
    in.close();

    std::ofstream out;
    out.open(argv[2]);
    if (out.fail())
    {
        std::cerr << "Error: cannot open " << argv[2] << std::endl;
        exit(1);
    }

    node *list_aux = list;
    while (list_aux != NULL)
    {
        out << list_aux->str << ": " << list_aux->count << std::endl;
        list_aux = list_aux->next;
    }
    out.close();

    deleteList(list);

    return 0;
}

bool hasLowercaseOnly(const char *str)
{
    bool res = true;
    int i = 0;
    while (res && str[i] != '\0')
    {
        res = isLowercase(str[i]);
        i++;
    }
    return res;
}

bool isLowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool isInList(const node *list, const char *str)
{
    if (NULL == list)
    {
        return false;
    }
    if (strcmp(list->str, str) == 0)
    {
        return true;
    }
    return isInList(list->next, str);
}

void updateList(node *&list, const char *str)
{
    if (NULL == list)
    {
        return;
    }
    if (strcmp(list->str, str) == 0)
    {
        list->count++;
        return;
    }
    else
    {
        updateList(list->next, str);
    }
}

void insert(node *&list, const char *str)
{
    if (NULL == list)
    {
        list = new node;
        list->count = 1;
        int length = strlen(str);
        list->str = new char[length + 1];
        // strncpy(list->str, str, length);
        strcpy(list->str, str);
        list->next = NULL;
        return;
    }
    else
    {
        insert(list->next, str);
    }
}

void deleteList(node *&list)
{
    if (list == NULL)
    {
        return;
    }
    node *tmp = list;
    list = list->next;
    delete[] tmp->str;
    delete tmp;
    deleteList(list);
}
