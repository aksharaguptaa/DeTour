//zoom size 150
#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

int tsp(vector<vector<int>>& graph, int start, int mask, vector<vector<int>>& dp, vector<vector<int>>& next) {
    int n = graph.size();
    if (mask == (1 << n) - 1) {
        return graph[start][0];
    }
    if (dp[start][mask] != -1) {
        return dp[start][mask];
    }
    int ans = INF;
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            int newMask = mask | (1 << i);
            int newAns = graph[start][i] + tsp(graph, i, newMask, dp, next);
            if (newAns < ans) {
                ans = newAns;
                idx = i;
            }
        }
    }
    next[start][mask] = idx;
    return dp[start][mask] = ans;
}
void printPath(vector<vector<int>>& next) {
    int start = 0;
    int mask = 1;
    int n = next.size() - 1;

    cout << "\t\tPath = ";
    while (true) {
        int nextCity = next[start][mask];
        cout << start << " -> ";
        if (nextCity == -1) {
            break;
        }
        mask |= (1 << nextCity);
        start = nextCity;
    }

    cout << "0" << endl;  
}
void solveTSP(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    vector<vector<int>> next(n, vector<int>(1 << n, -1));
    int minCost = tsp(graph, 0, 1, dp, next);
    cout <<"\t\tDistance = " << minCost <<" Km"<< endl;
    cout<<"\t\tPetrol consumption = "<<(float)minCost*0.075<<" L"<<endl;
    cout<<"\t\tPetrol cost = "<<(float)minCost*0.075*102<<" Rs"<<endl;
    printPath(next);
}
    
    
int main(){
    string yesno;
    int n;
    
    
    cout<<"\n\n________________________________________________________________________________________________________________\n";
    cout<<endl<<endl<<"\t\t\t\t\t   WELCOME TO DeTour !"<<endl<<endl;
    cout<<"\t\t\t\t   A portal to design your shortest tour\n"<<endl;
    cout<<"________________________________________________________________________________________________________________";
    
    
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    cout<<endl<<endl<<"\t\t\t\t\t\t\t\t\t\t\t"<<asctime(ptr)<<endl<<endl;
    
    
    cout<<"Do you wish to proceed further?"<<endl;
    cout<<"-> ";
    cin>>yesno;
    
    
    if(yesno=="Yes" || yesno=="YES" || yesno=="yes"){
        cout<<"\n\n\n";
    
    
    ifstream file1;
        file1.open("state.txt");
        if(file1.is_open()){
            char mychar;
            while(file1){
                mychar=file1.get();
                cout<<mychar;
            }
        }
        
        
        cout<<"\n\n\nEnter no. of cities you want to travel : ";
        cin>>n;
        
        
        int arr[n];
        
        
        cout<<"\n\nEnter cities by their coordinates (Note: First enter the city from which you want to start your journey)\n";
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
       cout<<"\n\n=> Cities and Distances between them\n"; 
       
       
     vector<vector<int>> graph(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j)
            graph[i][j]=0;
            else
            graph[i][j]=rand() % 100 + 1;
        }}
        
        cout<<"\n";
        for(int i=0; i<n; i++)
                cout<<arr[i]<<"\t";
            cout<<"\n\n";
        
        
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i<=j)
            cout<<graph[i][j]<<"\t";
        }
        cout<<"\n";
        }
        
        cout<<"\n\n";
        cout<<"=> City's coordinates & Ids\n\n";
        for(int i=0; i<n; i++)
        cout<<arr[i]<<" -> "<<i<<endl;
        
        cout<<"\n\n";
        
       cout<<"**************************************************************\n\n\t\t\tTOUR DETAILS\n\n**************************************************************\n\n";
       cout<<"\t  "<<"Generated on: "<<asctime(ptr)<<endl;
       
        
        
    solveTSP(graph);
      cout<<"\n**************************************************************\n";
        
    cout<<"\n\n________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\tThankyou for visiting, Enjoy Right :)";
    
    }
    else{
        cout<<"_____________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\tNo problem, thankyou for visiting, See you again :)";
    }
    
    
    return 0;
}