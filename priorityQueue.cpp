#include <bits/stdc++.h>
using namespace std;
#include <fstream>

class Priority_Queue
{
private:
  map<int,int>index_lookup;
  vector< pair<int,int> >heap;
  int _size;

public:
  Priority_Queue()
  {
    _size = 0;
  }

  int size()
  {
    return _size;
  }

  bool empty()
  {
    if(_size == 0) return true;
    return false;
  }

  int top()
  {
    if(empty() == true) return -1;
    return heap[0].first;
  }

  void swap(int idx1, int idx2)
  {
    pair<int,int> temp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = temp;

    index_lookup[heap[idx1].first] = idx1;
    index_lookup[heap[idx2].first] = idx2;
  }

  void fix_bottom_heap(int i)
  {
    int l = i*2 + 1;
    int r = i*2 + 2;

    int idx = i;
    if(l < _size && heap[l].second < heap[idx].second)
    {
      idx = l;
    }
    if(r < _size && heap[r].second < heap[idx].second)
    {
      idx = r;
    }

    if(idx != i)
    {
      swap(idx, i);
      fix_bottom_heap(idx);
    }
  }

  void fix_top_heap(int i)
  {
    if(i == 0) return;

    int p = (i - 1)/2;

    if(heap[i].second < heap[p].second)
    {
      swap(i,p);
      fix_top_heap(p);
    }
  }

  void push(int element, int priority)
  {
    index_lookup[element] = _size;
    heap.push_back({element, priority});

    fix_top_heap(_size);
    _size++;
  }

  int pop()
  {
    if(empty() == true) return -1;

    int min_priority_elem = heap[0].first; 
    swap(0,_size-1);
    heap.pop_back();
    _size--;
    fix_bottom_heap(0);

    return min_priority_elem;
  }

  void change_priority(int item, int priority)
  {
    if(index_lookup.find(item) == index_lookup.end()) return;

    int idx = index_lookup[item];
    if(heap[idx].second < priority)
    {
      heap[idx].second = priority;
      fix_bottom_heap(idx);
    }
    else if(heap[idx].second > priority)
    {
      heap[idx].second = priority;
      fix_top_heap(idx);
    }
  }

  void show_all()
  {
    for(int i=0; i<_size; i++)
    {
      cout<<"idx "<<i<<" : "<<heap[i].first<<" "<<heap[i].second<<"\n";
    }
  }

  void show_menu()
  {
    cout<<"1. Push an element\n";
    cout<<"2. Remove min element\n";
    cout<<"3. Change priority of an element\n";
    cout<<"4. Check if empty\n";
    cout<<"5. Check min element\n";
    cout<<"6. Clear Screen\n";
    cout<<"7. Show all\n";
  }
};


int main()
{
  Priority_Queue pq;
  
  pq.show_menu();
  int inp,e,p;
  while(cin>>inp)
  {
    switch(inp)
    {
      case 1:
        cin>>e>>p;
        pq.push(e,p);
        break;
      case 2:
        pq.pop();
        break;
      case 3:
        cin>>e>>p;
        pq.change_priority(e,p);
        break;
      case 4:
        pq.empty()==0?cout<<"False\n":cout<<"True\n";
        break;
      case 5:
        cout<<pq.top()<<"\n";
        break;
      case 6:
        system("cls");
        pq.show_menu();
        break;
      case 7:
        pq.show_all();
        break;
    }
  }
}