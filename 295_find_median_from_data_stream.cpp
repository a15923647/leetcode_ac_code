#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {}
    void addNum(int num) {
      //decide which side to push
      //keep the relationship that max_heap.top() <= min_heap.top()
      if (max_heap.empty() || num <= max_heap.top())
        max_heap.push(num);
      else
        min_heap.push(num);
      //keep the boundary in the median place
      if (max_heap.size() > min_heap.size() + 1) {
        //move elements from max_heap to min_heap
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
      if (min_heap.size() > max_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      } 
    }
    double findMedian() {
      if (max_heap.size() > min_heap.size())
        return max_heap.top();
      return (max_heap.empty()) ? 0 : (max_heap.top()+min_heap.top()) / 2;
    }
    priority_queue<double> max_heap; //left half
    priority_queue<double, vector<double>, greater<double>> min_heap; //right half
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */