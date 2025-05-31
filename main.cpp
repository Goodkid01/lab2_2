#include <iostream>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cmath>
#include <thread>
#include <algorithm>
#include <fstream>
#define N 100
#define M 100
//
//void QuickSort(int a, int b, int* arr) 
//    {
 //   if(a>=b)
 //       return;
    // Выбор опорного элемента
 //   int k = (rand()*rand()) % (b-a+1) + a;
 //   int m = arr[k];
    // Пресорт
  //  int l = a - 1;
 //   int r = b + 1;
 //   while(true) {
 //       do l++; while(arr[l] < m);
  //      do r--; while(arr[r] > m);
  //      if(l >= r) 
  //          break;
  //      std::swap(arr[l], arr[r]);
 //   }
 //   l = r;
 //   r++;
 //   QuickSort(a, l, arr);
 //   QuickSort(r, b, arr);
//}
///int main()    
//{   
 //   const int n =100000;
 //   int arr[n]={2,3,4,546,9,1};
//
  //  QuickSort(0,n-1,arr);
//
//for(int i=0;i<n;i++)
 //   {
      //  std::cout<<arr[i]<<" ";
 //   std::cout<< std::endl;
  //  }

//}
   




/*
int countDigits(int n) {
    
    if (n < 10) {
        return 1;
    }
    
    return 1 + countDigits(n / 10);
}

int main() {
    int N;
    
    std::cin >> N;

    if (N <= 0) {
        
        return 1;
    }

    int digits = countDigits(N);
    std::cout<< digits << std::endl;

    return 0;
}
*/ 
 int n, m;
char field[N][M];
int steps[N][M];

void Search(int i, int j, int step) {
    if(steps[i][j] <= step)
        return;
    steps[i][j] = step;

    if(field[i][j] == 'E') 
        return;

    if(i+1 < N && field[i+1][j] != '#')
        Search(i+1, j, step + 1);
    if(i-1 >= 0 && field[i-1][j] != '#')
        Search(i-1, j, step + 1);
    if(j+1 < M && field[i][j+1] != '#')
        Search(i, j+1, step + 1);
    if(j-1 < N && field[i][j-1] != '#')
        Search(i, j-1, step + 1);
    if(i+1 < n && j+1 < m && field[i+1][j+1] != '#')   
        Search(i+1, j+1, step + 1);
    if(i+1 < n && j-1 >= 0 && field[i+1][j-1] != '#')  
        Search(i+1, j-1, step + 1);
    if(i-1 >= 0 && j+1 < m && field[i-1][j+1] != '#')  
        Search(i-1, j+1, step + 1);
    if(i-1 >= 0 && j-1 >= 0 && field[i-1][j-1] != '#')  
        Search(i-1, j-1, step + 1);
}

int main() {
    int si, sj, ei, ej;
    std::ifstream in("input.txt");
    in >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            in >> field[i][j];
            steps[i][j] = INT_MAX;
            if(field[i][j] == 'S') {
                si = i;
                sj = j;
            } else if(field[i][j] == 'E') {
                ei = i;
                ej = j;
            }
        }
    Search(si, sj, 0);
    std::cout << steps[ei][ej];

}