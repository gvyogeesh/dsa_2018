/*
Suppose there is a circle. There are  petrol pumps on that circle. Petrol pumps are numbered  to  (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each litre of the petrol.
*/




#include <iostream>
using namespace std;

struct petrol_bunk{
    int fuel;
    int dist;
};

int find_starting_point(struct  petrol_bunk p[], int size){
    for(int i=0;i<=size;i++){
        int count = 0;
        int rem_dist = 0;
        for(int j=i;j<size+i;j++){
            rem_dist =  rem_dist + p[j%size].fuel - p[j%size].dist;
            if(rem_dist < 0)
              break;
            count++;
            if(count == size)
                return i;
        }
    }
    return -1;
}
int main()
{

    struct petrol_bunk p1[3];
    p1[0].fuel = 10;
    p1[0].dist = 11;

    p1[1].fuel = 2;
    p1[1].dist = 1;

    p1[2].fuel = 1;
    p1[2].dist = 1;

    int result;
    result = find_starting_point(p1, 3);
    cout << "Starting point is  " << result << endl;

   return 0;

}
