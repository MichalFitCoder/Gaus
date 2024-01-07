#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<double> podstawienie(vector <double> wezly, vector <double> wartosci, int wybor);
void kwadraty(vector<double> wezly, vector <double> wartosci, int l_wezlow, int wybor);
int main(){
    int n, wybor;
    double rob;
    vector<double> x;
    vector<double> y;
    cout << "jaka funkcja chcesz aproksymowac?" << endl<< "1. a*x + b" << endl << "2. a*1/x + b" << endl << "3. a^x + b" << endl << "wybor: ";
    cin >> wybor;
    cout << "podaj liczbe wezlow: ";
    cin >> n;

    
    for(int i = 0; i < n; i++){
        cout << "podaj x[" << i << "]: ";
        cin >> rob;
        x.push_back(rob);
    }

    if(wybor == 3) cout << "PODAWAJ WYKLADNIKI LICZBY e "<< endl;

    for(int i = 0; i < n; i++){
        cout << "podaj y[" << i << "]: ";
        cin >> rob;
        y.push_back(rob);
    }

    if(wybor == 2) kwadraty(podstawienie(x, y,wybor), y, n, wybor);
    else kwadraty(x, y, n, wybor);

    return 0;
}

vector<double> podstawienie(vector<double> wezly, vector<double> wartosci, int wybor){
        
    for(int i = 0; i < wezly.size(); i++){
        wezly[i] *= pow((1/wezly[i]), 2);
    }
    return wezly;
}

void kwadraty(vector<double> wezly, vector<double> wartosci, int l_wezlow, int wybor){

double a0, a1;
double W, Wa0, Wa1;
vector<double> ur(6); // UKLAD ROWNAN

ur[0] = l_wezlow;

for(int i = 0; i < l_wezlow; i++){
    ur[1] += wezly[i];
    ur[2] += wartosci[i];
    ur[4] += pow(wezly[i], 2);
    ur[5] += wezly[i]*wartosci[i];
}

ur [3] = ur[1];

W = ur[0]*ur[4] - ur[1]*ur[3];
Wa0 = ur[2]*ur[4] - ur[1]*ur[5];
Wa1 = ur[0]*ur[5] - ur[2]*ur[3];

a0 = Wa0/W;
a1 = Wa1/W;

cout << "funkcja aproksymacyjna ma postac: ";

if(wybor == 1) cout << "g(x) = " << a1 << "x + " << a0;
else if(wybor == 2) cout << "g(x) = " << a1 <<"*1/x + " << a0;
else cout << "g(x) = e^" << a1 << "x + e^" << a0;


//NIEPEWNOSCI TYPU A I B:
double ua, ub;

double y2;
for(int i = 0; i < wezly.size();i++){
    y2 += pow(wartosci[i], 2);
}

ua = sqrt((wezly.size()/(wezly.size()-2))*((y2 - a1*ur[5] - a0*ur[2])/(wezly.size()*ur[4] - pow(ur[1], 2))));
ub = ua - sqrt(ur[4]/wezly.size());

cout << "niepewnosc typu a wynosi: " << ua << endl;
cout << "niepewnosc typu b wynosi: " << ub << endl;

}