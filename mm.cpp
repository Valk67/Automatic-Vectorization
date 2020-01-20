#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void rndom();
void UserInput();

// void printer (float array[][], int n);


int main () {
    char flag;

    cin >> flag;

    if (flag == 'I') {
      UserInput();
    } 

    if (flag == 'R') { 
       rndom();   
    }
    return 0;

}

void UserInput() {
    int n = 0;
    float input = 0;
    cin >> n;
    float **A = new float*[n];
    float **B = new float*[n];
    float **S = new float*[n];
    for (int i = 0; i < n; i++) {
      A[i] = new float[n];
      B[i] = new float[n];
      S[i] = new float[n];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        S[i][j] = 0;
      }
    }


    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> input;
        A[i][j] = input;
      }
    }
    // cout << "printing A" << endl;
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //        cout << A[i][j] << " ";
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> input;
        B[i][j] = input;
      }
    }
    // cout << "printing b" << endl;
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //        cout << B[i][j] << " ";
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';
    clock_t time_req;

    float r = 0;
    time_req = clock();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        r = A[j][i];
        for (int u = 0; u < n; ++u) {

          S[j][u] += r * B[i][u];
        }
      }
    }
    time_req = clock() - time_req;
    cout << (float)time_req/CLOCKS_PER_SEC << endl;

    
   
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
           cout << S[i][j] << " ";
      }
      cout << '\n';
    }
    cout << '\n';

    // clean up 
    for (int i = n; i < n; i++ ) {
      delete[] A[i];
      delete[] B[i];
      delete[] S[i];
    }
     delete[] A;
     delete[] B;
     delete[] S;
}



void rndom() {
    int n = 0;
    cin >> n;
  
    float **array = new float*[n];
    float **array2 = new float*[n];
    float **S = new float*[n];
    for (int i = 0; i < n; i++) {
      array[i] = new float[n];
      array2[i] = new float[n];
      S[i] = new float[n];
    }
    
    float LO = -50.0;
    float HI = 50.0;
    srand (time(NULL));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        S[i][j] = 0;
      }
    }
    float divisor3 = 1 / ( static_cast <float> (RAND_MAX/(HI-LO)));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
           array[i][j] = LO + static_cast <float> (rand()) *divisor3;
      }
    }


    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
           array2[i][j] = LO + static_cast <float> (rand()) * divisor3;
               ///( static_cast <float> (RAND_MAX/(HI-LO)));
      }
    }

    clock_t time_req;

    float r = 0;
    time_req = clock();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        r = array[j][i];
        for (int u = 0; u < n; ++u) {

          S[j][u] += r * array2[i][u];
        }
      }
      //cout << " i = " << i << endl;
    }

    time_req = clock() - time_req;
    cout << (float)time_req/CLOCKS_PER_SEC << endl;
    

    // printer for first random array used for testing
    /*for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
           cout << array[i][j] << " ";
      }
      cout << '\n';
    }
    cout << '\n';
    */
    
    // clean up 
    for (int i = n; i < n; ++i ) {
      delete[] array[i];
      delete[] array2[i];
      delete[] S[i];
    }
     delete[] array;
     delete[] array2;
     delete[] S;
}

