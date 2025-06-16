#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename k, typename v>
struct HeapItem
{
    v val;
    k key;

    HeapItem()
    {
        val = 0;
        key = "";
    }
};
template <typename k, typename v>
class MinHeap
{
    HeapItem<k, v> *arr;
    int capacity;
    int total;

public:
    MinHeap(int cap = 0)
    {
        if (cap != 0)
        {
            arr = new HeapItem<k, v>[cap];
            capacity = cap;
            total = 1;
        }
        else
        {
            arr = 0;
            capacity = 0;
            total = 1;
        }
    }
    void resize()
    {
        if (capacity == 0)
        {
            capacity = 1;
        }
        capacity *= 2;
        HeapItem<k, v> *Newarr = new HeapItem<k, v>[capacity];
        for (int i = 1; i < total; i++)
        {
            Newarr[i] = arr[i];
        }
        delete[] arr;
        arr = Newarr;
    }
    MinHeap(const MinHeap<k, v> &obj)
    {
        if (obj.capacity != 0)
        {
            // delete[] arr;
            arr = new HeapItem<k, v>[obj.capacity];
            capacity = obj.capacity;
            total = obj.total;

            for (int i = 1; i <= total; i++)
            {
                arr[i] = obj.arr[i];
            }
        }
        else
        {
            arr = 0;
            capacity = 0;
            total = 1;
        }
    }
    MinHeap<k, v> operator=(const MinHeap<k, v> &obj)
    {
        if (this != &obj)
        {
            if (obj.capacity != 0)
            {
                delete[] arr;
                arr = new HeapItem<k, v>[obj.capacity];
                capacity = obj.capacity;
                total = obj.total;

                for (int i = 1; i <= total; i++)
                {
                    arr[i] = obj.arr[i];
                }
            }
        }
        return *this;
    }
    void insert(k ki, v vl)
    {
        if (capacity > 0)
        {
            if (total == capacity)
            {
                resize();
            }
            arr[total].key = ki;
            arr[total].val = vl;
            total++;

            MinHeapify(total / 2);
        }
        else
            cout << "\nNOt Enough CApacity In Queue\n";
    }

    void MinHeapify(int i)
    {

        int l = 2 * i;
        int r = 2 * i + 1;
        int smallest = i;
        if (l < total && arr[l].val < arr[smallest].val)
            smallest = l;
        if (r < total && arr[r].val < arr[smallest].val)
            smallest = r;
        if (smallest != i)
        {
            HeapItem<k, v> temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            //................

            MinHeapify(smallest);
        }
    }

    void decreaseKey(k ki, v val)
    {
        for (int i = 0; i < total; i++)
        {
            if (arr[i].key == ki)
            {
                v temp = arr[i].val;
                arr[i].val = val;
                if (temp < val)
                    MinHeapify(i);

                break;
            }
        }
    }

    void DeleteMin()
    {
        if (isEmpty())
        {
            cout << "Heap is Empty" << endl;
        }
        else
        {
            arr[1] = arr[total - 1];
            total--;
            MinHeapify(1);
        }
    }

    void DeleteKey(k key)
    {
        if (isEmpty())
        {
            cout << "Heap is Empty" << endl;
        }
        else
        {
            int i = 1;
            while (i <= total)
            {
                if (arr[i].key == key)
                {
                    arr[i] = arr[total - 1];
                    total--;
                    MinHeapify(i);
                    break;
                }
                i++;
            }
        }
    }

    v getVal(k key)
    {
        if (isEmpty())
        {
            cout << "Heap is Empty" << endl;
        }
        else
        {
            int i = 1;
            while (i <= total)
            {
                if (arr[i].key == key)
                {
                    return arr[i].val;
                }
                i++;
            }
        }

        return 0;
    }

    HeapItem<k, v> *getMin()
    {
        if (isEmpty())
        {
            cout << "Heap is Empty" << endl;
        }
        else
        {
            return &arr[1];
        }

        return 0;
    }
    bool isEmpty()
    {
        if (total <= 1)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        for (int i = 1; i < total; i++)
        {
            cout << arr[i].key << " ->";
        }
    }

