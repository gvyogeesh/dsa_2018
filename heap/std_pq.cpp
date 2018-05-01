/* Demonstration of standard priority_queue operations */
struct min_compare{
    bool operator()(int x, int y){
        return x > y;
    }
};

struct max_compare{
    bool operator()(int x, int y){
        return x < y;
    }
};

int main(){
    int arr[] = {4, 3, 2, 6};
    int mcost;
    mcost = mincost(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "Min Cost to connect ropes are " << mcost << endl;

    // priority_queue<int, vector<int>, less<int> > p;
    priority_queue<int, vector<int>,greater<int> > min_heap;
    priority_queue<int, vector<int>,less<int> > max_heap;

    max_heap.push(100);
    max_heap.push(10);
    max_heap.push(110);
    max_heap.push(1000);
    cout << max_heap.top() << endl;
    max_heap.pop();
    cout << max_heap.top() << endl;
    max_heap.pop();
    cout << max_heap.top() << endl;

    cout << "Min heap demo" << endl;
    min_heap.push(100);
    min_heap.push(10);
    min_heap.push(110);
    min_heap.push(1000);
    cout << min_heap.top() << endl;
    min_heap.pop();
    cout << min_heap.top() << endl;
    min_heap.pop();
    cout << min_heap.top() << endl;


    // p.push(100);
    // p.push(200);
    // p.push(45);
    // cout << p.top() << endl;
    return 0;
}
