#include <bits/stdc++.h>
using namespace std;


void learnPair() {
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> q = {1, {1, 2}};
    cout << q.first << endl;
    cout << q.second.first << " " << q.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};
    cout << arr[2].first << endl;
}

void learnVector() {
    vector<pair<int, int>> v;
    v.push_back({1, 6});
    v.emplace_back(2, 4);

    cout << v[0].first << " " << v[1].second << endl;

    vector<int> q(5, 100);
    vector<int> r(q);

    cout << "q[0]: " << q[0] << endl;
    cout << "r[0]: " << r[0] << endl;
}

void learnStack() {
    stack<int> s;
    s.push(5);
    s.push(10);
    cout << "top: " << s.top() << endl;
    s.emplace(15);
    s.emplace(20);
    cout << "top: " << s.top() << endl;
    s.pop();
    cout << "top: " << s.top() << endl;
    s.pop();
    cout << "size: " << s.size() << endl;
    cout << "is empty: " << s.empty() << endl;

}


void learnIterators() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << endl;
    it += 2;
    cout << *(it) << endl;
    cout << v.back() << endl;
    cout << endl;

    for (vector<int>::iterator it=v.begin(); it != v.end(); it++) {
        cout << *(it);
    }
    cout << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it);
    }
    cout << endl;
    for (auto it : v) {    //iterator on vector v
        cout << it;
    }
    cout << endl;

    //erasing
    v.erase(v.begin() + 1, v.begin() + 3);

    for (auto it : v) {
        cout << it;
    } 
    cout << endl;

    // insert
    vector<int> v2(5, 100);
    v2.insert(v2.begin() + 2, 4, 2);

    for(auto it : v2) {
        cout << it;
    }
    cout << endl;

    cout << "size of v2: " << v2.size() << endl;

    vector<int> v3(5, 50);
    v2.insert(v2.begin() + 1, v3.begin(), v3.begin() + 4);

    for (auto it : v2) {
        cout << it;
    }
    cout << endl;

    cout << "size of v2: " << v2.size() << endl;
    v3.swap(v2);
    cout << "size of v2: " << v2.size() << endl;
    v3.clear();
    cout << "is empty v3?: " << v3.empty() << endl;

}

void learnLists() {
    list<int> ls; 
    ls.push_back(5);
    for (auto it : ls) {
        cout << it;
    }
    cout << endl;
    ls.push_back(10);
    ls.push_front(1);
    ls.pop_back();
    ls.pop_front();
}


void learnPQ() {
    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.emplace(4);
    pq.emplace(7);

    priority_queue<int> pq_copy = pq;

    cout << "orig pq: " << endl;
    while(!pq_copy.empty()) {
        cout << pq_copy.top() << " ";
        pq_copy.pop();
    }
    cout << endl;
}

void learnSet() {
    set<int> s;
    s.emplace(45);
    s.insert(1);
    s.insert(22);
    s.emplace(-1);

    for (auto it : s) {
        cout << it << " ";
    }

    auto itr = s.find(1);
    cout << "found 1 at pos:" << distance(s.begin(), itr) << endl;
    cout << "upper bound 1: " << *s.upper_bound(1) << endl;
    cout << "lower bound -2: " << *s.lower_bound(-2) << endl;
    cout << "6 present or not: " << s.count(6) << endl;

    cout << endl;
}   


void learnMap() {
    map<int, int> map1;
    map<int, pair<int, int>> map2;
    map<pair<int, int>, int> map3;

    cout << "operations on map1: " << endl;
    map1.insert({1, 3});
    map1[4] = 5;
    map1.emplace(2, 5);

    for (auto it : map1) {
        cout << it.first << " " << it.second << endl;
    }

    cout << "value at key 4: " << (*map1.find(4)).second << endl;

    cout << "operations on map2: " << endl;
    map2.insert({1, {1, 3}});
    map2[4] = {4, 5};
    map2.emplace(2, make_pair(3, 5));

    for (auto it : map2) {
        cout << it.first << ": " << it.second.first << it.second.second << endl;
    }

    cout << "value at key 4: " << (*map2.find(4)).second.first << " " << (*map2.find(4)).second.second << endl;

    cout << "operations on map3: " << endl;
    map3.insert({{1, 3}, 3});
    map3[{4, 5}] = 5;
    map3.emplace(make_pair(2, 3), 5);

    for (auto it : map3) {
        cout << it.first.first << " " << it.first.second << ": " << it.second << endl;
    }

    cout << "value at key {4, 5}: " << (*map3.find({4, 5})).second << endl;        
}


bool comp(pair<int, int> p1, pair<int, int> p2) {

    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    if (p1.first > p2.first) return true;
    return false;
}


void learnAlgos() {
    pair<int, int> p[] = {{1, 7}, {1, 2}, {4, 2}};
    cout << "unsorted order pairs: " << endl;
    for (auto it : p) {
        cout << it.first << ": " << it.second << ", ";
    }
    cout << endl;

    sort(p, p + sizeof(p) / sizeof(p[0]), comp);

    cout << "sorted order pairs: " << endl;
    for (auto it : p) {
        cout << it.first << ": " << it.second << ", ";
    }
    cout << endl;    
}


int main()
{
    // cout << "Hello world!" << endl;
    //learnMap();   

    learnAlgos();


    return 0;
}