#include<iostream>
#include<string>
using namespace std;
int main() {
    int noOfTests;
    cin >> noOfTests;
    string r;
    for (int i = 1; i <= noOfTests;i++) {
        long int printers[4];
        long int min;
        long int sum;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == 0) {
                    cin >> printers[k];
                }
                else {
                    cin >> min;
                    printers[k] = min < printers[k] ? min : printers[k];
                }
            }
        }
        sum = printers[0] + printers[1] + printers[2] + printers[3];
        if (sum == 1000000) {
            r = to_string(printers[0]) + " " + to_string(printers[1]) + " " + to_string(printers[2]) + " " + to_string(printers[3]);
        }
        else if (sum > 1000000) {
            long int temp = sum - 1000000;
            for (int i = 0;i < 4;i++) {
                if (temp == 0) {
                    break;
                }
                else if (temp - printers[i] >= 0) {
                    temp = temp - printers[i];
                    printers[i] = 0;
                }
                else {
                    printers[i] = printers[i] - temp;
                    temp = 0;
                }
            }
            r = to_string(printers[0]) + " " + to_string(printers[1]) + " " + to_string(printers[2]) + " " + to_string(printers[3]);

        }
        /*long int temp = printers[0]+printers[1]+printers[2];
        temp = 1000000 - temp;
        if(temp>=0){
            if(temp < printers[3]){
                printers[3] = temp;
                r = to_string(printers[0])+" "+to_string(printers[1])+" "+to_string(printers[2])+" "+to_string(printers[3]);
            }
            else{
                r = "IMPOSSIBLE";
            }
        }
        else{
            int x = 3;
            while(temp<0){
                if(printers[x]>(-1*(temp))){
                    printers[x] += temp;
                    temp = 0;
                }
                else{
                    temp-=printers[x];
                    printers[x]=0;
                }
                x--;
            }
            sum=printers[0]+printers[1]+printers[2]+printers[3];
            if(sum==1000000){
                r = to_string(printers[0])+" "+to_string(printers[1])+" "+to_string(printers[2])+" "+to_string(printers[3]);
            }
            else{
                r = "IMPOSSIBLE";
            }
        }*/

        else {
            r = "IMPOSSIBLE";
        }
        cout << "Case #" << i << ": ";
        cout << r << endl;
    }

}