    ~MinHeap()
    {
        if (arr != 0)
        {
            delete[] arr;
        }
    }
};

template <typename k, typename v>
struct Hospital
{
    string Id;
    list<HeapItem<k, v>> routes;
};

template <typename k, typename v>
class HRRS
{
    vector<Hospital<k, v>> hosp;
    int size;

public:
    void readDataFromFile()
    {

        ifstream fin;
        fin.open("Data.txt");

        int n;
        fin >> n;
        size = n + 1;
        hosp.resize(size);
        for (int i = 0; i <= n; i++)
        {
            string s;
            fin >> s;
            // cout << s;
            char c;
            fin >> c;
            while (c != '\n' && !fin.eof())
            {
                if (c == '(')
                {
                    char ch[4];
                    fin.get(ch, 4, ',');
                    fin.ignore();
                    int ti;
                    fin >> ti;
                    //   cout << ch << "  " << ti;
                    HeapItem<k, v> obj;
                    obj.key = ch;
                    obj.val = ti;
                    if (s == "UN")
                    {
                        hosp[0].Id = s;
                        hosp[0].routes.push_back(obj);
                    }
                    else
                    {

                        int ind = stoi(s);
                        hosp[ind].routes.push_back(obj);
                        hosp[ind].Id = "H" + s;
                    }
                }
                fin.get(c);
            }
            cout << endl;
        }

        fin.close();
    }

    vector<list<k>> findTravelTime()
    {
        MinHeap<k, v> queue(5);

        string ch = "H";
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                queue.insert(hosp[0].Id, 0);
            }
            else
            {
                if (hosp[i].Id == "")
                {
                    queue.insert("HN", INT_MAX);
                }
                else
                    queue.insert(hosp[i].Id, INT_MAX);
            }
        }
        //  queue.print();
        vector<list<k>> result;
        result.resize(size);
        string id;
        //   string prev;
        for (int i = 0; i < size; i++)
        {
            HeapItem<k, v> *obj;

            obj = queue.getMin();

            struct list<HeapItem<k, v>>::iterator j;
            struct list<HeapItem<k, v>>::iterator n;
            if (i > 0)
            {
                id = ((*obj).key).substr(1, (obj->key).size());
                // cout<<id<<"---";
                if (id != "N")
                {
                    j = hosp[stoi(id)].routes.begin();
                    n = hosp[stoi(id)].routes.end();
                }
                else
                {
                    // i++;
                    continue;
                }
            }
            else
            {
                id = "0";
                j = hosp[0].routes.begin();
                n = hosp[0].routes.end();
            }
            cout << endl
                 << " -->" << (*obj).key << "  " << (*obj).val << endl;
            // id = ((*obj).key).substr(1,(obj->key).size());
            bool fl = false;
            while (j != n)
            {
                cout << "   " << (*j).key << "," << (*j).val;
                if (((*j).val + (*obj).val) < queue.getVal((*j).key))
                {
                    queue.decreaseKey((*j).key, (*j).val + (*obj).val);
                    fl = true;
                    int ind = stoi(((*j).key).substr(1, ((*j).key).size()));

                    result[ind].push_back((*obj).key);
                }

                j++;
            }

            queue.DeleteMin();
        }

        return result;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "->" << hosp[i].Id << " -- ";
            struct list<HeapItem<k, v>>::iterator j = hosp[i].routes.begin();
            struct list<HeapItem<k, v>>::iterator n = hosp[i].routes.end();
            while (j != n)
            {
                cout << "   " << (*j).key << "," << (*j).val;
                j++;
            }
            cout << endl;
        }
    }
};
int main()
{
    HRRS<string, int> obj;
    obj.readDataFromFile();

    obj.print();
    vector<list<string>> res = obj.findTravelTime();
    cout << "\n";
    int n = res.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        string prev = "UN";
        for (auto j : res[i])
        {
            if (count == 0)
            {
                prev = j;
                if (prev != "UN")
                {
                    for (auto z : res[stoi(prev.substr(1, prev.size()))])
                    {
                        cout << z << "->";
                    }
                }
            }
            count++;
            cout << j << "->";
        }
        cout << " : H" << i << endl;
    }
    return 0;
}