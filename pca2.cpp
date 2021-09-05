#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,p;
    cin>>m>>n>>p; //ask size of matricies by user 
//Use RCV(Row,Column,Value) METHOD for Matrices A,B&C
    vector<int>RA; //for rows of matrix A
    vector<int>CA; //for colomns of matrix A
    vector<int>VA; //for values of matrix A
    vector<int>RB; //for rows of matrix B
    vector<int>CB; //for colomns of matrix B
    vector<int>VB; //for values of matrix B
    vector<int>RC; //for rows of matrix C
    vector<int>CC; //for colomns of matrix C
    vector<int>VC; //for values of matrix C
//Initialize vectors for transpose of the matrix BT
    vector<int>CBT; //for colomns of transpose of the matrix B
    vector<int>RBT; //for rows of transpose of the matrix B
    vector<int>VBT; //for values of transpose of the matrix B

    srand(time(0));
    float spA,spB;

    clock_t start, end; //syntax
    
    
//calculate the time of sparsity of matrix multiplication
    start = clock(); //start calculating time from here

//Processing for Matrix A
    //randomly generating sparsity for matrix A
    spA = 1+rand()%100;
    
    cout<<"\nsparsity of spA: "<<spA<<"%"<<endl;
    
    int ra,ca;//row & col for matrix A
    //how many entries we want to fill non zero accordng to sparsity
    int ssa = ceil(m*n*(spA)/100); //How many entries to fill non zero's for matrix A
    cout<<"size of ssa: "<<ssa<<endl;
    //find & store values at randome position of matrix 
    for(int i=1;i<=ssa;i++){
        ra = rand()%m; //generate random positin between 0 to m-1
        ca = rand()%n; //generate random positin between 0 to n-1
        //cout<<"ra: "<<ra<<" ca "<<ca<<endl;
        RA.push_back(ra);
        CA.push_back(ca);
        VA.push_back(rand()%20);
    }
//let's display the sparsity matrix A
    cout<<"\nRow index of matrix A: \n";
    for(int i=0;i<RA.size();i++){
        cout<<RA[i]<<" ";
    }
    cout<<"\nColomn index of matrix A: \n";
    for(int i=0;i<CA.size();i++){
        cout<<CA[i]<<" ";
    }
    cout<<"\nValue of matrix A: \n";
    for(int i=0;i<VA.size();i++){
        cout<<VA[i]<<" ";
    }
    cout<<endl;

//Processing for Matrix B
    //use sparsity for matrix B
    spB = 1+rand()%100;
    
    cout<<"\nsparsity of spB: "<<spB<<"%"<<endl;
    
    int rb,cb;//row & col for matrix B
    //how many entries we want to fill non zero accordng to sparsity 
    int ssb = ceil(n*p*(spB)/100); 
    cout<<"size of ssb: "<<ssb<<endl;
    //find & store values at randome position of matrix 
    for(int i=1;i<=ssb;i++){
        rb = rand()%n; //generate random positin between 0 to n-1
        cb = rand()%p; //generate random positin between 0 to p-1
        RB.push_back(rb);
        CB.push_back(cb);
        VB.push_back(rand()%20);
    }
//let's display the sparsity matrix B 
    cout<<"\nRow index of matrix B: "<<endl;
    for(int i=0;i<RB.size();i++){
        cout<<RB[i]<<" ";
    }
    cout<<"\nColomn index of matrix B: "<<endl;
    for(int i=0;i<CB.size();i++){
        cout<<CB[i]<<" ";
    }
    cout<<"\nValue of matrix B: "<<endl;
    for(int i=0;i<VB.size();i++){
        cout<<VB[i]<<" ";
    }

//Processing of Transpose of the matrix B
    cout<<endl;
    cout<<"\ntranspose of matrix B"<<endl;
    for(int j=0;j<p;j++){
        for(int i=0;i<CB.size();i++){
            if(CB[i]==j){
                RBT.push_back(CB[i]);
                CBT.push_back(RB[i]);
                VBT.push_back(VB[i]);
            }
        }
    }
//let's display the transpose of matrix B  
    cout<<"\nrow of transpose of the matrix B"<<endl;
    for(int i=0;i<RBT.size();i++){
        cout<<RBT[i]<<" ";
    }
    cout<<"\ncolumn of transpose of the matrix B"<<endl;
    for(int i=0;i<CBT.size();i++){
        cout<<CBT[i]<<" ";
    }
    cout<<"\nvalue of transpose of the matrix B"<<endl;
    for(int i=0;i<VBT.size();i++){
        cout<<VBT[i]<<" ";
    }
//let's multiply both sparse matrices A and B, ans store the value in resultant matrix C
    for(int i=0;i<CA.size();i++){
        for(int j=0;j<CBT.size();j++){
            if(CA[i]==CBT[j]){
                RC.push_back(RA[i]);
                CC.push_back(RBT[j]);
                VC.push_back(VA[i]*VBT[j]);
            }
        }
    }
end = clock(); //stop the execution of time

//Display the resultant matrix C
cout<<endl;
cout<<"\nresultant matrix C\n";
    cout<<"\nrow of Resultant matrix C: \n";
    for(int i=0;i<RC.size();i++){
        cout<<RC[i]<<" ";
    }
    cout<<"\ncolumn of Resultant matrix C: \n";
    for(int i=0;i<CC.size();i++){
        cout<<CC[i]<<" ";
    }
    cout<<"\nvalue of Resultant matrix C: \n";
    for(int i=0;i<VC.size();i++){
        cout<<VC[i]<<" ";
    }
    cout<<endl;
// Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}